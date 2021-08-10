#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 백준 12865번 - 평범한 배낭
// DP

int main()
{

	int n, k;
	cin >> n >> k;

	vector<int> weight(n + 1);
	vector<int> value(n + 1);

	vector<vector<int>> DP(n + 1, vector<int>(k + 1, 0)); // 0인 2차원 벡터(n x k)

	for (int i = 1; i <= n; i++)
	{
		cin >> weight[i] >> value[i]; // 무게와 값 입력 받음

	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - weight[i] >= 0) // 이번 물건 넣을 수 있을 때와 그렇지 못할 때 비교
			{ // 넣을 수 있을 때(감당할 수 있는 무게가 될 때)
				int max = DP[i - 1][j];
				if (max < DP[i - 1][j - weight[i]] + value[i]) max = DP[i - 1][j - weight[i]] + value[i]; // 만약 가치가 더 크다면 넣는다
				DP[i][j] = max;
			}
			else // 물건 못 넣을 때
			{
				DP[i][j] = DP[i - 1][j]; // 지금 물건 없을 때랑 똑같음
			}

		}
	}
	cout << DP[n][k] << endl;

	return 0;
}