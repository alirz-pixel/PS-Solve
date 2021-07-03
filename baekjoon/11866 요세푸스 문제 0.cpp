/*
���� 11866�� �似Ǫ�� ���� 0 || �ǹ� 4
https://www.acmicpc.net/problem/11866


��ť�� ������, Kĭ ������ ������ �տ��� pop�ϰ� �ڿ� push ���ش�.
 = (�׳� ť�� ����߾ �Ǿ���)


���۽ð� : 3:12
����ð� : 3:21
*/


#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int cnt = 0;
    int N, K;
    cin >> N >> K;

    deque<int> DQ;
    for (int i = 1; i <= N; i++)
        DQ.push_back(i);

    
    cout << "<";
    while (!DQ.empty())
    {
        if (DQ.size() == 1)
            break;

        if (cnt == K - 1)
        {
            cnt = 0;
            cout << DQ.front() << ", ";
            DQ.pop_front();
            continue;
        }

        cnt++;
        DQ.push_back(DQ.front());
        DQ.pop_front();
    }  
    cout << DQ.front() << ">";

    return 0;
}