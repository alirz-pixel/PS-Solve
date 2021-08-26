/*  2021-08-22  8:36
���� 2161�� ī��1 || �����2
https://www.acmicpc.net/problem/2161






���۽ð� : 1:30
����ð� : 1:33       �ɸ��ð� : 3��  ||  ����Ƚ�� : 1ȸ
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
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
        q.push(i);

    
    // solve();
    bool turn = false;
    while(!q.empty())
    {
        // ������ ����
        if (!turn)
            cout << q.front() << " ";

        // ī�带 ���� �Ʒ��� ������ ����
        else
            q.push(q.front());

        turn = !turn;
        q.pop();
    }


    return 0;
}
