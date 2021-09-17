#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 백준 16236번 - 아기 상어
// BFS - 한번에 잡아먹을 수 있는 물고기 하나 탐색
// 탐색하면서 시간 계산 & total distance에 더하기
// 탐색 완료 후 다시 그 자리에서 BFS

struct point
{
	int x = -1;
	int y = -1;
	int distance = 0;
};
int board[21][21]{ 0 }; // 0~19 사용
int visit[21][21]{ 0 }; // 방문 : 0 아님
vector<point> queue; // 거리가 가까운 물고기 여러개라면, BFS 한번마다 정렬돼야 함 -> 좌표 순으로 정렬

void print(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visit[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void initVisit(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visit[i][j] = 0;
		}
	}
}

bool cmp(point a, point b) // 벡터 정렬 (distance -> 좌표 순)
{
	if (a.distance < b.distance) return true;
	else if (a.distance == b.distance)
	{
		if (a.x > b.x) return false;
		else if (a.x < b.x) return true;
		else if (a.x == b.x && a.y < b.y) return true;
		else return false;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	point shark;
	int shark_size = 2;
	int shark_eat = 0;
	int total_distance = 0;

	int a;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a;
			if (a == 9)
			{
				shark.x = i;
				shark.y = j;
				visit[i][j] = 1;
			}
			else board[i][j] = a;
		}
	}
	queue.push_back(shark);
	
	// BFS로 물고기 서치
	
	int i = 1;
	point tmp;
	int exit_cnt = 0;
	while (true)
	{
		while (true) // 한번 BFS 끝나고 visit[] 초기화
		{
			if (queue.size() == 0)
			{
				exit_cnt = 1;
				break; // 먹을 수 없는 상황 -> 종료
			}
			// 매번 정렬(distance 작은 순 -> x 작은 순 -> y 작은 순)
			sort(queue.begin(), queue.end(), cmp);
			tmp = queue[0];
			queue.erase(queue.begin()); // pop
			// 만약 물고기라면 -> BFS 종료
			if (board[tmp.x][tmp.y] > 0 && board[tmp.x][tmp.y] < shark_size)
			{
				//print(n);
				//cout << board[tmp.x][tmp.y] << ' ' << tmp.distance << endl;
				shark_eat++;
				if (shark_eat == shark_size)
				{
					shark_size++;
					shark_eat = 0;
				}
				board[tmp.x][tmp.y] = 0;
				total_distance += tmp.distance;
				// visit[] 초기화
				initVisit(n);
				tmp.distance = 0; // 거리 초기화
				// queue 초기화 & tmp 집어넣기
				queue.clear();
				queue.push_back(tmp);
				break;
			}

			// 상하좌우 확인
			if (tmp.x - 1 >= 0 && visit[tmp.x - 1][tmp.y] == 0
				&& board[tmp.x - 1][tmp.y] <= shark_size) // 위
			{
				visit[tmp.x - 1][tmp.y] = 1;

				queue.push_back(point{ tmp.x - 1, tmp.y, tmp.distance + 1 });
			}
			if (tmp.y - 1 >= 0 && visit[tmp.x][tmp.y - 1] == 0
				&& board[tmp.x][tmp.y - 1] <= shark_size) // 왼쪽
			{
				visit[tmp.x][tmp.y - 1] = 1;

				queue.push_back(point{ tmp.x, tmp.y - 1 , tmp.distance + 1 });
			}
			if (tmp.x + 1 < n && visit[tmp.x + 1][tmp.y] == 0
				&& board[tmp.x + 1][tmp.y] <= shark_size) // 아래
			{
				visit[tmp.x + 1][tmp.y] = 1;

				queue.push_back(point{ tmp.x + 1, tmp.y , tmp.distance + 1 });
			}
			if (tmp.y + 1 < n && visit[tmp.x][tmp.y + 1] == 0
				&& board[tmp.x][tmp.y + 1] <= shark_size) // 오른쪽
			{
				visit[tmp.x][tmp.y + 1] = 1;

				queue.push_back(point{ tmp.x, tmp.y + 1 , tmp.distance + 1 });
			}

			
		}
		if (exit_cnt != 0)
		{
			cout << total_distance << '\n';
			break;
		}
	}
	
	return 0;
}