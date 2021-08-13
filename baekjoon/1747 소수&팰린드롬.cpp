/*
���� 1747 �Ҽ�&�Ӹ���� || ���5
https://www.acmicpc.net/problem/1747



������ Ǯ�� ��, ������ �ؾ��ϴ� ī������ ����
���� Ǫ�µ� �ɸ��ð��� å���Ҽ��� ���� �Ǿ���.

�׸��� ���� �˻��� �̸� ���� �����Ͽ� ������ ����������,
MAX���� 100000���� �����س��
�Է°��� 1000000���� �־����ٸ�, Ʋ�Ƚ��ϴٰ� ���� ���̴�.

���۽ð� 8:40
����ð� 9:27    �ɸ��ð� 47��  ||  �õ�Ƚ�� 1ȸ
*/



#include <iostream>
#include <vector>
const int MAX = 2000000;

using namespace std;

bool same(int n);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    vector<int> prime;
    vector<bool> prime_Check(MAX);
    for (int i = 2; i * i < MAX; i++)
    {
        if (prime_Check[i])
            continue;

        for (long long int j = i * i; j < MAX; j += i)
            prime_Check[j] = true;
    }

    for (int i = 2; i < MAX; i++)
        if (!prime_Check[i])
            prime.push_back(i);

    int n;
    cin >> n;

    for (int i = 0; i < prime.size(); i++)
    {
        if (prime[i] >= n && same(prime[i]))
        {
            cout << prime[i];
            break;
        }
    }

    return 0;
}


bool same(int n)
{
    int temp = 0, nTmp = n;
    
    while(n != 0)
    {
        temp *= 10;
        temp += n % 10;

        n /= 10;
    }

    if (temp == nTmp)  
        return true;

    return false;
}