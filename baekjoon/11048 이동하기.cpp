/*  2021-09-11  10:52
���� 11048�� �̵��ϱ�  ||  �ǹ�1
https://www.acmicpc.net/problem/11048



�׳� �����ϰ� dp �����δٰ� max���� üũ�ϸ鼭 �������� �ȴ�.



���۽ð� : 10:52
����ð� : 10:57     ����õ� : 1ȸ  ||  �ɸ��ð� : 5��
*/



#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);


	int n, m;
	cin >> n >> m;

	vector<vector<int>> maze(n, vector<int>(m));
	for (auto &i : maze)
		for (auto &j : i)
			cin >> j;

	
	// solve();
	vector<vector<int>> dp(n+1, vector<int>(m+1));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1])) + maze[i-1][j-1];


	cout << dp[n][m];

	return 0;
}