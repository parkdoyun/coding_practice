#include <iostream>
#include <string>
#include <map>

using namespace std;

// 백준 1620번 - 나는야 포켓몬 마스터 이다솜
// C++에서 cin, cout 시간 많이 잡아먹는다 -> 백준 15552번 빠른 A+B 참고
// 1. C 사용
// 2. 개행문자 \n 사용 & line 17 ~ 19 넣기
// 맵 구조

string list1[100001];

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int>list;
	string s;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;

		list.insert(make_pair(s, i)); // name, num (pair)
		list1[i] = s;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (s[0] >= 'A' && s[0] <= 'Z') // list search
		{
			cout << list.find(s)->second << '\n'; // first : key, second -> value
		}
		else // list1 search
		{
			cout << list1[stoi(s)] << '\n'; // endl이 생각보다 시간 많이 잡아먹음
		}
	}
	return 0;
}