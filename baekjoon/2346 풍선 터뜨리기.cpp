/*  2021-08-26 2:12
���� 2346�� ǳ�� �Ͷ߸��� || �ǹ�3
https://www.acmicpc.net/problem/2346



dequeue�� �̿��Ͽ� ���̿� �����ִ� ����ŭ '�̵�'�ϴ°� ����Ʈ��.
��, ��ť������ '�̵�'�� '��� ����, ��� ������' ��� ���� �ǹ��Ѵ�.


���� ���̿� ���� ���� ����̸�,
�տ��� ����, �� ���� �ڿ��ٰ� �ִ´ٶ�� �ǹ̰� �ȴ�.

�ݴ�� �����̸�
�ڿ��� ����, �� ���� �տ��ٰ� �ִ´ٶ�� �ǹ��̴�.


���⼭ ������ ���� �ϳ� ����µ�,
ǳ���� �Ͷ߸� �� ��ť���� ��Ұ� �ϳ� ������� ���� �ǹǷ�
������ ���� ���� { 1�� ���ų�, 1�� ���ϴ� } ������ �߰������� ����� �ȴٴ� ���̴�.

�� ���� �����Ѵٸ�, ���� Ǯ �� �ִ�.



���۽ð� : 2:12
����ð� : 2:23       �ɸ��ð� : 11��  ||  ����Ƚ�� : 1ȸ
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int n, temp;
    cin >> n;

    deque<pair<int, int>> deq;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        deq.push_back({temp, i});
    }


    // solve();
    int front;
    while(!deq.empty())
    {
        // ǳ�� ��Ʈ����
        front = deq.front().first;
        cout << deq.front().second << " ";
        deq.pop_front();



        // ��Ʈ�� ǳ���� �ִ� ������ ���� �� ��ŭ �̵�
        // ǳ���� �ȿ� ���� ���̰� ����� ��
        if (front > 0)
        {
            front--;
            while(front--)
            {
                deq.push_back(deq.front());
                deq.pop_front();
            }
        }
        else
        {
            front++;
            while(front <= 0)
            {
                deq.push_front(deq.back());
                deq.pop_back();
                front++;
            }
        }
    }
    return 0;
}