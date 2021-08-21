/*  2021-08-22  2:27
���� 13904�� ���� || ���3
https://www.acmicpc.net/problem/16234



�ٸ� ������ �����ϸ鼭(ģ���� ��ȭ �� �뷡) Ǯ���µ��� 15�� ���� Ǯ� �׷���
����� �����ϴ�.  [Ƽ� �� �� å���Ȱ� ���⵵]


===========================
Ǯ�� ����� �̷��ϴ�.
�������� ������� �ʾƵ� ��������

�������� ���� �����ο� �� ���� �����Ͽ�
�켱���� ť�� �ִ´�.

�� �����Ͽ� ���� �Է°����� �켱���� ť�� �ְ���,
�� �߿��� ���� ū ���� ������ result ������ �����ش�.   (�׳� pq.pop() �ϸ� ��)

�̷��� 0�ϱ��� �ݺ��ϸ� ���� Ǯ �� �ִ�.
===========================

���۽ð� 2:10
����ð� 2:15       �ɸ��ð� : 15��  ||  �õ�Ƚ�� : 1ȸ
*/



#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_queue<int> pq;
    vector<vector<int>> day(1001);

    int inputDay, inputEnd, maxDay = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> inputDay >> inputEnd;

        maxDay = max(inputDay, maxDay);
        day[inputDay].push_back(inputEnd);
    }


    int result = 0;    
    for (int i = maxDay; i > 0; i--)
    {
        for (int j = 0; j < day[i].size(); j++)
            pq.push(day[i][j]);


        if (!pq.empty())
        {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result;
    return 0;
}