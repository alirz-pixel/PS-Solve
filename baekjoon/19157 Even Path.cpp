/*  2021-08-22  8:36
���� 19157�� Even Path || ���4
https://www.acmicpc.net/problem/19157


���ͳ��� �����Ͽ� Ǯ��.
�����ϱ� ������ �׷����̷����� Ǯ��� �Ǵ� �� �˾����� �ð��ʰ� 3��Ÿ ����

���۽ð� : ?:??
����ð� : ?:??    (�ǹ̾���.) 
*/



#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int n, q;
    cin >> n >> q;

    vector<int> col(n+1), row(n+1), R(n+1), C(n+1);
    for (int i = 1; i <= n; i++)
        cin >> row[i];

    for (int i = 1; i <= n; i++)
        cin >> col[i];


    R[1] = C[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (row[i]%2 == row[i-1]%2)
            R[i] = R[i-1];
        else
            R[i] = i;

        if (col[i]%2 == col[i-1]%2)
            C[i] = C[i-1];
        else
            C[i] = i;
    }


    // solve();
    int ra, ca, rb, cb;
    while(q--)
    {
        cin >> ra >> ca >> rb >> cb;

        if (ra < rb) swap(ra, rb);
        if (ca < cb) swap(ca, cb);

        if (R[ra] <= rb && C[ca] <= cb)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}