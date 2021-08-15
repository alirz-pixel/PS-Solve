/*
���� 2847�� ������ ���� ������ || �ǹ�4
https://www.acmicpc.net/problem/2847



���� ������ ���� ������ ������ ��,
���� ������ �� ũ�ٸ� (���� ����-1)�� �ǵ��� ������Ʈ�� �����ָ� �ȴ�.
(��, �ǹ�4 ������ ���̵�)

�̷� ������ ���� ���п� ���ҽ�Ų �� ���� ���� ����
[���� ����] - [���� ����]�� ����ؼ� ���س�����,
���ҽ�Ų �� ���� ���� �� �ְ� �Ǵ� ���̴�.


���۽ð� 1:04
����ð� 1:09   �ɸ��ð� : 5��  ||  �õ�Ƚ�� : 1ȸ
*/


#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int n, result = 0;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    
    for (int i = arr.size()-1; i > 0; i--)
        if (arr[i] <= arr[i - 1])
        {
            result += arr[i-1] - (arr[i]-1);
            arr[i-1] = arr[i]-1;
        }

    cout << result;

    return 0;
}