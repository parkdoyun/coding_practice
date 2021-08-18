#include <iostream>
#include <string>
using namespace std;

// 백준 5397번 - 키로거
// 스택, 링크드 리스트
// 링크드 리스트로도 풀어보자

char arr[1000001];
char stack[1000001];

// arr + stack
// 커서 앞쪽 : arr, 커서 뒤쪽 : stack

int main()
{
	int t, stack_ptr, arr_ptr;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string str;
		cin >> str; // 입력
		stack_ptr = -1;
		arr_ptr = -1;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '<')
			{
				if (arr_ptr == -1) continue;
				stack[++stack_ptr] = arr[arr_ptr];
				arr_ptr--;
			}
			else if (str[j] == '>')
			{
				if (stack_ptr == -1) continue;
				arr[++arr_ptr] = stack[stack_ptr];
				stack_ptr--;
			}
			else if (str[j] == '-') // 삭제
			{
				if (arr_ptr == -1) continue;
				arr_ptr--;
			}
			else
			{
				arr[++arr_ptr] = str[j];
			}
		}
		for (int j = 0; j <= arr_ptr; j++)
		{
			cout << arr[j];
		}
		for (int j = stack_ptr; j >= 0; j--)
		{
			cout << stack[j]; // 출력
		}
		cout << '\n';
	}
	return 0;
}