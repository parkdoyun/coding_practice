#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 백준 1157번 - 단어 공부
// 문자열

struct alpha
{
	int idx = -1;
	int cnt = 0;
};
bool cmp(alpha a, alpha b)
{
	if (a.cnt > b.cnt) return true;
	return false;
}
int main()
{
	string s;
	cin >> s;
	struct alpha arr[27];
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			arr[(int)(s[i] - 'A')].cnt++;
			arr[(int)(s[i] - 'A')].idx = (int)(s[i] - 'A');
		}
		else
		{
			arr[(int)(s[i] - 'a')].cnt++;
			arr[(int)(s[i] - 'a')].idx = (int)(s[i] - 'a');
		}
	}

	sort(arr, arr+27, cmp); // 내림차순
	int err_cnt = 0;
	int max = arr[0].cnt;
	if (arr[1].cnt == max)
	{
		cout << '?' << endl;
		err_cnt = 1;
	}
	if (err_cnt == 0) cout << (char)(arr[0].idx + 'A') << '\n';
	return 0;
}