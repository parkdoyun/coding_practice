#include <iostream>
#include <string>
using namespace std;

// 백준 5430번 - AC
// 덱
// 배열로 받고, 시작 인덱스, 끝 인덱스, 방향 변수 이용하여 배열 제어

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int arr[100001]{ 0 };
		int order_n, n;
		int start_idx = 0; int end_idx; // 시작, 끝 인덱스
		int direction = 1; // 1 : 오른쪽, -1 : 왼쪽 (방향)
		
		string func;
		cin >> func;
		cin >> n;
		order_n = func.length();
		int idx = 1;
		char c;
		cin >> c; // '['
		int a;
		for (int j = 0; j < n; j++)
		{
			cin >> a;
			arr[j] = a; // 숫자 바로 입력 받음
			cin >> c; // ',' or ']'
		}
		if (n == 0) cin >> c; // 마지막 ']' 처리 (만약 n = 0 이면 마지막 괄호 ']' 입력 안 받아져서 다음 func에 들어가게 됨)
		// 배열이 비어있는데 D를 사용한 경우 에러
		int err_cnt = 0;
		end_idx = n-1; // 맨 끝
		for (int j = 0; j < order_n; j++)
		{
			if (func[j] == 'R')
			{
				direction = direction * -1;
				// 시작과 끝 인덱스 교체
				int tmp = start_idx;
				start_idx = end_idx;
				end_idx = tmp;
			}
			else if (func[j] == 'D')
			{
				// 배열이 비어있는데 D를 사용한 경우 에러
				if((direction == 1 && start_idx > end_idx) || (direction == -1 && start_idx < end_idx))
				{
					err_cnt = 1;
					break;
				}
				if (direction == 1) start_idx++;
				else if (direction == -1) start_idx--;
			}
		}

		// 출력
		if (err_cnt != 0) cout << "error" << endl;
		else
		{
			cout << '[';
			
			// 오른쪽 진행인지 왼쪽 진행인지
			if (direction == 1)
			{
				for (int j = start_idx; j <= end_idx; j++)
				{
					cout << arr[j];
					if (j != end_idx) cout << ',';
				}
			}
			else if (direction == -1)
			{
				for (int j = start_idx; j >= end_idx; j--)
				{
					cout << arr[j];
					if (j != end_idx) cout << ',';
				}
			}
			cout << ']' << endl;
		}


	}

	return 0;
}