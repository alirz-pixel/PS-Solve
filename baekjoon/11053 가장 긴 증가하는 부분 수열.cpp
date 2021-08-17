/*  2021-08-17
���� 11053�� ���� �� �����ϴ� �κ� ���� || �ǹ�2
https://www.acmicpc.net/problem/11053



���� �� �����ϴ� �κ� ������ O(n^2)���� �����ϰ� ������ �� �ִ�.
�ٸ�, �Է��� 10,000�� �Ǵ� ���� O(log n)���� Ǯ��� �Ǵ� ���� �������̴�.

���۽ð� 10:34
����ð� 10:42
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


    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];


    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i]) dp[i] = max(dp[j]+1, dp[i]);

    cout << *max_element(dp.begin(), dp.end());
    return 0;
}