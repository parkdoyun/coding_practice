#include <iostream>
#include <vector>
using namespace std;

// 백준 11725번 - 트리의 부모 찾기
// DFS, 트리

// 연결끼리 붙여놓고 나중에 (DFS, BFS) 탐색

vector<vector<int>> tree(100001); // 트리(양끝 연결 정보 모두 저장)
int parent_arr[100001]{ 0 }; // 부모 정보 입력할 배열

void DFS(int tmp, int parent);

int main()
{
	int n, a, b;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	// 탐색으로 부모 찾기
	DFS(1, 0);
	
	for (int i = 2; i <= n; i++)
	{
		cout << parent_arr[i] << '\n';
	}
	return 0;
}

void DFS(int tmp, int parent)
{
	for (int i = 0; i < tree[tmp].size(); i++)
	{
		if (tree[tmp][i] == parent) continue;
		else
		{
			parent_arr[tree[tmp][i]] = tmp;
			DFS(tree[tmp][i], tmp);
		}
	}
}