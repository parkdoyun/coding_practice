#include <iostream>
using namespace std;

// 백준 2493번 - 탑
// 스택
// 만약 앞에 있는 탑이 신호 수신 못 한다면(낮다면) push
// 스택에는 내림차순으로 들어오게 됨 (7, 5, 2, ...)
// 만약 앞에 있는 탑이 신호 수신 가능할 때 (높을 때) 스택에 있는 탑도 수신 가능한 지 확인
// 스택에 있는 탑들은 현재 내 탑보다 큰 수이기 때문에 스택에 있는 것
// 가능하면 pop, 인덱스 저장

struct node
{
	int height = 0; // 탑 높이
	int idx = 0; // 몇번째의 탑인지
};

struct node stack[500002]; // 스택
int arr[500002]{ 0 }; // 배열
int tower_num[500002]{ 0 }; // 몇번째 탑이 수신하는지

int main()
{
	int n, stack_ptr;
	cin >> n;
	stack_ptr = -1;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i]; // 입력
	}

	for (int i = n; i >= 2; i--)
	{
		if (arr[i] > arr[i - 1]) // 만약 앞에 있는 탑이 낮다면
		{// stack에 넣자
			stack[++stack_ptr] = node{ arr[i], i };
		}
		else // 만약 앞에 있는 탑이 높다면
		{
			// 스택 탑 확인
			while (stack_ptr > -1)
			{
				if (stack[stack_ptr].height < arr[i - 1]) // 앞에 있는 탑이 스택에 있는 탑보다 높다면
				{
					// pop
					tower_num[stack[stack_ptr].idx] = i - 1;
					stack_ptr--;
				}
				else break;
			}
			
			// 현재 탑 정보 갱신
			tower_num[i] = i - 1;
		}
	}

	// 스택 비우기 (필요 X, 굳이 안 비워도 디폴트 값 0으로 지정함)

	for (int i = 1; i <= n; i++)
	{
		cout << tower_num[i] << ' ';
	}
	cout << '\n';

	return 0;
}