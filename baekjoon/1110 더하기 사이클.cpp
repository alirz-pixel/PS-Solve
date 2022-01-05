/*  2021-08-25  1:27
���� 1110�� ���ϱ� ����Ŭ || �����1
https://www.acmicpc.net/problem/1110


������ ���������� ������ ����� ���� �ʰ� Ǯ�ٰ�
'�־��� ���� 10���� �۴ٸ� �տ� 0�� �ٿ� �� �ڸ� ���� �����'
�κ��� �ݺ����� �߰��Ͽ� 18���̳� �ɸ��� �Ǿ���.



���۽ð� - 20:12
����ð� - 20:30       �ɸ��ð� : 18��  ||  ����Ƚ�� : 1ȸ
*/


#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int startN, N, temp, cnt = 0;
    cin >> N;
    if (N < 10)
        N *= 10;

    startN = N;
    do {
        temp = N % 10;

        N = (temp * 10) + (((N / 10) + temp) % 10);
        cnt++;
    } while (startN != N);

    cout << cnt;

    return 0;
}





// ---- [ ���� Ǯ�� ] ----
// 2021-08-22  8:36

// .. ������ ����� ���� �ʰ� Ǯ� �����Ÿ��� �� ���� �ߴ�..

// ���۽ð� : 1:27
// ����ð� : 1:42       �ɸ��ð� : 15��  ||  ����Ƚ�� : 1ȸ


// #include <iostream>

// using namespace std;

// void cycle(int& n);
// int main(void)
// {
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     cout.tie(0);


//     int n, tempN, cnt = 0;
//     cin >> n;
    
//     tempN = n;
//     do
//     {

//         cnt++;
//         cycle(n);

//     } while(tempN != n);

//     cout << cnt;
//     return 0;
// }


// void cycle(int& n)
// {
//     int sum = 0, temp = n % 10;

//     if (n < 10)
//     {
//         temp = n;
//         n *= 10;
//     }

//     while(n)
//     {
//         sum += n % 10;
//         n /= 10;
//     }

//     n = sum%10 + (temp*10);
//     return;
// }