#include <iostream>

using namespace std;

// 백준 2491 - 수열
// DP - 점화식
// 연속해서 커지거나 같은 것
// 연속해서 작아지거나 같은 것 두개 구하고
// 더 길이 긴 것 출력

int arr[100001]{ 0 }; // 크기 큰 배열은 main 함수 내에 선언 시 stack overflow 발생
int big_arr[100001]{ 0 }; // 힙 영역 이용하거나 전역 변수로 선언
int small_arr[100001]{ 0 };

int main()
{
	int n;
	cin >> n;

	//int arr[100001]{ 0 };
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// 연속해서 커지거나 같은 것
	// 연속해서 작아지거나 같은 것 두개 구하고
	// 더 길이 긴 것 출력
	//int big_arr[100001]{ 0 };
	//int small_arr[100001]{ 0 }; **용량 큰 배열 main함수 내에 선언하면 안 됨, 전역 변수로 선언해주자
	
	int big_cnt = 0;
	int small_cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] <= arr[i]) big_arr[big_cnt]++;
		else big_cnt++;		
		if (arr[i - 1] >= arr[i]) small_arr[small_cnt]++;
		else small_cnt++;
	}
	// big_arr 중 가장 큰 수 찾음
	int big_max = big_arr[0];
	for (int i = 1; i <= big_cnt; i++)
	{
		if (big_max < big_arr[i]) big_max = big_arr[i];
	}
	// small_arr 중 가장 큰 수 찾음
	int small_max = small_arr[0];
	for (int i = 1; i <= small_cnt; i++)
	{
		if (small_max < small_arr[i]) small_max = small_arr[i];
	}
	// 큰 것 출력
	int max = (big_max > small_max ? big_max : small_max);
	cout << ++max << endl;

	return 0;
}