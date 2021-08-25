#include <iostream>
using namespace std;

// 백준 16173번 - 점프왕 쪨리
// 오른쪽부터 -> 아래
// DFS로 도달하지 못 하면 return
// 도달하면 나온다
// brute-force, DFS

void DFS(int n, int x, int y); // check: 도달했는지 변수
int check = -1;
int board[4][4]{ 0 };

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) // 입력
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	
	DFS(n, 0, 0);
	
	if (check == 1) cout << "HaruHaru\n";
	else cout << "Hing\n";
	
	return 0;
}
void DFS(int n, int x, int y)
{
	if (x > n - 1 || y > n - 1) return; // 범위 벗어남
	else if (x == n - 1 && y == n - 1)
	{
		check = 1;
		return;
	}
	else if (board[x][y] == 0) return; // *** 0이 칸에 있으면 무한루프 돈다
	else // 아닐 경우, 이동
	{		
		int a = board[x][y];
		DFS(n, x + a, y);
		DFS(n, x, y + a);		
	}
	
}