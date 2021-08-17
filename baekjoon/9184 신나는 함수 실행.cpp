/*  2021-08-18  3:15
���� 9184�� �ų��� �Լ� ���� || �ǹ�2
https://www.acmicpc.net/problem/9184



�Ǻ���ġ �Լ��� ������ ��ó�� ����Լ��� DP�� �̿��� Ǯ����.


���۽ð� 3:16
����ð� 3:32       �ɸ��ð� : 16��  ||  ����Ƚ�� : 1ȸ
*/


#include <iostream>
#include <vector>

using namespace std;


// vector<vector<vector<int>>> dp(21, vector<vector<int>>(21, vector<int>(21)));
int dp[21][21][21];
int solve(int a, int b, int c);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);
    

    int a, b, c;


    while (1) {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break;

        
        cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << "\n";
    }
    


    return 0;
}


int solve(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
        return solve(20, 20, 20);


    int& ret = dp[a][b][c];
    if (ret != 0)
        return ret;

    if (a < b && b < c)
        ret = (solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c));
    else
        ret = (solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1));

    return ret;
}