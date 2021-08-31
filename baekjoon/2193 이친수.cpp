/*  2021-08-31  4:58
���� 2193�� ��ģ��  ||  �ǹ�3
https://www.acmicpc.net/problem/2193




ù ��° Ǯ�� :
 - ���� ��Ģ�� ã�ƺ��� �Ǻ���ġ ���� ������ �ִٴ� ���� �˰ԵǾ���.
   ���� �����ϰ� �Ǻ���ġ �� �ڵ带 ¥�� �����Ͽ���.


���۽ð� : 4:58
����ð� : 5:08       �ɸ��ð� : 10��  ||  ����Ƚ�� : 1ȸ


�� ��° Ǯ�� :
       ���� :  0   1
 n = 1 �� ��,  0   1
 n = 2 �� ��,  1   0
 n = 3 �� ��,  1   1

 - �̷��� ������� ����
   ���� n�� 0 ������ 'n-1'�� 0�� ���� + 'n-1'�� 1�� �����̸�,
   ���� n�� 1 ������ 'n-1'�� 0�� ������� ���� �˰ԵǾ���.

   �̸� �̿��Ͽ� �ڵ带 ¥�� �Ǿ���.

���۽ð� : ?:??
����ð� : ?:??       �ɸ��ð� : �뷫 15��  ||  ����Ƚ�� : 1ȸ
*/


#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    // first : 0�� ����
    // second : 1�� ����
    vector<pair<ll, ll>> dp(n);
    dp[0].first = 0;
    dp[0].second = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i].first = dp[i-1].first + dp[i-1].second;
        dp[i].second = dp[i-1].first;
    }

    cout << dp[n-1].first + dp[n-1].second;
    return 0;
}


// ù Ǯ��  -  �ɸ��ð� : 10��  ||  �õ�Ƚ�� : 1ȸ;
// #include <iostream>

// using namespace std;

// int main(void)
// {
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     cout.tie(0);


//     int n;
//     cin >> n;

//     long long result = 1, temp1 = 1, temp2 = 1;
//     for (int i = 3; i <= n; i++)
//     {
//         result = temp1 + temp2;
//         temp1 = temp2;
//         temp2 = result;
//     }


//     cout << result;

//     return 0;
// }