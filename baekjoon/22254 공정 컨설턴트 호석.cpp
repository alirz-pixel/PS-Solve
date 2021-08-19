/*  2021-08-20  5:30
���� 22254�� ���� ������Ʈ ȣ�� || ���4
https://www.acmicpc.net/problem/22254


���ð��� ���� ���� ���� ���ο� ����  --> �켱���� ť�� �ð��� ���ؼ� ���ĵǵ��� �ۼ�
�ּ� ���������� ��  --> �̺�Ž���� �̿��Ͽ� true�� �� ���� ���� ��������, false�� �� ū���� Ž�� �ϵ��� �ۼ�



���۽ð� 5:31
����ð� 5:45       �ɸ��ð� : 14��  ||  �õ�Ƚ�� : 2ȸ (+4ȸ)
*/



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool complete(vector<int>& line, int num, int x);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, x, result;
    cin >> n >> x;

    int left = 1, mid, right = n;
    vector<int> line(n);
    for (auto &i : line)
        cin >> i;


    while(left <= right)
    {
        mid = (left + right) / 2;

        if (complete(line, mid, x))
        {
            right = mid - 1;
            result = mid;
        }

        else
            left = mid + 1;
    }

    cout << result;
    return 0;
}


bool complete(vector<int>& line, int num, int x)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < num; i++)
        pq.push(line[i]);


    int top;
    for (int i = num; i < line.size(); i++)
    {
        top = pq.top() + line[i];
        pq.pop();

        if (top > x)
            return false;

        pq.push(top);
    }

    return true;
}