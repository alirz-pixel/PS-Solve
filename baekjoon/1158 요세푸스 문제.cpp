/*  2021-08-26  8:1:46
���� 1158�� �似Ǫ�� ���� || �ǹ�5
https://www.acmicpc.net/problem/1158




���۽ð� : 1:46
����ð� : 1:50       �ɸ��ð� : 4��  ||  ����Ƚ�� : 1ȸ
*/


#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    queue<int> q;
    int n, k;

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        q.push(i);


    // solve();
    cout << "<";
    int front, cnt;
    while(1)
    {
        cnt = k-1;

        while (cnt--)
        {
            q.push(q.front());
            q.pop();
        }

        if (q.size() == 1)
            break;

        cout << q.front() << ", ";
        q.pop();
    }

    cout << q.front() << ">";

    return 0;
}