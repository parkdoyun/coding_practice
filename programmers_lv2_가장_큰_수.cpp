#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) // 앞자리부터 뒷자리까지 전부 비교, a가 더 클 때 true return -> 이렇게 하지 X
{
	/*
	if (a == b) return false; // 두 수가 같을 경우 (true return 시 segmentation error)
	int size = (a.size() >= b.size() ? b.size() : a.size()); // 작은 사이즈로 비교 -> 같은 것 중 짧은 게 앞에 온다
	int small_chk = 0; // 사이즈 더 작은 수 체크, b가 사이즈 더 큼
	if (a.size() >= b.size()) small_chk = 1; // a가 사이즈 더 큼

	// 비교
	for (int i = 0; i < size; i++)
	{
		if ((int)a[i] == (int)b[i]) continue;
		else if ((int)a[i] > (int)b[i]) return true;
		else if ((int)a[i] < (int)b[i]) return false;
	}
	
	// 남은 숫자가 이전 숫자보다 클 경우 -> 남은 숫자 가진 수가 더 큼
	if (small_chk == 1) // a가 남은 숫자 가지는 경우
	{
		if ((int)a[size] > (int)a[size - 1]) return true;
		else return false; // 더 작은 경우 -> 남은 숫자 없는 수가 더 큼
	}
	else // b가 남은 숫자 가지는 경우
	{
		if ((int)b[size] > (int)b[size - 1]) return false;
		else return true; // 더 작은 경우 -> 남은 숫자 없는 수가 더 큼
	}
	*/

	// string은 + 연산자 지원
	return a + b > b + a;
}

// 프로그래머스 level2 - 가장 큰 수
// 정렬

int main()
{
	vector<int> numbers = { 979, 97, 978, 81,818,817 };
	string answer = "";

	// numbers string으로 변환
	vector<string> number;
	stringstream ssInt;
	for (int i = 0; i < numbers.size(); i++)
	{
		// int to string
		ssInt << numbers[i];
		number.push_back(ssInt.str());
		ssInt.str("");
	}

	// 정렬
	sort(number.begin(), number.end(), cmp);

	int zero_cnt = -1;// 0 아니면 -> 1
	for (int i = 0; i < number.size(); i++)
	{
		answer += number[i];
	}
	// 전부 0일 경우 -> 000..00이 아니라 0으로 바꿔줌
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] != '0')
		{
			zero_cnt = 1;
			break;
		}
	}
	if (zero_cnt == -1) answer = "0";

	cout << answer << endl;
	return 0;
}