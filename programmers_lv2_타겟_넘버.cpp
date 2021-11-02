#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
struct node
{
	int value;
	int level;
	node(int v, int l)
	{
		value = v;
		level = l;
	}
	node() {};
};
*/

// DFS
void DFS(int num, int idx, int &answer, int target, vector<int> numbers)
{
	if (idx == numbers.size())
	{
		if(num == target) answer++;
		return;
	}
	DFS(num + numbers[idx], idx + 1, answer, target, numbers);
	DFS(num - numbers[idx], idx + 1, answer, target, numbers);
}
// 프로그래머스 - level2 : 타겟 넘버
// queue. while loop 사용하는 게 BFS와 유사 (참고 문제)
// 시간 초과 -> 기본 BFS 사용 시 시간 초과 발생하는 듯
// DFS로 풀어보기

int main()
{
	int answer = 0;
	vector<int>	numbers = { 1, 1, 1, 1, 1 };
	int target = 3;

	// BFS
	/*
	// queue에 넣고 하나씩 빼면서 계산 (***numbers[0]도 부호 있음***)
	vector<node> queue;
	queue.push_back(node(numbers[0], 0));
	queue.push_back(node(numbers[0] * -1, 0));
	node root;
	int a;
	for (int i = 1; i < numbers.size(); i++)
	{
		while (queue.size() != 0 && queue[0].level == i - 1)
		{
			root = queue[0];
			queue.erase(queue.begin()); // dequeue

			a = root.value + numbers[i]; // +
			queue.push_back(node(a, i)); // enqueue(새로운 값)

			a = root.value - numbers[i]; // -
			queue.push_back(node(a, i)); // enqueue(새로운 값)
		}
	}

	// 마지막에 target과 같은 결과 count
	for (int i = 0; i < queue.size(); i++)
	{
		if (queue[i].level == numbers.size() - 1 && queue[i].value == target) answer++;
	}
	*/

	// DFS
	DFS(numbers[0], 1, answer, target, numbers);
	DFS(numbers[0] * -1, 1, answer, target, numbers); // numbers[0]도 부호 있음

	cout << answer << endl;
	return 0;

}