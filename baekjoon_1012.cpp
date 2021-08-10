#include <iostream>
#include <vector>
using namespace std;

int search_cab(vector<vector<int>>&c, int x, int y, int w, int h);

// 백준 1012번 - 유기농 배추
// recursion(재귀), DFS

int main()
{
	int w, h; // width, height
	int cabbage_n; // number
	int test_n;
	cin >> test_n;
	for (int i = 0; i < test_n; i++)
	{
		cin >> w >> h >> cabbage_n;
		vector<vector<int>>cab(w, vector<int>(h, 0));
		int *idx_arr = new int[cabbage_n * 2]; // 좌표 저장 배열
		int x, y;
		for (int j = 0; j < cabbage_n; j++)
		{
			cin >> x >> y;
			cab[x][y] = 1; // 1 넣기
			idx_arr[j * 2] = x;
			idx_arr[j * 2 + 1] = y;
		}
		int bug_n = 0;
		for (int j = 0; j < cabbage_n; j++)
		{
			
			if (cab[idx_arr[j * 2]][idx_arr[j * 2 + 1]] == 1)
			{
				bug_n++;
				search_cab(cab, idx_arr[j * 2], idx_arr[j * 2 + 1], w, h);
			}
		}

		cout << bug_n << endl;
		w = 0;
		h = 0;

		delete[] idx_arr;
	}
	return 0;
}

int search_cab(vector<vector<int>>&c, int x, int y, int w, int h)
{
	c[x][y] = 0; // 0으로 지움
	// 위로 이동
	if (x > 0 && (c[x - 1][y] == 1))search_cab(c, x - 1, y, w, h);
	// 아래로 이동
	if (x >= 0 && x < w-1 && (c[x + 1][y] == 1))search_cab(c, x + 1, y, w, h);
	// 왼쪽
	if (y > 0 && (c[x][y-1] == 1))search_cab(c, x , y-1, w, h);
	// 오른쪽
	if (y >= 0 && y < h-1 && (c[x][y + 1] == 1))search_cab(c, x, y + 1, w, h);
	// 끝에 오면 중지
	return 0; // 재귀 종료
}