/*
���� 9012�� ��ȣ || �ǹ�4
https://www.acmicpc.net/problem/9012


�� ������ c++ �������� Ǯ�� ���� �ٽ� Ǯ��Ҵ�.

�� �������� stack�� ����� ��,
stack�� ����ִ� ���¿��� st.top()�� ȣ���Ű�� �ȵȴٴ� ����
�˰ԵǾ���.

���۽ð� 6:18   
����ð� 6:25       �ɸ��ð� : 8��  ||  �õ�Ƚ�� : 1ȸ
*/


#include <iostream>
#include <stack>

using namespace std;

void solve(const string& input)
{
    stack<char> st;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
            st.push(input[i]);

        else if (input[i] == ')')
        {
            if (st.empty())
            {
                cout << "NO\n";
                return;
            }

            if (st.top() == '(')
                st.pop();
        }
    }

    if (st.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
}


int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int t;
    cin >> t;

    string input;
    while (t--)
    {
        cin >> input;
        solve(input);
    }

    return 0;
}