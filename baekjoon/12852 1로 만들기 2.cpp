/*  2021-08-17
���� 12852�� 1�� ����� 2 || �ǹ�1
https://www.acmicpc.net/problem/12852



1�� ����� 1�� Ǯ���� ������
BFS��� ���� �ٷ� �� �� �־�����

DPƯ���� ���� �Ŀ� Ǭ ������
�������� ���� Ȱ���� �� �־���.

���۽ð� 9:58
����ð� 10:17       �ɸ��ð� : 19��  ||  ����Ƚ�� : 1ȸ
*/




#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void solve(int n);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    solve(n);

    return 0;
}


void solve(int n)
{
    vector<int> dp(n + 1, -1);

    queue<int> q;
    q.push(n);

    int front;
    while(!q.empty())
    {
        front = q.front();
        q.pop();


        if (front % 3 == 0 && dp[front/3] == -1)
        {
            dp[front/3] = front;

            if (front / 3 == 1)
                break;

            q.push(front/3);
        }

        if (front % 2 == 0 && dp[front/2] == -1)
        {
            dp[front/2] = front;

            if (front / 2 == 1)
                break;

            q.push(front/2);
        }

        if (front > 1 && dp[front-1] == -1)
        {
            dp[front-1] = front;

            if (front-1 == 1)
                break;

            q.push(front-1);
        }
    }


    stack<int> result;
    int searchBack = 1;
    while(dp[searchBack] != -1)
    {
        result.push(searchBack);
        searchBack = dp[searchBack];
    }
    result.push(n);

    cout << result.size()-1 << "\n";
    while(!result.empty())
    {
        cout << result.top() << " ";
        result.pop();
    }
}