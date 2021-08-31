/*  2021-08-31  4:58
���� 1197�� �ּ� ���д� Ʈ��  ||  ���4
https://www.acmicpc.net/problem/1197




ũ�罺Į �˰����� �ڵ� ¥�⿡ ���Ͽ�
�����ε� �ּ� ���д� Ʈ���� ���õ� ������ ������
�� �˰������� © �����̴�.


   

���۽ð� : 4:58
����ð� : 5:08       �ɸ��ð� : 10��  ||  ����Ƚ�� : 1ȸ
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int find(vector<int>& parent, int x);
bool _union(vector<int>& parent, int a, int b);
ll spanning(vector<pair<ll, pair<int, int>>>& edge, int v, int e);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int v, e;
    cin >> v >> e;

    vector<pair<ll, pair<int, int>>> edge(e);
    for (auto &i : edge)
        cin >> i.second.first >> i.second.second >> i.first;

    sort(edge.begin(), edge.end());

    //solve();
    cout << spanning(edge, v, e);

    return 0;
}


int find(vector<int>& parent, int x)
{
    if (parent[x] == x)
        return x;
    
    return parent[x] = find(parent, parent[x]);
}

bool _union(vector<int>& parent, int a, int b)
{
    int x = find(parent, a);
    int y = find(parent, b);

    if (x == y)
        return false;

    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;

    return true;
}   

ll spanning(vector<pair<ll, pair<int, int>>>& edge, int v, int e)
{
    // init();
    vector<int> parent(v+1);
    for (int i = 1; i <= v; i++)
        parent[i] = i;


    ll result = 0;
    for (auto i : edge)
    {
        if (!_union(parent, i.second.first, i.second.second))
            continue;

        result += i.first;
    }

    return result;
}
