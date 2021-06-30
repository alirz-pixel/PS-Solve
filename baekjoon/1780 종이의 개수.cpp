/*
���� 1780�� ������ ���� || �ǹ� 2
https://www.acmicpc.net/problem/1780


����Լ��� �̿��Ͽ� '-1,  0, 1'�θ� ä���� ���̸� �Ǻ��Ѵ�.

�̷� ���� ���� ������ Ǯ ��,
�׻� ������ �κ��� startX, startY, endX, endY�� ���ϴ� �κп��� �������µ�
�̹��� ������� ����, for�� �̿��Ͽ� �� Ǯ���� �� ���� �ѵ��ϴ�.

�׸��� size�� 3�� ��, ��͸� �Ͽ� �ɰ��� ���� �ƴ� for������ �̿��ϸ�
�ð� ���⵵ ���鿡�� �̵��� �� �� �˾�����, ū ���̴� ������


���۽ð� : 3:49
����ð� : 4:19
*/


#include <iostream>

using namespace std;

short int arr[2187][2187];
void cut(int* result, int startX, int startY, int endX, int endY);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int N, result[3] = { 0, 0, 0 };
    cin >> N;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> arr[y][x];

    
    cut(result, 0, 0, N, N);


    for (int i = 0; i < 3; i++)
        cout << result[i] << "\n";
    return 0;
}

void cut(int* result, int startX, int startY, int endX, int endY)
{
    if (startX < 0 || startY < 0 || startX > endX || startY > endY)
        return;


    bool check = true;
    int size = endX - startX;

    for (int y = startY; y < endY; y++)
    {
        for (int x = startX; x < endX; x++)
            if (arr[y][x] != arr[startY][startX])
            {
                check = false;

                if (size == 3)
                {
                    cout << "size == 3";
                    break;
                }

                // 9���� �ɰ���
                int cut_X, cut_Y = startY, cut_Size = (size / 3);
                for (int i = 0; i < 3; i++)
                {
                    cut_X = startX;
                    for(int j = 0; j < 3; j++)
                    {
                        cut(result, cut_X, cut_Y, cut_X + cut_Size, cut_Y + cut_Size);
                        cut_X += cut_Size;
                    }

                    cut_Y += cut_Size;
                }

                break;
            }

        if (!check)
            break;
    }

    if (check)
        result[arr[startY][startX] + 1]++;

    else if (size == 3)
        for (int y = startY; y < endY; y++)
            for (int x = startX; x < endX; x++)
                result[arr[y][x] + 1]++;
}