/*
���� 1018�� ü���� �ٽ� ĥ�ϱ�  || �ǹ� 5
https://www.acmicpc.net/problem/1018

���� �ð� : 11:44
���� �ð� : 
*/

#include <algorithm>
#include <iostream>
#include <string>

#define MAX 50

using namespace std;


int check(int x, int y);
string chess[MAX];

int main(void)
{
    int N, M, temp, min = 65;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> chess[i];

    
    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            temp = check(j, i);

            if (min > temp)
                min = temp;
        }
    }

    cout << min;

    return 0;
}



int check(int x, int y)
{
    int cnt = 0;
    char WB = 'W';

    for (int i = y; i < y + 8; i++)
    {
        for (int j = x; j < x + 8; j++)
        {
            if (chess[i][j] != WB)
            {

                cnt++;
            }


            if (WB == 'W')
                WB = 'B';

            else
                WB = 'W';
        }

        if (WB == 'W')
            WB = 'B';

        else
            WB = 'W';
    }

    return min(cnt, 64 - cnt);
}