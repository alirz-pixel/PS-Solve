/*
���� 16916 �κ� ���ڿ� || ���4
https://www.acmicpc.net/problem/16916


KMP �˰��� �н� ��, 
KMP �˰���� ���õ� ������ ã�� Ǯ�ԵǾ���.

(��, �˰��� �з��� �˰��ִ� ���¿��� ������ Ǯ��.)

���۽ð� 9:52
����ð� 9:57
*/



#include <iostream>
#include <vector>

using namespace std;

void make_table(vector<int>& p, const string& pattern);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    string input, pattern;
    cin >> input;
    cin >> pattern;

    vector<int> p(pattern.size(), 0);
    make_table(p, pattern);

    int j = 0;
    for (int i = 0; i < input.size(); i++)
    {
        while(j > 0 && input[i] != pattern[j])
            j = p[j-1];

        if (pattern[j] == input[i])
        {
            if (j == pattern.size() - 1)
            {
                cout << 1;
                return 0;
            }

            else
                j++;
        }
    }

    cout << 0;
    return 0;
}


void make_table(vector<int>& p, const string& pattern)
{
    int j = 0;
    for (int i = 1; i < pattern.size(); i++)
    {
        while(j > 0 && pattern[i] != pattern[j])
            j = p[j-1];

        if (pattern[i] == pattern[j])
            p[i] = ++j;
    }
}