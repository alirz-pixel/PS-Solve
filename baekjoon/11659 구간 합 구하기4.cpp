/*
���� 11659�� ���� �� ���ϱ� 4 || �ǹ� 3
https://www.acmicpc.net/problem/11659

�� �ƽ����� ���� ���Բ��� �ð����⵵�� O(1)�� ���´ٰ� �˷��ּż�
�� �κп� ������ ���� Ǯ���� ������ ���� �ð����� ������ ���� �� ���� �ƽ���.



���۽ð� : 9:58
����ð� : 10:17   �õ� Ƚ��: 1  ||  �ҿ�ð�: 19��
*/

  
  
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int N, M, t1, t2;
    cin >> N >> M;

    vector<int> input(N + 1);
    vector<int> sum(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> input[i];
        sum[i] = input[i] + sum[i - 1];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> t1 >> t2;

        cout << sum[t2] - sum[t1 - 1] << "\n";
    }

    return 0;
}