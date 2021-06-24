/*
���� 10816�� ���� ī�� 2  || �ǹ� 4
https://www.acmicpc.net/problem/10816

���� �ð� : 5:25
���� �ð� : 5:35
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    vector<int>::iterator upper, lower;
    int N, M, temp;
    cin >> N;   

    vector<int> arr(N);
    for (auto& i : arr)
        cin >> i;

    sort(arr.begin(), arr.end());

    
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;

        lower = lower_bound(arr.begin(), arr.end(), temp);
        upper = upper_bound(arr.begin(), arr.end(), temp);

        cout << upper-lower << " ";
    }
    

    return 0;
}