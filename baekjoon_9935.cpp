#include <iostream>
#include <string>
using namespace std;

// 백준 9935번 - 문자열 폭발
// 스택
// 처음부터 넣는다
// 만약 폭발 문자열에 해당될 경우 pop한다

char stack[1000001]; // 스택 역할 배열

int main()
{
	string input_s, exp_s;
	cin >> input_s >> exp_s;
	int stack_ptr = -1;
	int exp_size = exp_s.size();
	int err_cnt;
	
	for (int i = 0; i < input_s.size(); i++)
	{
		if (input_s[i] == exp_s[exp_size - 1])
		{ // 같으면 폭발 문자열이 들어가 있으면 pop
			err_cnt = 0;
			for (int j = 0; j < exp_size-1; j++)
			{				
				if (exp_s[exp_size - j - 2] != stack[stack_ptr - j]) // 폭발 문자열 들어있지 않으면
				{					
					stack[++stack_ptr] = input_s[i]; // 그냥 스택에 넣고 다음 문자열 확인
					err_cnt = 1;
					break;
				}
			}
			if (err_cnt == 0) // 폭발 문자열 들어있으면
			{
				stack_ptr -= (exp_size - 1); // 폭발 문자열만큼 pop
			}
		}
		else
		{
			stack[++stack_ptr] = input_s[i];
		}
	}
	if (stack_ptr == -1) cout << "FRULA\n";
	else
	{
		for (int i = 0; i <= stack_ptr; i++) // 결과 출력
		{
			cout << stack[i];
		}
		cout << '\n';
	}
	
	return 0;
}