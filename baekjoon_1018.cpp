#include <iostream>
#include <vector>
using namespace std;

// w : 0, b : 1
// 백준 1018번 - 체스판 다시 칠하기
// brute-force
// 이렇게말고 그냥 배열에 64개 다 쓴 후에 비교하는 방법도 있을 듯.

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>>board(n);
	char tmp;
	for (int i = 0; i < n; i++)
	{
		board[i].resize(m);
		for (int j = 0; j < m; j++) // 체스판 입력
		{
			
			cin >> tmp;
			if (tmp == 'W') board[i][j] = 0;
			else board[i][j] = 1;
		}
	}
	// 맨처음이 w일 때와 B일 때 두개 중에 최소값 넣기
	// 모든 경우의 수 채스판 다 해본 뒤에 최소값 출력
	
	int start_x = 0;
	int start_y = 0; // 8*8
	
	
	int total_min = n * m;
	for (int i = 0; i < n - 8 + 1; i++) // 가로
	{
		for (int j = 0; j < m - 8 + 1; j++)
		{
			int check_cnt = 0;
			int cnt_w = 0; // w로 시작할 때(0)
			int cnt_b = 0; // b로 시작할 때(1)
			for (int r = 1; r <= 8; r++) // w로 시작할 때
			{
				if (r % 2 == 1) check_cnt = 1; // 1이면 홀수 검사
				for (int k = 1; k <= 8; k++)
				{
					if (r % 2 == 1) // 홀수 줄
					{
						if (k % 2 == 1 && board[i + r - 1][j + k - 1] == 1) cnt_w++; // 홀수 줄 홀수 번호
						else if(k % 2 == 0 && board[i + r - 1][j + k - 1] == 0) cnt_w++;
					}
					// 짝수 줄
					else
					{
						if (k % 2 == 1 && board[i + r - 1][j + k - 1] == 0) cnt_w++; // 홀수 줄 홀수 번호
						else if (k % 2 == 0 && board[i + r - 1][j + k - 1] == 1) cnt_w++;
					}

					
				}
			}
			for (int r = 1; r <= 8; r++) // b로 시작할 때
			{
				for (int k = 1; k <= 8; k++)
				{
					if (r % 2 == 1) // 홀수 줄
					{
						if (k % 2 == 1 && board[i + r - 1][j + k - 1] == 0) cnt_b++; // 홀수 줄 홀수 번호
						else if (k % 2 == 0 && board[i + r - 1][j + k - 1] == 1) cnt_b++;
					}
					// 짝수 줄
					else
					{
						if (k % 2 == 1 && board[i + r - 1][j + k - 1] == 1) cnt_b++; // 홀수 줄 홀수 번호
						else if (k % 2 == 0 && board[i + r - 1][j + k - 1] == 0) cnt_b++;
					}
				}
			}

			int cnt = (cnt_w < cnt_b ? cnt_w : cnt_b);
			if (total_min > cnt) total_min = cnt;
		}
		
	}

	cout << total_min << endl;
	return 0;
}