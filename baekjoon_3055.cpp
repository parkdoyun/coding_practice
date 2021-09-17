#include <iostream>
#include <vector>
using namespace std;

// 백준 3055번 - 탈출
// BFS

struct point
{
	int x;
	int y;
	int distance = 0; // 거리 (시간)
};

char map[51][51];
int visit[51][51]{ 0 }; // 물 BFS
int s_visit[51][51]{ 0 }; // 고슴도치 이동 BFS
vector<point> water;
vector<point> s_vec;

void initVisit(int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			visit[i][j] = 0;
		}
	}
}

void print(int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}
int main()
{
	int r, c;
	cin >> r >> c;
	point s;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S')
			{
				s.x = i;
				s.y = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == '*')
			{
				water.push_back(point{ i, j });
			}
		}
	}

	// BFS -> 물 확장 & 고슴도치 이동
	point tmp_w;
	s_vec.push_back(s);
	int exit_cnt = 0; // -1 : error, 1 : 종료
	while (true)
	{		
		int tmp_distance; 
		if(water.size() != 0) tmp_distance = water[0].distance; // 이거까지는 다 해야함! , ***조심하기!*** (인덱스)
		while (water.size() != 0) // 한 거리까지는 한번에 다 해야함, 빈 벡터 참조 안 하도록 조건 설정
		{
			//if (water.size() == 0) break; // 물이 더 이상 찰수가 없음
			tmp_w = water[0];
			if (tmp_w.distance > tmp_distance) break;
			water.erase(water.begin()); // pop
			if (tmp_w.x - 1 >= 0 && visit[tmp_w.x - 1][tmp_w.y] == 0
				&& map[tmp_w.x - 1][tmp_w.y] == '.')
			{
				visit[tmp_w.x - 1][tmp_w.y] = 1;
				map[tmp_w.x - 1][tmp_w.y] = '*'; // 물이 참
				water.push_back(point{ tmp_w.x - 1, tmp_w.y, tmp_w.distance + 1 });
			}
			if (tmp_w.x + 1 < r && visit[tmp_w.x + 1][tmp_w.y] == 0
				&& map[tmp_w.x + 1][tmp_w.y] == '.')
			{
				visit[tmp_w.x + 1][tmp_w.y] = 1;
				map[tmp_w.x + 1][tmp_w.y] = '*'; // 물이 참
				water.push_back(point{ tmp_w.x + 1, tmp_w.y, tmp_w.distance + 1 });
			}
			if (tmp_w.y - 1 >= 0 && visit[tmp_w.x][tmp_w.y - 1] == 0
				&& map[tmp_w.x][tmp_w.y - 1] == '.')
			{
				visit[tmp_w.x][tmp_w.y - 1] = 1;
				map[tmp_w.x][tmp_w.y - 1] = '*'; // 물이 참
				water.push_back(point{ tmp_w.x, tmp_w.y - 1 , tmp_w.distance + 1 });
			}
			if (tmp_w.y + 1 < c && visit[tmp_w.x][tmp_w.y + 1] == 0
				&& map[tmp_w.x][tmp_w.y + 1] == '.')
			{
				visit[tmp_w.x][tmp_w.y + 1] = 1;
				map[tmp_w.x][tmp_w.y + 1] = '*'; // 물이 참
				water.push_back(point{ tmp_w.x, tmp_w.y + 1, tmp_w.distance + 1 });
			}
		}
		
		// BFS 고슴도치
		
		if (s_vec.size() == 0)
		{
			exit_cnt = -1;
			break; // 이동 불가능
		}
		
		int tmp_s_distance;
		if(s_vec.size() != 0) tmp_s_distance = s_vec[0].distance; //***조심하기!*** (인덱스)
		while (s_vec.size() != 0)
		{
			s = s_vec[0];
			if (s.distance > tmp_s_distance) break;
			//print(r, c);
			//cout << s.x << ' ' << s.y << endl << endl;

			s_vec.erase(s_vec.begin());
			if (map[s.x][s.y] == 'D')
			{
				exit_cnt = 1;
				cout << s.distance << '\n';
				break;
			}
			if (s.x - 1 >= 0 && map[s.x - 1][s.y] != '*' && map[s.x - 1][s.y] != 'X'
				&& s_visit[s.x - 1][s.y] == 0)
			{
				s_visit[s.x - 1][s.y] = 1;
				s_vec.push_back(point{ s.x - 1, s.y, s.distance + 1 });
			}
			if (s.x + 1 < r && map[s.x + 1][s.y] != '*' && map[s.x + 1][s.y] != 'X'
				&& s_visit[s.x + 1][s.y] == 0)
			{
				s_visit[s.x + 1][s.y] = 1;
				s_vec.push_back(point{ s.x + 1, s.y, s.distance + 1 });
			}
			if (s.y - 1 >= 0 && map[s.x][s.y - 1] != '*' && map[s.x][s.y - 1] != 'X'
				&& s_visit[s.x][s.y - 1] == 0)
			{
				s_visit[s.x][s.y - 1] = 1;
				s_vec.push_back(point{ s.x, s.y - 1, s.distance + 1 });
			}
			if (s.y + 1 < c && map[s.x][s.y + 1] != '*' && map[s.x][s.y + 1] != 'X'
				&& s_visit[s.x][s.y + 1] == 0)
			{
				s_visit[s.x][s.y + 1] = 1;
				s_vec.push_back(point{ s.x, s.y + 1, s.distance + 1 });
			}
		}
		if (exit_cnt != 0) break;
		
	}
	if (exit_cnt == -1) cout << "KAKTUS\n";


	return 0;
}