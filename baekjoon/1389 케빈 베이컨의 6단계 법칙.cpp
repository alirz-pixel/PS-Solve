/*
���� 1389�� �ɺ� �������� 6�ܰ� ��Ģ || �ǹ� 1
https://www.acmicpc.net/problem/1389


�Է¿� ���� ������� �׷����� ���� ��, 
��� ���鿡 ���� lever order(ť �̿�)�� �ϵ� ť�� �� Ƚ���� cnt�� ���� �����ָ� 
�������� ���ϴ� ���� ���� ���̴�.

�׷����� ��������Ʈ�� ���� ����.
����) ģ�� ���谡 �ߺ��Ǿ ���� �� �����Ƿ�, �湮ó���� ����� �Ѵ�.


���۽ð� : 5:39
����ð� : 6:18,   �õ�Ƚ�� 1��  ||  �ҿ�ð� 40��
*/


#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int levelorder(vector<vector<int>>& graph, int N, int start);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    
    int min = 1234567891, min_Index = 101, temp;
    int N, M, V1, V2;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, 0)); //�ߺ� ģ�� ���踦 ó���ϱ� ���� �湮ó�� (2���� �迭)

    for (int i = 0; i < M; i++)
    {
        cin >> V1 >> V2;

        if (!visited[V1][V2])
        {    
            graph[V1].push_back(V2);
            graph[V2].push_back(V1);

            visited[V1][V2] = true;
            visited[V2][V1] = true;
        }
    }


    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    for (int i = 1; i <= N; i++)
    {
        temp = levelorder(graph, N, i);

        if (min > temp)
        {
            min = temp;
            min_Index = i;
        }
    }
        
    cout << min_Index;
    return 0;
}

int levelorder(vector<vector<int>>& graph, int N, int start)
{
    int cnt = 1, result = 0, size;
    vector<bool> visited(N + 1);
    queue<vector<int>> q;

    q.push(graph[start]);
    visited[start] = true;
    while (!q.empty())
    {
        size = q.size();
        for (int i = 0; i < size; i++)
        {
            for(auto i : q.front())
                if (!visited[i])
                {
                    q.push(graph[i]);
                    visited[i] = true;
                    result += cnt;
                }

            q.pop();
        }

        cnt++;
    }

    return result;
}

/*
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
            cout << i << " " << graph[i][j] << "\n";
        cout << "\n";
    }
*/