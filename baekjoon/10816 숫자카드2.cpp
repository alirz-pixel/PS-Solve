/*
���� 10816�� ���� ī�� 2  || �ǹ� 4
https://www.acmicpc.net/problem/10816

���� �ð� : 5:15
���� �ð� : 5:21
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> cnt(20000002);

    int N, M, temp;
    cin >> N;   

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        cnt[temp + 10000000]++;
    }


    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        cout << cnt[temp + 10000000] << " ";
    }

    return 0;
}