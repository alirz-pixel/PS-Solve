/*  2021-08-22  8:36
���� 9659�� �� ����5 || �ǹ�2
https://www.acmicpc.net/problem/9659



���۽ð� : 8:38
����ð� : 8:40     �ɸ��ð� : 2��  ||  ����Ƚ�� : 1ȸ
*/



#include <iostream>

using namespace std;

int main(void)
{   
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    long long int n;
    cin >> n;

    if (n % 2)
        cout << "SK";
    else
        cout << "CY";

    return 0;
}