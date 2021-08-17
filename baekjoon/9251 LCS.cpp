/*
���� 9251�� LCS || ���5
https://www.acmicpc.net/problem/9251



��ϴ��б� �˰��� Ư�� �ð���
���̳��� ���α׷����� ���� �� ������ ���� �˰����� �������ּż�
���� Ǯ �� �־���.


���۽ð� *:**
����ð� *:**      (�ǹ̾���)
*/




#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size()+1, 0));
    for (int i = 1; i <= a.size(); i++)
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i-1] == b[j-1])  dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    cout << dp[a.size()][b.size()];

    return 0;
}