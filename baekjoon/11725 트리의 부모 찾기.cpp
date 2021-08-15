/*
���� 11725�� Ʈ���� �θ� ã�� || �ǹ�2
https://www.acmicpc.net/problem/11725



���Ͽ� ���ε�� Ǯ��� ������,
������ �������� �ʾ� BFS�� Ž���ϸ�

�θ� �����ϸ� Ǯ����.
(���ͳ� �˻��� �غ���, ���Ͽ� ���ε�� Ǭ ����� ������..)

���۽ð� 8:36
����ð� 8:43   �ɸ��ð� : 13��  ||  �õ�Ƚ�� : 1ȸ
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>>& graph, int num);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, v1, v2;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    BFS(graph, n);

    return 0;
}


void BFS(vector<vector<int>>& graph, int num)
{
    vector<int> parent(num + 1);
    vector<bool> v(num + 1);
    queue<int> q;

    q.push(1);
    v[1] = true;

    int front;
    while(!q.empty())
    {
        front = q.front();
        q.pop();


        for (auto i : graph[front])
            if (!v[i])
            {
                q.push(i);
                v[i] = true;

                parent[i] = front;
            }
    }

    for(int i = 2; i <= num; i++)
        cout << parent[i] << "\n";
}