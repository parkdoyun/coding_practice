#include <iostream>
using namespace std;

// 백준 1912번 - 연속합
// DP - 점화식
// 만약 다음 값이 음수라 더해졌을 때 더 작아진다면
// 비교 연속합(tmp_max)을 만들어서 현재 연속합(tmp_res)과 비교한다.

int main()
{
	int n, tmp, tmp_res, tmp_max, max;
	max = 0;
	tmp_res = 0;

	cin >> n; 
	int i = 1;

	cin >> tmp;
	max = tmp;
	tmp_res = tmp;

	while (n != 1) // n = 1인 경우, 바로 max 값 출력
	{	
		cin >> tmp;
		i++;
		
		if (tmp > tmp_res && tmp_res < 0) // 이전까지의 연속합이 음수이고 새 값이 양수일 때
		{
			tmp_res = tmp;
			max = tmp_res;
		}
		else if (tmp_res + tmp >= tmp_res) // 새 값이 양수거나 0 (0일때도 포함)
		{
			tmp_res += tmp;
			if (max < tmp_res) max = tmp_res;			
		}
		else if (tmp_res + tmp < 0) // 더하면 음수 -> 초기화
		{
			tmp_res = 0;
		}
		else if (tmp_res + tmp < tmp_res) // 더하면 작아짐(새 값이 음수), 비교 연속합 생성
		{
			tmp_max = tmp_res + tmp;			
			
			while (tmp_max < tmp_res && i < n) // 비교
			{
				cin >> tmp;
				i++;
				tmp_max += tmp;
				if (tmp_max > tmp_res)
				{
					tmp_res = tmp_max;
					if (tmp_res >= max) max = tmp_res;
					break;
				}		
				if (tmp_max < 0) // ***비교 연속합이 음수일 경우, tmp_res 유지
				{
					tmp_res = 0;
					break;
				}
			}
			tmp_max = 0;
		}
		if (i >= n) break;
	}

	cout << max << endl; // 결과 출력

	return 0;
}