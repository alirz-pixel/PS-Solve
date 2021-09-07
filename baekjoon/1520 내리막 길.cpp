/*  2021-08-31  4:58
���� 1520�� ������ ��   ||  ���4
https://www.acmicpc.net/problem/1520



�����ڷ� - https://yabmoons.tistory.com/340

ù �õ� : BFS
�� ��° �õ� : DFS + DP (������ �ð��ʰ�)
�� ��° �õ� : DFS + DP

�˰��� ��� :
 - DP[][] = c�� ( m-1, n-1 )�� �� �� �ִ� ��δ� �� c�� �����Ѵٴ� �ǹ��̴�.
 
 - (����Լ�) DFS�� ��ȸ�ϸ�, ( m-1, n-1 )�� ������ ���
   �� ��ο� ���Ե� DP �迭�� 1[���������� �� �� �ִ� ����� ��]�� �ʱ�ȭ ���ش�.

   �ٸ� ��ε� ���� DFS�� ��ȸ�ϸ鼭 dp �迭�� ��� ���� Ȯ���ϰ�,
   �� ���� �̿��Ͽ� ���������� �����ϴ� ����� ���� ����ؼ� ���س�����.




���۽ð� : 2:57  
����ð� : 4:21       �ɸ��ð� : 1�ð� 24��  ||  ����Ƚ�� : 4ȸ
*/


#include <iostream>
#include <vector>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<vector<int>> map, dp;
int m, n;

int DFS(int y, int x);
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);


	cin >> m >> n;
	
	map = vector<vector<int>>(m, vector<int>(n));
	dp = vector<vector<int>>(m, vector<int>(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}

	
	// solve()
	cout << DFS(0, 0);

	return 0;
}


int DFS(int y, int x)
{
	// ������ ����
	if (y == m-1 && x == n-1)
		return 1;
	
	// �������� �� �� �ִ� ��� or �� �� ���� ���
	if (dp[y][x] != -1)
		return dp[y][x];

	dp[y][x] = 0;	
	for (int i = 0; i < 4; i++)
	{
		int my = y + dy[i];
		int mx = x + dx[i];

		if (my < 0 || mx < 0 || mx >= n || my >= m)
			continue;

		if (map[y][x] > map[my][mx])
			dp[y][x] = dp[y][x] + DFS(my, mx);
	}

	return dp[y][x];
}