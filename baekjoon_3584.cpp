#include <iostream>
using namespace std;

// 백준 3584 - 가장 가까운 공통 조상
// 트리 (이진 X)

struct node
{
	int value;
	node *parent = NULL;
};

int main()
{
	int t, n, a, b, node1, node2;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		struct node tree[10001];
		int node1_route[10001]{ 0 }; // 루트까지의 경로 넣는 배열
		int node2_route[10001]{ 0 };
		cin >> n;
		for (int j = 0; j < n - 1; j++)
		{
			cin >> a >> b;
			tree[b].parent = &tree[a];
			tree[b].value = b;
			tree[a].value = a; // 이렇게 안 하면 루트에 값 안 들어감
		}
		cin >> node1 >> node2;
		// 루트까지의 경로 기록
		int node1_route_len = 0; // 배열에서 0은 참조 안 함.
		int node2_route_len = 0; 
		node1_route[0] = -1; // 비교값 넣음
		node2_route[0] = -2;
		node *tmp = &tree[node1];
		while (tmp != NULL) // 루트까지
		{
			node1_route[++node1_route_len] = tmp->value;
			tmp = tmp->parent;
		}
		tmp = &tree[node2];
		while (tmp != NULL)
		{
			node2_route[++node2_route_len] = tmp->value;
			tmp = tmp->parent;
		}
		// 두 경로에서 공통점 찾기
		while (node1_route_len != 0 && node2_route_len != 0)
		{			
			if ((node1_route[node1_route_len] == node2_route[node2_route_len]) && 
				(node1_route[node1_route_len-1] != node2_route[node2_route_len-1]))
			{
				cout << node1_route[node1_route_len] << '\n';
				break;
			}				
			node1_route_len--;
			node2_route_len--;
		}
	}
	return 0;
}