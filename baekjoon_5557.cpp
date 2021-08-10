#include <iostream>

using namespace std;

// 백준 5557 - 1학년
// DP -> 점화식 먼저 세우기
// 1. n-1번 수 +/- n번 수가 0~20 사이인가?
// 2. 사이라면 n번째 배열(arr[n])에서 (n-1) +/- (n) 번째 배열에 값을 더한다
// 0 ~ 20 인덱스를 가진 1차원 배열이 n개(최대 100)만큼 있는 2차원 배열을 생성 arr[n][21]
// long long 변수형 사용 (2^63-1 -> 수가 크므로)


int main()
{
	long long arr[101][22]{ 0 }; // 배열 0으로 초기화

	int n, tmp, res_plus, res_minus;
	cin >> n >> tmp;

	arr[0][tmp]++; // 계산하는 수는 도중에 음수일 수 없으므로 첫번째 등식의 수는 무조건 +부호만을 가진다


	for (int i = 1; i < n-1; i++)
	{
		cin >> tmp;
		for (int j = 0; j <= 20; j++)
		{
			if (arr[i - 1][j] != 0) // n-1번째 등식에서 값이 존재한다면
			{
				res_plus = j + tmp; // n번째 수를 더한 수
				res_minus = j - tmp; // n번째 수를 뺀 수
				if (res_plus >= 0 && res_plus <= 20) arr[i][res_plus] += arr[i-1][j]; // 1. 0~20 사이에 있는지 확인 2. n-1번째 등식의 개수를 n번째 등식의 개수에 더함
				if (res_minus >= 0 && res_minus <= 20) arr[i][res_minus] += arr[i-1][j];
			}
		}
	}
	cin >> tmp; // 마지막 답이 되는 수 입력
	cout << arr[n - 2][tmp] << endl; // 결과 출력

	return 0;
}