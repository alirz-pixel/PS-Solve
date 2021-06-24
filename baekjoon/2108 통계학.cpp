/*
���� 2108�� �����  || �ǹ� 4
https://www.acmicpc.net/problem/2108

�� ������ ���� 
cin.tie(NULL);
ios::sync_with_stdio(false);
cout.tie(NULL); �� �ð��� ���� �ٿ��شٴ� ���� �˰ԵǾ�����,

map�� �������� �ð��� ���� ��ƸԴ´ٴ� �� ���� �˰ԵǾ���.


���۽ð� : 11:01
����ð� : 12:00 -> �� ����Ƚ�� 2ȸ, �ɸ��ð� 59��
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

#define MAX 400001

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int average = 0, middle = 0, many = 0, range = 0;
    int N, max = -4001, min = 4001, many_max = 0, many_count = 0, many_cnt = 0;
    cin >> N;

    vector<int> cnt(8002);
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        average += arr[i];

        cnt[arr[i] + 4000]++;

        if (max < arr[i])
            max = arr[i];

        if (min > arr[i])
            min = arr[i];

        if (many_max < cnt[arr[i] + 4000])
        {
            many_max = cnt[arr[i] + 4000];
            many_cnt = 0; // �ֺ���� ����
        }

        if (many_max == cnt[arr[i] + 4000])
            many_cnt++;
    }

    sort(arr.begin(), arr.end());

    // ��ձ��ϱ�
    average = floor((average / (float)N) + 0.5);
    cout << average << "\n";

    // �߾Ӱ� ���ϱ�
    middle = arr[N / 2];
    cout << middle << "\n";

    // �ֺ� ���ϱ�
    if (N == 1)
        cout << arr[0] << "\n";

    else
    {
        for (int i = 0; i < N; i += cnt[arr[i] + 4000])
        {
            if (cnt[arr[i] + 4000] == many_max)
            {
                if (many_count == 1 || many_cnt == 1)
                {
                    cout << arr[i] << "\n";
                    break;
                }

                else
                    many_count++;                
            }
        }
    }
    
    
    // ���� ���ϱ�
    range = max - min;
    cout << range;

    return 0;
}