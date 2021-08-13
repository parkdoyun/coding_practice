#include <iostream>

using namespace std;

// 백준 15552번 - 빠른 A+B
// C++에서 cin, cout 시간 많이 잡아먹는다
// 1. C 사용
// 2. 개행문자 \n 사용 & line 17 ~ 19 넣기
// 입출력 테스트

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		cout << a + b << '\n';
	}

	return 0;
}