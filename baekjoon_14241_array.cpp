#include <iostream>

using namespace std;

// 백준 14241번 - 슬라임 합치기
// 배열 이용

int main()
{
	int n;
	cin >> n;
	int arr[101]{ 0 };
	int tmp;
	
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		arr[tmp]++;
	}

	// 점수 계산 -> 제일 작은 슬라임부터 계산
	int slime_count = 0; // 몇개의 슬라임 꺼냈는지
	int score = 0; // 점수
	int slime_size = 0; // 합친 슬라임 크기
	for (int i = 1; i <= 100; i++)
	{
		while (arr[i] != 0)
		{
			if (slime_count == 0) slime_size = i;
			else
			{
				score += slime_size * i;
				slime_size += i;
			}
			arr[i]--;
			slime_count++;
		}		
	}
	cout << score << endl; // 점수 출력
	return 0;
}