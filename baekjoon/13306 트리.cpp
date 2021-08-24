/*  2021-08-22  8:36
���� 13306�� Ʈ�� || �÷�1
https://www.acmicpc.net/problem/13306




��ϴ��б� �˰��� Ư�� �ð��� �� ������ Ǫ�� �˰��� ���� ������ ���ּż�
����� �ʰ� ®�� �� ����.

�˾Ƴ� �� : 
  ������ 'input�� ���� = ������ ����'��� ������������
  input�� ������ ����� ������ �ϰ�, ����� ������ �ٽ� �ٲ㼭 Ǫ�� ����� �ִٴ� ���� �˰ԵǾ���.
  (�˰��� �з� : �������� ����)


���۽ð� : 7:40 
����ð� : 8:00     �ɸ��ð� : �뷫 20��  ||  ����Ƚ�� : 1ȸ
*/




#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int find(vector<int>& parent, int x);
bool union_(vector<int>& parent, int a, int b);
void solve(vector<int>& graph, stack<pair<int, pair<int, int>>>& st, int n, int q);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, q, command, v1, v2;
    cin >> n >> q;

    // n - input();
    vector<int> graph(n+1);
    graph[1] = 1;
    for (int i = 2; i <= n; i++)
        cin >> graph[i];        


    // q - input();
    stack<pair<int, pair<int, int>>> st;
    for (int i = 0; i < (n-1)+q; i++)
    {
        cin >> command;

        // ���� ����
        if  (command == 0)
        {
            cin >> v1;
            st.push( {command, { v1, -1 }} );
        }

        // ���� ����
        else if (command == 1)
        {
            cin >> v1 >> v2;
            st.push( {command, { v1, v2 }} );
        }
    }

    solve(graph, st, n, q);

    return 0;
}


int find(vector<int>& parent, int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent, parent[x]);
}

bool union_(vector<int>& parent, int a, int b)
{
    int x = find(parent, a);
    int y = find(parent, b);

    if (x == y)
        return true;

    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
    
    return false;
}

void solve(vector<int>& graph, stack<pair<int, pair<int, int>>>& st, int n, int q)
{
    stack<bool> result;

    // ���Ͽ� ���ε� init()
    vector<int> parent(n+1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int command;
    pair<int, int> vertex;
    while(!st.empty())
    {
        command = st.top().first;
        vertex = st.top().second;
        st.pop();

        // ���� ����
        if (command == 1)
        {
            if (find(parent, vertex.first) == find(parent, vertex.second))
                result.push(true);
            else
                result.push(false);
        }

        // ���� ����
        else
        {
            parent[vertex.first] = graph[vertex.first];
            find(parent, vertex.first);
        }
    }

    while(!result.empty())
    {
        if(result.top())
            cout << "YES\n";
        else
            cout << "NO\n";

        result.pop();
    }
}