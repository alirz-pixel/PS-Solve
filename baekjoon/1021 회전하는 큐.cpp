/*
���� 1021�� ȸ���ϴ� ť || �ǹ� 4
https://www.acmicpc.net/problem/1021


���������� �������� �̵�, ���������� �̵��� �ּڰ��� ���ϰ� �;�������
�̿� ���ؼ� �����ϰ� �����ؾߵ� �� ������,

���������� ���������θ� �̵��ص� �ð��ʰ��� ���� �ʴµ���
min(ť�� ����ִ� ������ - ���������� �̵��� Ƚ��, ���������� �̵��� Ƚ��) �� Ǯ �� �ִ� �� ����.
  = min(�������� �̵��� Ƚ��, ���������� �̵��� Ƚ��)


���۽ð� : 2:23
����ð� : 2:43
*/


#include <algorithm> 
#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    cin.tie();
    ios::sync_with_stdio(false);
    cout.tie();


    int cnt = 0, cntTemp, delTemp = 0;
    int N, M, del;
    cin >> N >> M;

    deque<int> dequeue;
    for (int i = 1; i <= N; i++)
        dequeue.push_back(i);

    cin >> del;
    while(!dequeue.empty() && M > delTemp)
    {
        if (del == dequeue.front())
        {
            dequeue.pop_front();
            delTemp++;

            if (delTemp < M)
                cin >> del;

            continue;
        }
        
        cntTemp = 0;
        while (dequeue.front() != del)
        {
            cout << "why not??" << endl;
            dequeue.push_back(dequeue.front());
            dequeue.pop_front();
            cntTemp++;
        }

        cnt += min(cntTemp, (int)dequeue.size() - cntTemp);
    }
    
    cout << cnt;
    return 0;
}