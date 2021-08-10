#include <iostream>

using namespace std;

// 백준 11052번 - 카드 구매하기
// DP - 점화식
// 카드가 1개일 때부터 n개일 때까지 최댓값을 차차 구해나간다
// 카드가 n개일 때의 최댓값을 M(n)라 하면
// M(1) + M(n-1), M(2) + M(n-2), ... , M(0.5*(n-1)) + M(..) 중에서 최댓값을 구하고
// Pn과 비교하여 카드가 n개일 때의 최댓값을 구한다
// (어차피 카드의 개수가 더 많아진다 해도 특정 카드 개수의 최댓값은 변하지 않는다)
// [ex] 1) M(1) = P1
// 2) M(2) => M(1)*2 vs P2 => M(1)*2
// 3) M{3} => M(1)*3 vs M(2)+M(1) = M(1)*2+M(1) = M(1)*3 vs P3


int main()
{
	int n;
	cin >> n;

	int price_max[10002]{ 0 }; // 카드가 n개일 때의 최댓값 배열
	int value[10002]{ 0 }; // 카드의 가격 배열
	
	for (int i = 1; i <= n; i++)
	{
		cin >> value[i];
	}

	price_max[1] = value[1];
	if (value[1] * 2 > value[2]) price_max[2] = value[1] * 2;
	else price_max[2] = value[2];

	for (int i = 3; i <= n; i++)
	{
		int max = 0;
		for (int j = 1; j < (i / 2 + 1); j++) // 절반만 구해보면 된다 -> (1) + (n-1) = (n-1) + (1)
		{
			if (max < price_max[j] + price_max[i - j]) max = price_max[j] + price_max[i - j];
		}
		if (max < value[i]) price_max[i] = value[i]; // 마지막으로 Pn과 비교
		else price_max[i] = max;
	}

	cout << price_max[n] << endl;

	return 0;
}