#include <stdio.h>
#include <string.h>

// 백준 1406번 - 에디터
// 커서 이동하면서 스택에 넣자
// 문자열 배열 + 스택 구조
// 스택

char string[600001];
char stack[600001];

int main()
{
	int stack_ptr = -1;
	int string_ptr = -1; // 마지막 원소 인덱스 표시
	scanf("%s", string);
	string_ptr = strlen(string) - 1;
	int m;
	scanf("%d", &m);
	char inst, c;
	for (int i = 0; i < m; i++)
	{
		scanf("%c", &inst); // 개행문자 입력(C++과 다름)
		scanf("%c", &inst);
		if (inst == 'L')
		{
			if (string_ptr == -1) continue;
			stack[++stack_ptr] = string[string_ptr];
			string_ptr--;
		}
		else if (inst == 'D')
		{
			if (stack_ptr == -1) continue;
			string[++string_ptr] = stack[stack_ptr];
			stack_ptr--;
		}
		else if (inst == 'B')
		{
			if (string_ptr == -1) continue;
			string_ptr--;
		}
		else // P
		{
			scanf("%c", &c); // 공백
			scanf("%c", &c);
			string[++string_ptr] = c;
		}
	}
	for (int i = 0; i <= string_ptr; i++)
	{
		printf("%c", string[i]);
	}
	for (int i = stack_ptr; i >= 0; i--) // 스택은 거꾸로
	{
		printf("%c", stack[i]);
	}


	printf("\n"); // 작은 따옴표 쓰면 에러
	return 0;
}