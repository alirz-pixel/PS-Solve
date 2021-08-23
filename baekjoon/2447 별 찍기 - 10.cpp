/*  2021-08-22  8:36
���� 2447�� �� ��� - 10 || �ǹ�1
https://www.acmicpc.net/problem/2



�������� �������������� Ǯ������,
�������� �� �з��� Ǯ�������� �ڵ带 �� ������ Ǭ ���� �ƽ���..


���۽ð� : 6:29
����ð� : 6:59     �ɸ��ð� : �뷫 30��  ||  ����Ƚ�� : 1ȸ
*/



#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> output;

void divide(int n, int x, int y, int size);
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	output = vector<vector<char>>(n, vector<char>(n));

	// �ɰ��� ����

	divide(n, 0, 0, n);

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
			cout << output[y][x];
		cout << "\n";
	}
	return 0;
}


void divide(int n, int x, int y, int size)
{
	if (size == 0)
		return;

	if (size == 3)
	{
		for (int tmpY = y; tmpY < y + size; tmpY++)
			for (int tmpX = x; tmpX < x + size; tmpX++)
				output[tmpY][tmpX] = '*';

		// ��� �� ���� �����ϱ�
		output[y + 1][x + 1] = ' ';

		return;
	}

	// ����� 3�� �ƴ϶��
	// 9 �������� ����
	divide(n, x, y, size / 3);
	divide(n, x + (size / 3), y, (size / 3));
	divide(n, x + ((size / 3) * 2), y, (size / 3));


	divide(n, x, y + (size / 3), (size / 3));
	// ��� �� ���� ä���
	for (int i = y+(size/3); i < (y+(size/3)) + (size / 3); i++)
		for (int j = x+(size/3); j < (x+(size/3)) + (size / 3); j++)
			output[i][j] = ' ';
	divide(n, x + ((size / 3) * 2), y + (size / 3), (size / 3));


	divide(n, x, y + ((size / 3) * 2), (size / 3));
	divide(n, x + (size / 3), y + ((size / 3) * 2), (size / 3));
	divide(n, x + ((size / 3) * 2), y + ((size / 3) * 2), (size / 3));

	return;
}