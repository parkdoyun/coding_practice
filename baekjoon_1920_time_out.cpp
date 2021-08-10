#include <iostream>
#include <algorithm>

// 백준 1920번
// binary search
// time out 

using namespace std;

int main()
{
	int n, m;
	cin >> n;

	
	int *num = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	sort(num, num+n); // 배열 sort

	cin >> m;
	int tmp;

	for (int i = 0; i < m; i++)
	{
		int idx_center = n / 2;
		int idx_front = 0;
		int idx_back = n - 1;

		cin >> tmp;			
		int check_cnt = 0;

		while (idx_back - idx_front >= 0)
		{
			idx_center = (idx_front + idx_back) / 2;
			
			if (num[idx_center] == tmp)
			{
				cout << 1 << endl;
				check_cnt++;
				break;
			}
			else if (num[idx_center] > tmp) idx_back = idx_center - 1;
			else idx_front = idx_center + 1;
		}
		if (check_cnt == 0) cout << 0 << endl;
	}


	delete[] num;

	return 0;
}