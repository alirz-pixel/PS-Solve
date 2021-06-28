/*
���� 7662�� ���� �켱���� ť   || ��� 5
https://www.acmicpc.net/problem/7662

(ó������ �켱���� ť�� MAX HEAP, MIN HEAP �ΰ��� �����ؼ� ���������)
(�߰��� ������ �Ͼ��, �ٽ� ������ �Ͼ ���� �������� ���ؼ� Ʋ��)


�� ��, � �ڷᱸ���� ����ؾ��� �� ���� ���ͳ� �˻��� ���� �˰ԵǾ���
  �ߺ����� ����� �Ǵ� multiset�� �̿��Ͽ���, 
  �ִ� ������ --Se.end()
  �ּڰ� ������ Se.begin()

���� �ð�: 2:50
���� �ð�: 4:15  ||  �� �õ� Ƚ�� : 2ȸ, �ɸ� �ð� 1�ð� 25��
*/

#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int T, k;    char oper;   long long int n;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        multiset<long long int> Se;
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            cin >> oper >> n;
            
            if (oper == 'I')
                Se.insert(n);

            else if (Se.size() != 0)
            {
                if (n == 1) // max ����
                    Se.erase(--Se.end());

                else
                    Se.erase(Se.begin());
            }
        }

        if (Se.size() == 0)
            cout << "EMPTY\n";

        else
        {
            cout << *(--Se.end()) << " ";
            cout << *(Se.begin()) << "\n";
        }
    }

    return 0;
}


/*
for (int i = 0; i < 5; i++)
    {
        pq_MAX.push(i);
        pq_MIN.push(i);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << pq_MAX.top() << " ";
        pq_MAX.pop();
    }

    cout << endl;
    
    for (int i = 0; i < 5; i++)
    {
        priority_queue<int, vector<int>, greater<int>> pq_MIN;
        if (pq_MIN.empty())
            cout << "empty!" << " ";
        else
            cout << pq_MIN.top() << " ";
        pq_MIN.pop();
    }
*/