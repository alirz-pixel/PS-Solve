/*  2021-08-22  2:27
���� 13904�� ���� || ���3
https://www.acmicpc.net/problem/13904



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

2�� Ǯ�� ��� :
 - 1. ������ ������ ���� ������ �����Ѵ�.
 - 2. ������ ������ ���� ������ ��ȸ�Ѵ�. �� ��
 - 2-1 ����, ���� ��ȸ���� �� ������ �������� �������� ���ٸ� �湮ó���� ���� ��, result ������ �����ش�.
 - 2-2                                     �������� �ִٸ� 0���� ũ�� �����Ϻ��� ���� ���� �湮ó���� ���ְ� result ������ �����ش�.
===============================


���۽ð� 2:10  &&  2:34
����ð� 2:15  &&  2:43        �ɸ��ð� : 15��  ||  �õ�Ƚ�� : 1ȸ
                         2�� : �ɸ��ð� : 9��  ||  �õ�Ƚ�� : 1ȸ
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);

    
    int n;
    cin >> n;

    vector<pair<int, int>> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i].second >> input[i].first;

    sort(input.begin(), input.end(), greater<pair<int,int>>());

    // solve();
    vector<bool> day(1001);
    int j, result = 0;
    for (int i = 0; i < n; i++)
    {
        if (!day[input[i].second])
        {
            result += input[i].first;
            day[input[i].second] = true;
        }

        else
        {
            for (j = input[i].second; j > 0; j--)
            {
                if (day[j] == false)
                    break;
            }

            if (j != 0)
            {
                result += input[i].first;
                day[j] = true;
            }
        }
    }
    
    cout << result;
    return 0;
}