/* 
���� 1292�� ���� Ǫ�� ���� || �ǹ�5
https://www.acmicpc.net/problem/1292


�� ����غ��� ���������ε� ���� ������ ����ó�� ���̱�� �ϳ�
2�� �ݺ����� �� Ȱ���ϸ� �� ���� Ǯ �� �ִ� �����̴�.


���۽ð� 20:05
����ð� 20:14       �ɸ��ð� : 9��  ||  �õ�Ƚ�� : 1ȸ
*/


#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    int cnt = 1, now = 0, sum = 0;
    while (1) {
        for (int i = 0; i < cnt; i++) {
            now++;

            if (a <= now)
                sum += cnt;

            if (b <= now)
                break;
        }
        cnt++;

        if (b <= now)
            break;
    }
    
    cout << sum;
    return 0;
}