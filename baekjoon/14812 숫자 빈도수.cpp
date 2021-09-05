/*  2021-08-31  4:58
���� 14812�� ���� �󵵼�   ||  �ǹ�5
https://www.acmicpc.net/problem/14812



... �ð����⵵�� �� �� ����Ͽ� �ð��� ������ �� �˰� �����ɸ��� �Ǿ���.

�˰��� ��� :
 - �־��� n�� ���Ͽ� (1 ~ n) ������ d�� ��� �������� ����ȴ�. - (��, ���Ʈ����.)

���۽ð� : 12:09
����ð� : 12:19       �ɸ��ð� : 9��  ||  ����Ƚ�� : 1ȸ
*/


#include <iostream>

using namespace std;

void divide(int& result, int num, int& d);
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);


	int n, d;
	cin >> n >> d;


	// solve();
	int result = 0;
	for (int i = 1; i <= n; i++)
		divide(result, i, d);

	cout << result;

	return 0;
}


void divide(int& result, int num, int& d)
{
	while (num)
	{
		cout << num << "\n";
		if (num % 10 == d)
			result++;

		num /= 10;
	}
}