#include <iostream>

using namespace std;

// 백준 1003 - 피보나치
// DP
// 점화식 : f(n) = f(n-1) + f(n-2)
// (0,1) 구조체로 계산
// 0과 1로부터 큰 수로 점점 0,1 개수를 덧셈

struct fibo // 피보나치 구조체
{
	int zero;
	int one;
};

int main()
{
	int t, tmp;
	cin >> t;
	struct fibo arr[41];
	arr[0].zero = 1; arr[0].one = 0; // 0은 0이 1개고 1이 0개
	arr[1].zero = 0; arr[1].one = 1; // 1은 0이 0개고 1이 1개

	for (int i = 0; i < t; i++)
	{
		cin >> tmp; // 수 입력 받음
		for (int j = 2; j <= tmp; j++) // 입력받은 수까지
		{// f(tmp) = f(tmp-1) + f(tmp-2)
			arr[j].zero = arr[j - 1].zero + arr[j - 2].zero; // (tmp의 0의 개수) = (tmp-1의 0의 개수) + tmp-2의 0의 개수)
			arr[j].one = arr[j - 1].one + arr[j - 2].one; // (tmp의 1의 개수) = (tmp-1의 1의 개수) + tmp-2의 1의 개수)
		}
		cout << arr[tmp].zero << ' ' << arr[tmp].one << endl; // 출력
	}

	return 0;
}