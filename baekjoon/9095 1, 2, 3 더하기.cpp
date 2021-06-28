/*
���� 9095�� 1, 2, 3 ���ϱ� || �ǹ� 3
https://www.acmicpc.net/problem/9095

�� ������ ����ȭ �Ϸ� ������ ������ �𸣰ھ
�ٸ� ����� ���� ���ԵǾ���...

������ ����� ����ȭ�� �ƴ� ����� ����� �̿��� ���̴�.
�׳� �ܼ��� �Է��� n�� �־����� �� n�� ���� ������ ��͸� ���鼭 +1, +2, +3�� �ݺ��ϸ� �Ǵ� ���̴�.

==> �̷��� �ڵ带 ¥���� f(n) = f(n - 1) + f(n - 2) + f(n - 3);�� �Ǵ°��� Ȯ���Ͽ���.
==> ��, ���Ǽ��� �Ͽ� ����ȭ�� ���Ѱſ���..
*/

#include <iostream>

using namespace std;

void loop(int aim, int now);

int cnt;
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int DP[12] { 0, };
    int T, n;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> n;

        if (DP[n] == 0)
        {
            cnt = 0;
            loop(n, 0);

            DP[n] = cnt;
        }

        cout << DP[n] << "\n";
    }
    return 0;
}

void loop(int aim, int now)
{
    if (aim < now)
        return;

    if (aim == now)
    {
        cnt++;
        return;
    }

    
    loop(aim, now + 1);
    loop(aim, now + 2);
    loop(aim, now + 3);

    return;
}