/*
���� 17298�� ��ū��  || ��� 4
https://www.acmicpc.net/problem/17298

���� A�� �־����� ��, �������� �Ǵ��ϸ�

DP�� �ϳ� ��������, ������ ��ū���� ���� �����ؾ��� ��

1. ����, ���� ���� ���� ������ ũ�ٸ�, ���� ���� ���ÿ� ����
2. ����, ���� ���� ���� ������ �۴ٸ�, DP�� �ϳ��� Ž���ϸ� ���� �� ���� ū ���� ã�´�.

(�� ��� ���̽��� ���� MAX���� �ϳ� �����صΰ� '-1' ó���� �� �͵� �����ؾ� �� ��)



��� : ����� ������ �̿��Ͽ� �迭 �� ���鼭 ����ϸ� �� ��



���� �ð� : 11:46
���� �ð� : 12:23, �� ����Ƚ�� : 2��  ||  �ɸ��ð� : 37�� 
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int N, MAX = 0;
    cin >> N;

    stack<int> st;
    vector<int> DP(N);
    vector<int> A(N);

    for (auto& i : A)
        cin >> i;

    
    st.push(-1);
    MAX = A[A.size() - 1];
    DP[A.size() - 1] = -1;
    for (int i = A.size() - 2; i >= 0; i--) // �� ���� ���� -1�� Ȯ���̹Ƿ�
    {  
        if (A[i] < A[i + 1])
        {
            if (MAX < A[i + 1])
                MAX = A[i + 1];

            st.push(A[i + 1]);
            DP[i] = A[i + 1];
        }


        else if (A[i] > A[i + 1]) // ���簪�� ���������� ū ���
        {
            if (A[i] >= MAX) // �� ���簪�� MAX�� ���� ū ���
            {
                MAX = A[i];
                DP[i] = -1;
                st.push(-1);
                continue;
            }

            for (int j = i + 1; j < A.size(); j++)
                if (A[i] < DP[j])
                {
                    st.push(DP[j]);
                    DP[i] = DP[j];
                    break;
                }
        }

        else // ���簪�� �������� ���� ���
        {
            DP[i] = DP[i + 1];
            st.push(DP[i + 1]);
        }
    }


    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}