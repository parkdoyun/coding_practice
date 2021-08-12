#include <stdio.h>

// 백준 14241 - 슬라임 합치기
// 최소 힙 이용

int main()
{
	int n, x, arr_n;
	scanf("%d", &n); // n

	int arr[101];
	arr_n = 0; // 힙에 있는 노드의 개수

	for (int i = 0; i < n; i++) // 슬라임 크기 입력, 힙에 넣기
	{
		scanf("%d", &x);
		// 노드(슬라임) 추가
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
	int score = 0; // 점수
	int slime_size = arr[1];
	for (int i = 0; i < n; i++) // 슬라임 꺼내서 점수 최댓값 계산
	{
		if (i == 0)
		{
			slime_size = arr[1];
		}
		else
		{
			score += slime_size * arr[1];
			slime_size += arr[1];
		}
		if (arr_n == 1)
		{
			arr[1] = 0;
			arr_n--;
		}
		else
		{
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
	printf("%d\n", score); // 점수 출력

	return 0;
}
