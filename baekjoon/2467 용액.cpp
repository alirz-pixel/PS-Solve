/*  2021-08-20  10:05
���� 2467�� ��� || ���5
https://www.acmicpc.net/problem/2467


ó������ N�� Mó�� ����Ž���� �ϸ� �� �� �˾�����,
�Է�ũ�Ⱑ 100,000�̶� �ȵ� ���̶� �Ǵ��Ͽ���.

�� �������� ������ ���� �������� �ε�,
�� �������͸� ����� �� sum�� 0�� �Ǵ� ��츦 ������� �ʾ�.
�ݺ����� ������� ���Ͽ� �ð��ʰ��� �ǹ��ȴ�......


���۽ð� 10:05
����ð� 10:24       �ɸ��ð� : 19��  ||  �õ�Ƚ�� : 2ȸ
*/



#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    vector<long long int> arr(n), result(2);
    for (auto &i : arr)
        cin >> i;

    
    int start = 0, end = arr.size()-1;
    long long int sum, tmpMin = arr[start] + arr[end];

    result[0] = arr[start];
    result[1] = arr[end];
    while (start < end)
    {
        sum = arr[start] + arr[end];
        
        if (abs(tmpMin) > abs(sum))
        {
            tmpMin = sum;
            result[0] = arr[start];
            result[1] = arr[end];
        }

        if (sum == 0)
            break;

        else if (sum > 0)
            end--;

        else if (sum < 0)
            start++;
    }

    
    cout << min(result[0], result[1]) << " " << max(result[0], result[1]);
    return 0;
}