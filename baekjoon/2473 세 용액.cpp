/*  2021-08-28  10:20
���� 2473�� �� ���  ||  ���4
https://www.acmicpc.net/problem/2473



�ð����⵵ ����� �߸��Ͽ�
N * log N �˰������� Ǯ���� �ߴٰ�

����õ� 4���̳� Ʋ��������
�ð����⵵�� N^2�� �˰������� Ǯ �� �ִٴ� ���� �˰ԵǾ�

�� ���� �ڵ带 ���µ� 14���� �ҿ��Ͽ� �ڵ带 �����Ͽ���.


-----------
== ����
 - for������ �� ���� �����̸鼭,
   �� ���� ���ؼ� �� �����͸� �����ϴ� ������� ������ Ǯ����.
   
   �ð����⵵ O(N^2)
   

���۽ð� : 11:26
����ð� : 11:40       �ɸ��ð� : 14�� (+1�ð�) ||  ����Ƚ�� : 1ȸ (+4ȸ)
*/


#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    // input()
    int n;
    cin >> n;

    vector<long long int> water(n);
    for (auto &i : water)
        cin >> i;

    sort(water.begin(), water.end());
    
    // solve();
    long long int sum, min = abs(water[0] + water[1] + water[2]);

    int l, r, resultIndex[3] = { 0, 1, 2 };
    for (int i = 0; i < n-2; i++)
    {

        l = i+1;
        r = n-1;

        // �� ���� ������ ��, ��������
        while (l < r)
        {
            sum = water[i] + water[l] + water[r];

            if (min > abs(sum))
            {
                min = abs(sum);

                resultIndex[0] = i;
                resultIndex[1] = l;
                resultIndex[2] = r;
            }

            if (sum > 0)
                r--;
            else
                l++;
        }
    }


    // output();
    for (auto i : resultIndex)
        cout << water[i] << " ";
    return 0;
}