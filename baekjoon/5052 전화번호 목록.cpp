/*
���� 5052 ��ȭ��ȣ ��� || ���4
https://www.acmicpc.net/problem/5052


�ϰ����� �Ǵ��ϱ� ���� ���ξ�鿡 ���ؼ�
table�� ���� ������Ʈ���ָ鼭
KMP�� ���� Ž�� ��Ű�� �� ���̶� �Ǵ�.

�㳪, �׳� �ε��� �ϳ��ϳ� ���ϴ°Ŷ� �ٸ� ���� ���ٰ� ������ ��
(���λ縸 �Ǻ��ϹǷ�)

�׷��� ���ͳݿ� �˻��Ͽ� Ǯ�̸� ���Ҵµ� �ű⼱
set�� �̿��� ���λ縦 ��� set�� ��Ͻ�Ű�� ����� �����.



���۽ð� 10:18
����ð� **:**
*/


#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    bool result;
    int t;
    cin >> t;

    while (t--)
    {
        result = false;
        int n;
        cin >> n;

        vector<pair<int, string>> input(n);
        for (int i = 0; i < n; i++)
        {
            cin >> input[i].second;
            input[i].first = input[i].second.size();
        }

        sort(input.begin(), input.end());
        
        unordered_set<string> s;
        s.insert(input[0].second);

        for (int i = 1; i < n; i++)
        {
            string temp;
            
            for (int j = 0; j < input[i].first; j++)
            {
                temp += input[i].second[j];
                if (s.find(temp) != s.end())
                {
                    result = true;
                    cout << "NO\n";
                    break;
                }
            }

            if (result)
                break;

            s.insert(temp);
        }

        if (!result)
            cout << "YES\n";
    }

    return 0;
}