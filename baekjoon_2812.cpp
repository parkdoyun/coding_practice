#include <iostream>
using namespace std;

// 백준 2812번 - 크게 만들기 (인터넷 참고)
// 스택
// 그리디 알고리즘
// 들어오려는 수가 스택의 top보다 크다면 pop하고 넣는다(스택의 top보다 작을 때까지)
// 만약 더 이상 수를 삭제할 수 없다면(del_count) 그냥 넣는다

int arr[500001]{ 0 };

int main()
{
	int n, k;
	cin >> n >> k;
	char c;
	int tmp;
	int del_count = 0;
	cin >> c;
	arr[0] = (int)(c - '0');
	int stack_ptr = 0;

	for (int i = 1; i < n; i++)
	{
		cin >> c;
		tmp = (int)(c - '0');
		if (del_count == k) // 만약 앞에서 삭제를 다 했다면 뒤에 전부 스택에 넣는다 (어차피 앞부분이 커야 큰 수가 나오므로)
		{
			arr[++stack_ptr] = tmp;
		}
		else
		{
			if (arr[stack_ptr] < tmp) // 스택의 top보다 수가 크다면
			{
				while (arr[stack_ptr] < tmp && del_count < k)
				{
					arr[stack_ptr] = tmp; // 스택에서 pop
					del_count++;
					stack_ptr--;
					if (stack_ptr == -1) // 스택의 top보다 작아지거나 스택에 있는 모든 수 삭제할 때까지
					{
						
						break;
					}
				}	
				stack_ptr++;
			}
			else
			{
				arr[++stack_ptr] = tmp;
			}
		}
	}
	for (int i = 0; i < n - k; i++) // 삭제를 k보다 덜 했을 경우 (뒤에 있는 수가 전부 작아서 스택에 전부 들어옴)
	{
		cout << arr[i];
	}
	cout << endl;
	return 0;
}