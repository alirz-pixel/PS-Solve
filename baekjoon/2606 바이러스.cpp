/*
���� 2606 ���̷��� || �ǹ�3
https://www.acmicpc.net/problem/2606


���� Ǯ�̿��� �� ������ �׷��� �̷� (BFS)�� �̿��Ͽ� Ǯ������.
�̹��� ���Ͽ� ���ε带 �н��ϰ� �Ǿ�, �̰��� ����Ͽ� Ǯ���µ�

���Ͽ� ���ε带 �н��� ��,
���Ͽ� �κп��� '�׷����� ���̰� ���� ���� -> �׷����� ���̰� ���� �������� �ٰ�' ������ �̾߱Ⱑ �־
�̷��� �����ؼ� ����������, �� ������
1�̶� ����� ����� ��Ʈ��尡 1�� ���;��ϱ� ������
�ڴʰ� ���Ͽ��� ��ġ�� ������ ���� �����Ͽ� �����Ͽ���.


���۽ð� 8:15
����ð� 8:34         �ɸ��ð� : 19��  ||  �õ�Ƚ�� : 3ȸ
*/



#include <iostream>
#include <vector>

using namespace std;


int find(vector<int>& parent, int a);
void union_(vector<int>& parent, int a, int b);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, m, v1, v2, cnt = 0;
    cin >> n >> m;

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;

        union_(parent, v1, v2);
    }
    
    for (int i = 2; i <= n; i++)
    {
        if (find(parent, i) == 1)
            cnt++;
    }
    cout << cnt;
    return 0;
}


int find(vector<int>& parent, int a)
{
    if (parent[a] == a)
        return a;

    parent[a] = find(parent, parent[a]);
    return parent[a];
}

void union_(vector<int>& parent, int a, int b)
{
    int x = find(parent, a);
    int y = find(parent, b);

    if (x == y)
        return;

    if (x > y)
        parent[x] = y;
    else   
        parent[y] = x;
    // if (rank_[x] >= rank_[y])
    // {
    //     parent[y] = x;
    //     rank_[x] += rank_[y];
    // }
    // else
    // {
    //     parent[x] = y;
    //     rank_[y] += rank_[x];
    // }
}