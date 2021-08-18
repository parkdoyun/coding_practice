#include <iostream>
using namespace std;

// 백준 5639 - 이진 검색 트리
// 이진 탐색 트리
// 후위 순회하면서 값 출력 + 메모리 정리

struct node
{
	int value;
	node *left = NULL;
	node *right = NULL;
};

void preOrder(int value, node *tmp, node *prev);
void postOrder(node *tmp);

int main()
{
	int n;
	cin >> n;
	node *root = new node;
	root->value = n;
	
	while (cin >> n) // 입력 제한 없을 때 이런 식으로 처리
	{
		preOrder(n, root, NULL);
	}
	postOrder(root);
	return 0;
}

void preOrder(int value, node *tmp, node *prev) // 전위 순회
{
	if (tmp == NULL) // leaf node
	{
		node *n = new node;
		n->value = value;
		if (value < prev->value) prev->left = n; // tmp로 비교하면 안 됨 (NULL이기 때문에 right랑 같음)
		else prev->right = n;
		return;
	}
	if (value < tmp->value)	preOrder(value, tmp->left, tmp);
	if (value > tmp->value) preOrder(value, tmp->right, tmp);
}

void postOrder(node *tmp) // 후위 순회
{
	if (tmp->left != NULL) postOrder(tmp->left);
	if (tmp->right != NULL) postOrder(tmp->right);
	cout << tmp->value << '\n';
	if (tmp->left == NULL && tmp->right == NULL) delete tmp; // 메모리 정리
}