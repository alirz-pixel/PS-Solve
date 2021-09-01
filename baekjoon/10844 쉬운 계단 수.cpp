/*  2021-08-31  4:58
���� 10844�� ���� ��� ��  ||  �ǹ�1
https://www.acmicpc.net/problem/10844



���̳��� ���α׷����� top-down ����� �̿��Ͽ� Ǯ����.

���� ���� :
 - �� ���ڸ��� 0~9�� �� �� �����Ƿ� for���� ������ topdown �Լ��� ȣ���Ѵ�.
   �׸��� ��� ���� ���ؼ� (level-1, nowNum-1) + (level-1, nowNum+1)�� �Ͽ� ���� ������ ������.

    ���⼭ �̹� ����� ���� �� ����ϴ� ��찡 ���� �� �����Ƿ�
    dp[level][num] ������ ����� �̷� ��츦 �����Ͽ���.


   

���۽ð� : ?:??
����ð� : ?:??       �ɸ��ð� : ??��  ||  ����Ƚ�� : 1ȸ
*/


#include <iostream>
#include <vector>
const long long mod = 1000000000;

using namespace std;
using ll = long long;

ll topdown(vector<vector<ll>>& dp, int level, int num);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    // dp[level][num];
    // num = 0~9;
    vector<vector<ll>> dp(n, vector<ll>(10, 0));
    dp[0][0] = 0;
    for (int i = 1; i <= 9; i++)
        dp[0][i] = 1;

    ll result = 0, temp;
    for (int i = 0; i <= 9; i++)
        result = (result + topdown(dp, n-1, i)) % mod;

    cout << result;

    return 0;
}


ll topdown(vector<vector<ll>>& dp, int level, int num)
{
    if (num < 0 || num > 9)
        return 0;

    if (level == 0 && num == 0)
        return 0; // dp[0][0];

    if (dp[level][num])
        return dp[level][num];

    return dp[level][num] = (topdown(dp, level-1, num+1) + topdown(dp, level-1, num-1)) % mod;
}