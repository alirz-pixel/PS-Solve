/*  2021-08-26 2:12
���� 9934�� ǳ�� �Ͷ߸��� || �ǹ�1
https://www.acmicpc.net/problem/9934


��Ģ�� �̷��ϴ�.

�־��� n�� ���Ͽ�
Ʈ���� ���̰� 1�� ���, �ε����� 1���� �����Ͽ� �ݺ�-{����(1) x 2}�� ���� ���̰� 1�� ����� ��Ģ�� ����ִ�.
Ʈ���� ���̰� 2�� ���, �ε����� 2���� �����Ͽ� �ݺ�-{����(2) x 2}�� ���� ���̰� 2�� ����� ��Ģ�� ����ִ�.

�̸� �Ϲ�ȭ �ϸ�
Ʈ���� ���̰� n�� ���, �ε����� n���� �����Ͽ� �ݺ�-{2n}�� ���� ���̰� n�� ����� ��Ģ�� ���� �� �ִ�.


���۽ð� : 2:38
����ð� : 3:00       �ɸ��ð� : 22��  ||  ����Ƚ�� : 1ȸ
*/


#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int n, temp;
    cin >> n;
    
    temp = (int)pow(2, n);
    vector<int> input(temp);
    for (int i = 1; i <= (temp-1); i++)
        cin >> input[i];

    
    int jump = 2;
    vector<vector<int>> result(n+1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = jump/2; j <= temp-1; j += jump)
            result[i].push_back(input[j]);
        jump *= 2;
    }

    for (int i = n; i > 0; i--)
    {
        for(int j = 0; j < result[i].size(); j++) 
            cout << result[i][j] << " ";

        cout << "\n";
    }
    return 0;
}