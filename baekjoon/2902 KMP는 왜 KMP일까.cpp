/*
���� 2902 KMP�� �� KMP�ϱ�? || �����2
https://www.acmicpc.net/problem/2902


.... �������� ����� ������ Ǫ��
������ ����� �����.

���۽ð� 9:42
����ð� 9:45     �ɸ��ð� : 3��  ||  �õ�Ƚ�� : 1ȸ
*/



#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    string input, result;
    cin >> input;

    result += input[0];
    for (int i = 1; i < input.size(); i++)
    {
        if(input[i-1] == '-')
            result += input[i];
    }

    cout << result;
    return 0;
}