/*  2021-08-20  2:35
���� 15700�� Ÿ�� ä��� 4 || �����4
https://www.acmicpc.net/problem/15700



1x2 or 2x1 Ÿ���� ��ġ�ϴ� ������ 2ĭ�̴�.
�׷��� ������ n x m ������ �־����� ��, 

�� ������ �� �� �ִ� Ÿ���� ũ���� 2�� �������ָ�
�� ������ �� �� �ִ� Ÿ���� ������ �� �� �ְ� �Ǵ� ���̴�.
(���� ����ư ����)


���۽ð� 2:35
����ð� 2:40     �ɸ��ð� : 5��  ||  �õ�Ƚ�� : 2ȸ
*/


#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    long long int n, m;
    cin >> n >> m;

    cout << (n * m) / 2;
    return 0;
}