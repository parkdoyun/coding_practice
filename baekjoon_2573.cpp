#include <iostream>
using namespace std;

// 백준 2573번 - 빙산
// DFS
// 주변 0 몇개인지 저장하는 배열 (상하좌우)
// 한꺼번에 감소 시킴
// 몇 덩어리인지 확인 (DFS)

struct node
{
	int x = -1;
	int y = -1;
	int zero_cnt = -1;
};

int board[302][302]{ 0 }; // 보드
int visit[302][302]{ 0 }; // 방문
void DFS(int n, int m, int x, int y);

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	int year = 0;
	while (true) // 두 덩어리 이하로 남을 때까지
	{
		node arr[10001];
		int arr_ptr = 0; // 앞으로 들어갈 수 있는 배열 포인터
		for (int i = 1; i < n-1; i++)
		{
			for (int j = 1; j < m-1; j++)
			{
				if (board[i][j] != 0)
				{
					// 상하좌우 0 확인
					int zero_cnt = 0;
					if (board[i - 1][j] == 0) zero_cnt++;
					if (board[i + 1][j] == 0) zero_cnt++;
					if (board[i][j - 1] == 0) zero_cnt++;
					if (board[i][j + 1] == 0) zero_cnt++;
					arr[arr_ptr] = { i, j, zero_cnt };
					arr_ptr++;
				}
			}
		}
		// 전부 0됨(빙산이 다 녹을 때까지 분리되지 않음)
		if (arr_ptr == 0)
		{
			cout << "0\n";
			break;
		}
		// 감소
		for (int i = 0; i < arr_ptr; i++)
		{
			if (board[arr[i].x][arr[i].y] >= arr[i].zero_cnt)
			{
				board[arr[i].x][arr[i].y] -= arr[i].zero_cnt;
			}
			else board[arr[i].x][arr[i].y] = 0;
		}
		year++;
		
		// 덩어리 개수 확인
		int mass_n = 0;
		for (int i = 1; i < n - 1; i++)
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (board[i][j] != 0 && visit[i][j] == 0)
				{
					visit[i][j] = 1;
					DFS(n, m, i, j);
					mass_n++;
				}
			}
		}
		if (mass_n >= 2)
		{
			cout << year << '\n';
			break;
		}

		//memset(visit, 0, sizeof(visit)); // visit배열 0으로 초기화 -> 안 됨
		for (int i = 1; i < n - 1; i++) // 방문 초기화
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (visit[i][j] != 0) visit[i][j] = 0;
			}
		}
		
	}

	return 0;
}
void DFS(int n, int m, int x, int y)
{
	// 상하좌우 0 아니고 숫자인지, 방문 안 했는지 확인
	if (x + 1 >= 1 && x + 1 < n - 1 && y >= 1 && y < m - 1
		&& board[x+1][y] != 0 && visit[x+1][y] == 0)
	{
		visit[x + 1][y] = 1;
		DFS(n, m, x + 1, y);
	}
	if (x - 1 >= 1 && x - 1 < n - 1 && y >= 1 && y < m - 1
		&& board[x - 1][y] != 0 && visit[x - 1][y] == 0)
	{
		visit[x - 1][y] = 1;
		DFS(n, m, x - 1, y);
	}
	if (x >= 1 && x < n - 1 && y + 1 >= 1 && y + 1 < m - 1
		&& board[x][y + 1] != 0 && visit[x][y + 1] == 0)
	{
		visit[x][y + 1] = 1;
		DFS(n, m, x, y + 1);
	}
	if (x>= 1 && x< n - 1 && y - 1 >= 1 && y - 1 < m - 1
		&& board[x][y - 1] != 0 && visit[x][y - 1] == 0)
	{
		visit[x][y - 1] = 1;
		DFS(n, m, x, y - 1);
	}
}
