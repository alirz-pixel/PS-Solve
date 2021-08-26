/*  2021-08-22  8:36
���� 17608�� ����� || �����2
https://www.acmicpc.net/problem/17608



42�� �ٿ� max ���� �����ϴ� �ڵ� ���
stick[i]�� ��� ����ó���� �Ǿ���....

----------
��Ǯ�� :
������ vector�� Ǯ�����µ�,

�̷� ������ ��� �������� ®�� ��
for���� ���� ����� ���� �ʾƵ� �Ǽ� ������ Ǯ �� �ִ�.


for������ Ǯ���� ��� :
    for (int i = n - 2; i >= 0; i++)  

���� ó�� i�� �ʱⰪ�� n-2�� �ؾߵȴٴ� ���� �����ؾߵǱ� ������
stack���� Ǫ�� ���� ���ϴ�.

���۽ð� : 1:07
����ð� : 1:14       �ɸ��ð� : 7��  ||  ����Ƚ�� : 2ȸ
*/



#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, temp, result = 0, max = 0;
    cin >> n;

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        st.push(temp);
    }

    while(!st.empty())
    {
        if (st.top() > max)
        {
            max = st.top();
            result++;
        }

        st.pop();
    }

    cout << result;
    return 0;
}