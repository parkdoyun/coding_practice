#include <iostream>
#include <vector>
using namespace std;

// 백준 9489번 - 사촌
// 트리

struct node
{
	int value = -1;
	node *parent = NULL;
	vector<node*> child;
};

int main()
{
	int n, k;
	while (true)
	{
		cin >> n >> k;
		if (n == 0 && k == 0) break;
		node input[1000]{0};
		for (int i = 0; i < n; i++)
		{
			cin >> input[i].value;
		}
		node *root = &input[0];
		
		int start_idx, tmp_idx, next_idx;
		int prev_parent_idx = 0; // 연결 가능한 부모 노드
		
		node *k_node;
		start_idx = 1; // 채워져야 하는 인덱스(자식들)의 시작점
		for (int i = 1; i < n; i++)
		{
			tmp_idx = i; // 현재 보고 있는 노드
			next_idx = i + 1; // 현재 노드의 다음 노드
			if (next_idx != n)
			{
				if (input[next_idx].value != input[tmp_idx].value + 1) // 다음 노드가 연속되지 않는다면
				{
					for (int j = start_idx; j <= tmp_idx; j++)
					{
						input[j].parent = &input[prev_parent_idx];
						input[prev_parent_idx].child.push_back(&input[j]); // 자식에 추가						
					}
					prev_parent_idx++;
					start_idx = tmp_idx + 1;
				}
			}
			else // tmp_idx가 맨 마지막일때
			{
				for (int j = start_idx; j <= tmp_idx; j++)
				{
					input[j].parent = &input[prev_parent_idx];
					input[prev_parent_idx].child.push_back(&input[j]); // 자식에 추가
				}
			}
			if (input[i].value == k) k_node = &input[i];
		}
		// 사촌 출력 (부모가 루트, 내가 루트일 때는 제외)
		node *k_parent = k_node->parent;
		if (k_parent == root || k_parent == NULL)
		{
			cout << "0\n";
		}
		else
		{
			node *k_grand_parent = k_parent->parent;
			int sib_num = 0;
			for (int i = 0; i < k_grand_parent->child.size(); i++)
			{
				sib_num += k_grand_parent->child[i]->child.size();
			}
			int brother_num = k_parent->child.size();
			cout << sib_num-brother_num << '\n';
		}
		
	}

	return 0;
}