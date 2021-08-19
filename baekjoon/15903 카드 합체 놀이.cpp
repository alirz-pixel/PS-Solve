/*  2021-08-20  1:26
���� 15903�� ī�� ��ü ���� || �ǹ�2
https://www.acmicpc.net/problem/15903



result ������, card1/card2 �� �������� long long int�� ���� �ʾ�
1�� �õ����� Ʋ���� �Ǿ���..

�˰��� ��ü�� �켱���� ť�� ���ٰ� ���� ��, �־��ٰ��� �ݺ��ϸ�
ī�带 ��ü�ϴ� ������� �����ߴ�.


���۽ð� 1:26
����ð� 1:43     �ɸ��ð� : 17��  ||  �õ�Ƚ�� : 2ȸ
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using LL = long long int;
using PQ = priority_queue<long long int, vector<long long int>, greater<long long int>>;

void solve(PQ& pq, int n, int m);
void cardFusion(PQ& pq, int m);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, m, temp;
    cin >> n >> m;

    PQ pq;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        pq.push(temp);
    }


    solve(pq, n, m);
    return 0;
}


void solve(PQ& pq, int n, int m)
{
    cardFusion(pq, m);

    LL result = 0;
    while(!pq.empty())
    {
        result += pq.top();
        pq.pop();
    }

    cout << result;
}

void cardFusion(PQ& pq, int m)
{
    LL card1, card2;
    for (int i = 0; i < m; i++)
    {
        card1 = pq.top();
        pq.pop();

        card2 = pq.top();
        pq.pop();

        pq.push(card1 + card2);
        pq.push(card1 + card2);
    }
}