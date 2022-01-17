/*  2021-08-25  1:07
���� 2884�� �˶� �ð� || �����3
https://www.acmicpc.net/problem/2884



��(m) ������ ���� ��, 0�� ���� ������� �ʾ�
����ó���� ���ϰ� �Ǿ���.


���۽ð� : 1:07
����ð� : 1:11       �ɸ��ð� : 4��  ||  ����Ƚ�� : 2ȸ
*/




#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int h, m;
    cin >> h >> m;

    m = ((m + 60) - 45);
    if (m >= 60)
        m -= 60;
    else
        h--;

    if (h < 0)        
        h = 23;

    cout << h << " " << m;
    return 0;
}