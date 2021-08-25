#include <iostream>
#include <vector>
using namespace std;

// 백준 1967번 - 트리의 지름
// 트리, DFS
// 리프부터 올라오면서 자신의 노드로부터 여러가지 아래로 뻗어나가는 경로 중에
// 상위 두개(가중치 높은)를 더해서 route_max와 비교한다
// 경로는 무조건 끝이 리프 노드
// DFS 함수는 가중치 최상위 경로에 간선 가중치 더한 값 리턴 (자신의 노드를 거치는 경로 중에 최댓값 리턴)

struct node
{
	node *parent = NULL;
	vector<int> child; // 자식의 인덱스 번호
};
struct edge // edge_arr 배열의 인덱스 : 자식 노드 번호
{
	int value = 0;
	int parent = -1; // tree 배열의 인덱스 번호 (노드 번호)
};

// 올라오면서 가장 큰 경로값 리턴
int DFS(int idx);
int route_max = 0;

node tree[10001]; // 루트 : tree[1]
edge edge_arr[10001]; // 간선 정보 담은 배열

int main()
{
	int n, p, c, v;
	cin >> n;
	for (int i = 1; i < n; i++) // 트리 생성
	{
		cin >> p >> c >> v;
		tree[p].child.push_back(c);
		tree[c].parent = &tree[p];
		edge_arr[c].parent = p;
		edge_arr[c].value = v;		
	}
	DFS(1);
	cout << route_max << '\n';
	return 0;
}

// 리프 찍고 올라오면서 계산
// 리프까지의 경로 중에 가장 큰 것과 두번째로 큰 것 계산
// 경로 최댓값 계산

int DFS(int idx) // 가중치 비교 후 가장 큰 값(다른쪽 리프부터 현재 지점까지의 값)두개
{
	int max1 = 0; // 가중치 가장 큰 경로 값(다른 리프로부터 자신까지)
	int sec_max1 = 0; // 두번째로 큰 경로 값
	if (tree[idx].child.size() == 0) // 리프 노드라면
	{
		return edge_arr[idx].value;	// 간선 정보만 리턴	
	}	
	else
	{
		for (int i = 0; i < tree[idx].child.size(); i++)
		{
			int a = DFS(tree[idx].child[i]); // 경로값 비교
			if (a > max1)
			{			
				sec_max1 = max1;
				max1 = a;
			}
			else if (a > sec_max1) sec_max1 = a;
			
		}
	}
	int tmp = max1 + sec_max1;
	if (tmp > route_max) route_max = tmp; // route_max와 비교
	return max1 + edge_arr[idx].value;
}