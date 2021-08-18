#include <iostream>
using namespace std;

// 트리 탐색 예시

void preorder(int tree[],int tmp_idx);
void inorder(int tree[], int tmp_idx);
void postorder(int tree[], int tmp_idx);

int main()
{
	int tree[16] = { 0, 50, 30, 98, 24, 45, 52, 0, 5, 28, 0, 0, 0, 60, 0, 0 };
	cout << "---------PreOrder----------\n";
	preorder(tree,1);
	cout << "\n---------PostOrder----------\n";
	postorder(tree, 1);
	cout << "\n---------InOrder----------\n";
	inorder(tree, 1);
	return 0;
}

void preorder(int tree[], int tmp_idx)
{
	if (tree[tmp_idx] == 0) return;
	cout << tree[tmp_idx] << endl; // leaf node
	if (tmp_idx * 2 <= 15) preorder(tree, tmp_idx * 2); // left
	if (tmp_idx * 2 + 1 <= 15) preorder(tree, tmp_idx * 2 + 1); // right
	return;
}

void inorder(int tree[], int tmp_idx)
{
	if (tmp_idx * 2 <= 15) inorder(tree, tmp_idx * 2); // left
	if (tree[tmp_idx] == 0) return;
	cout << tree[tmp_idx] << endl; // leaf node
	if (tmp_idx * 2 + 1 <= 15) inorder(tree, tmp_idx * 2 + 1); // right
	return;
}

void postorder(int tree[], int tmp_idx)
{
	if (tree[tmp_idx] == 0) return;
	if (tmp_idx * 2 <= 15) postorder(tree, tmp_idx * 2);
	if (tmp_idx * 2 + 1 <= 15) postorder(tree, tmp_idx * 2 + 1);
	cout << tree[tmp_idx] << endl; // leaf node
	return;
}