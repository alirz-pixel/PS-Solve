/*  2021-08-22  8:36
���� 2887�� �༺ �ͳ� || ���1
https://www.acmicpc.net/problem/2887



(���Ͽ� ���ε� �� �ּ� ���д� Ʈ��[ũ�罺Į])
�ּ� ���д� Ʈ���� ���� ��, min( [x, y, z] �� �� )�� �̿��ؾ� �����Ƿ�
X, Y, Z �� ������ ���� �����صξ��ٰ� �����Ͽ� ���� min �κ��� ������ ���Ͽ���.

�� ���Ĵ� �ּ� ���д� Ʈ���� �˰����� �״�� ����Ͽ���.



���۽ð� : 3:01
����ð� : 3:39      �ɸ��ð� : �뷫 38��  ||  ����Ƚ�� : 1ȸ
*/



#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int find(vector<int>& parent, int x);
bool union_(vector<int>& parent, int a, int b);
void solve(vector<pair<long long int, pair<int, int>>>& edge, vector<int>& parent, int n);
int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int n, x, y, z;
    cin >> n;


    //���Ͽ� ���ε� ����
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // �Է¹ޱ�
    vector<pair<long long int, int>> inputX(n), inputY(n), inputZ(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;

        inputX[i] = { x, i };
        inputY[i] = { y, i };
        inputZ[i] = { z, i };
    }

    sort(inputX.begin(), inputX.end());
    sort(inputY.begin(), inputY.end());
    sort(inputZ.begin(), inputZ.end());


    // �༺ ���� �Ÿ��� ���� �͵� ���ϱ�
    vector<pair<long long int, pair<int, int>>> edge;
    for (int i = 0; i < n-1; i++)
    {
        edge.push_back({abs(inputX[i].first-inputX[i+1].first), {inputX[i].second, inputX[i+1].second}});
        edge.push_back({abs(inputY[i].first-inputY[i+1].first), {inputY[i].second, inputY[i+1].second}});
        edge.push_back({abs(inputZ[i].first-inputZ[i+1].first), {inputZ[i].second, inputZ[i+1].second}});
    }

    sort(edge.begin(), edge.end());
    solve(edge, parent, n);

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
        return false;

    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;

    return true;
}

void solve(vector<pair<long long int, pair<int, int>>>& edge, vector<int>& parent, int n)
{   
    long long int cost, result = 0;
    pair<int, int> vertex;
    for (int top = 0; top < edge.size(); top++)
    {
        cost = edge[top].first;
        vertex = edge[top].second;

        // ����Ŭ�� �������� �ʴ´ٸ�
        if (union_(parent, vertex.first, vertex.second))
            result += cost;
    }

    cout << result;
}