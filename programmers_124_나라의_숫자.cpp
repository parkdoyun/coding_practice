#include <iostream>
#include <string>
#include <vector>
#include <math.h>

// 프로그래머스 level 2 - 124 나라의 숫자

using namespace std;

int main()
{
	string answer = "";
	int n = 9;
	

	// 3의 몇제곱 사이에 있는지 (자릿수) 확인
	int position_cnt = 0; // 제곱 수(자릿수)
	long int sum = 0;
	for (int i = 1; sum <= 500000000; i++)
	{
		if (n >= sum && n <= sum + pow(3, i))
		{
			position_cnt = i;
			break;
		}
		sum += pow(3, i);
	}

	int tmp = n;
	tmp = tmp - sum - 1;
	// 그 후 3의 몇 배수 뒤에 있는지
	// 첫째 자리 수 -> 3^(position_cnt-1)로 구분
	// 둘째 자리 수 -> 3^(position_cnt-2)
	// ...
	int position = 0;
	int a;
	for (int i = position_cnt - 1; i >= 0; i--)
	{
		a = pow(3, i);
		position = tmp / a;
		if (position == 0) answer += "1";
		else if (position == 1) answer += "2";
		else answer += "4";
		tmp = tmp % a;
	}

	cout << answer << endl;
	return 0;
}