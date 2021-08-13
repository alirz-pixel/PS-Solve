/*
���� 1976�� ���� ���� || ���4
https://www.acmicpc.net/problem/1976



���Ͽ� ���ε� �˰����� �̿��� ������ ã�Ƽ� Ǯ���� ������
�׷��� ����� ���� ������ Ǯ �� �־��� �� ����.

���࿡ �� ������ ���� �˰��� �з��� ���� �ʰ� ������ Ǯ���ٸ�,
�׷��� �˰������� Ǯ���� ���ɼ��� Ŀ���δ�.


���۽ð� 9:21
����ð� 9:36    �ɸ��ð� : 15��  ||  �õ�Ƚ�� : 1ȸ
*/


#include <iostream>
#include <vector>

using namespace std;

vector<int> rank_;

int find(vector<int>& parent, int x);
void union_(vector<int>& parent, int a, int b);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, m, temp;
    cin >> n >> m;

    vector<int> parent(n + 1);
    rank_ = vector<int>(n + 1, 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;


    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> temp;

            if (temp)
                union_(parent, i, j);
        }

    bool result = true;
    int same;

    cin >> temp;
    same = find(parent, temp);
    for (int i = 2; i <= m; i++)
    {
        cin >> temp;

        if (same != find(parent, temp))
            result = false;
    }

    if (result)
        cout << "YES";
    else 
        cout << "NO";


    return 0;
}


int find(vector<int>& parent, int x)
{
    if (parent[x] == x)
        return x;

    parent[x] = find(parent, parent[x]);
    return parent[x];
}

void union_(vector<int>& parent, int a, int b)
{
    int x = find(parent, a);
    int y = find(parent, b);

    if (x == y)
        return;

    if (rank_[x] < rank_[y])
    {
        parent[x] = y;
        rank_[y] += rank_[x];
    }
    else
    {
        parent[y] = x;
        rank_[x] += rank_[y];
    }
}