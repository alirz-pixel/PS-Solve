/*  2021-08-20  4:42
���� 11943�� ���� �ű�� || �����4
https://www.acmicpc.net/problem/11943





���۽ð� 4:42
����ð� 4:45         �ɸ��ð� : 3��  ||  �õ�Ƚ�� : 1ȸ
*/


#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int a, b, c, d;
    cin >> a >> b;  
    cin >> c >> d;

    cout << min(a+d, c+b);

    return 0;
}