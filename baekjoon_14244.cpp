#include <iostream>
using namespace std;

// 백준 14244번 - 트리 만들기
// 마지막 부분 노드들로 개수 맞추기
// 트리, 구성적

int main()
{
	int n, m, a, b;
	cin >> n >> m;
	cout << "0 1\n";
	a = 1;
	b = 2;

	for (int i = 2; i <= n - 1; i++)
	{
		cout << a << ' ' << i << '\n';
		if (n - 1 - i > (m-2))
		{
			a = i;
		}
	}
	return 0;
}