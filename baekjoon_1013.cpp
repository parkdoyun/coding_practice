#include <iostream>
#include <string>
using namespace std;

// 백준 1013번 - Contact
// 문자열, 정규표현식
// 01 OR 100:0....01:1...1

int main()
{
	int n;
	cin >> n;
	string s, tmp;
	
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		
		tmp = "";
		int j = 0;
		int err_cnt = 0;
		while (j < s.size())
		{			
			if (s.size() == 1) // 한글자 -> 무조건 NO
			{
				err_cnt = 1;
				break;
			}
			
			tmp += s[j];

			if (tmp == "01")
			{				
				tmp = "";
			}
			else if (tmp == "100")
			{
				while (j != s.size() && s[j] == '0') // 0 반복
				{
					tmp += s[j];
					j++;
				}
				if (j == s.size() && s[j - 1] == '0') // 마지막이 0 (100000...0)
				{
					err_cnt = 1;
					break;
				}
				else if (j == s.size() && s[j - 1] == '1') // 끝이 (1000..01)
				{
					tmp = "";
					break;
				}
				// 1 계속 돌기
				if (j != s.size() && s[j] == '1') // 1000...01...
				{
					tmp = s[j];
					j++; // 100..0(1) 처음 1 빼기
				
					while (j != s.size() && s[j] == '1') // 1 반복
					{
						tmp += s[j];
						j++;
					}
					tmp = "";
					if (s[j - 1] == '1' && s[j - 2] == '0') // 1이 하나였음 (100010..)
					{
						continue;
					}
					// 만약에 11...1100 이거나 11...1101 일수도
					if (j < s.size() - 1 && s[j] == '0' && s[j + 1] == '0') // 11..1100 -> 100부터 시작
					{
						j = j - 1;
						continue;
					}
					else if (j < s.size() - 1 && s[j] == '0' && s[j + 1] == '1') continue; // 01 인식하도록
				}
				
			}
			else if (tmp == "00" || tmp == "11")
			{
				break;
			}			

			j++;
		}
		if (tmp != "" || err_cnt != 0) cout << "NO\n";
		else cout << "YES\n";
		
	}

	return 0;
}