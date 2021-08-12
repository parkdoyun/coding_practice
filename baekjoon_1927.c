#include <stdio.h>

// 백준 1927 - 최소 힙
// C++로 돌리면 시간 초과
// C로 돌리니까 됨
// 1차원 배열 arr 이용
// arr[1] -> 루트 노드, arr[2] : 루트의 왼쪽 자식 노드, arr[3] = 루트의 오른쪽 자식 노드

int main()
{
	int n, x, arr_n;
	scanf("%d", &n);
	
	int arr[100001];
	arr_n = 0; // 힙에 있는 노드의 개수
	for (int i = 0; i < n; i++)
	{		
		scanf("%d", &x);
		if (x > 0) // 노드 추가
		{
			arr_n++;
			arr[arr_n] = x;
			if (arr_n != 1)
			{
				int child_idx = arr_n;
				int parent_idx = child_idx / 2;
				while (child_idx != 1 && (arr[child_idx] < arr[parent_idx]))
				{
					int tmp = arr[child_idx];
					arr[child_idx] = arr[parent_idx];
					arr[parent_idx] = tmp;
					child_idx = parent_idx;
					parent_idx = parent_idx / 2;
				}
			}
			
		}
		else // x = 0, 루트 출력 & 삭제
		{
			if (arr_n == 0) printf("0\n");
			else if (arr_n == 1)
			{
				printf("%d\n", arr[1]);
				arr[1] = 0;
				arr_n--;
			}
			else
			{
				printf("%d\n", arr[1]);
				arr[1] = arr[arr_n];
				arr[arr_n] = 0;
				arr_n--;
				int parent_idx = 1;
				int child_left_idx, child_right_idx;

				// 삭제하고 루트밖에 안 남았을 때 (parent가 리프 노드인지 확인)
				while (!(parent_idx * 2 > arr_n))
				{ // 자식 노드 확인
					child_left_idx = parent_idx * 2;
					child_right_idx = child_left_idx + 1;
					// 1. 자식이 두명 -> 더 작은 자식 노드 비교, 큰 자식 노드 비교, 둘다 크면 종료
					if (parent_idx * 2 + 1 <= arr_n)
					{
						int big_child_idx = (arr[child_left_idx] > arr[child_right_idx] ? child_left_idx : child_right_idx);
						int small_child_idx = (big_child_idx == child_left_idx ? child_right_idx : child_left_idx);
						if (arr[small_child_idx] < arr[parent_idx])
						{
							// 부모 노드와 자식 노드 바꾸기
							int tmp = arr[small_child_idx];
							arr[small_child_idx] = arr[parent_idx];
							arr[parent_idx] = tmp;
							parent_idx = small_child_idx;
						}
						else if (arr[big_child_idx] < arr[parent_idx])
						{
							// 부모 노드와 자식 노드 바꾸기
							int tmp = arr[big_child_idx];
							arr[big_child_idx] = arr[parent_idx];
							arr[parent_idx] = tmp;
							parent_idx = big_child_idx;
						}
						else break;
					}
					else // 2. 자식이 한명(왼쪽) -> 자식 노드 비교, 크면 종료
					{
						if (arr[child_left_idx] < arr[parent_idx])
						{
							int tmp = arr[child_left_idx];
							arr[child_left_idx] = arr[parent_idx];
							arr[parent_idx] = tmp;
							parent_idx = child_left_idx;
						}
						else break;
					}
				}
			}
		}
	}

	return 0;
}