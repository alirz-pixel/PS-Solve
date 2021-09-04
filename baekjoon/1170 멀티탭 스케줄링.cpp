/*  2021-09-04  11:47
���� 1170�� ��Ƽ�� �����ٸ�   ||  ���1
https://www.acmicpc.net/problem/1170


�˰��� ��� :

i) ���� �ʿ䰡 ����
 i-1] �̹� �����ִ� ���,
 i-2] �÷��װ� ����ִ� ���,

ii) �̾ƾ߸� �ϴ� ���, �ּ��� ������ �ؾ���
 ii-1] ������ ����� ���� ���� ��ǰ�� �̾ƾ���.
 ii-2] ������ ���� ��ǰ�� �� ���� ���߿� ����� ��ǰ�� �̾ƾ� ��.



���۽ð� : 11:47  
����ð� : ?:??       �ɸ��ð� : �뷫 105��  ||  ����Ƚ�� : 2ȸ
*/


#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);


	int n, k, temp;
	cin >> n >> k;

	vector<int> product(k+1);
	vector<int> input(k);
	for (int i = 0; i < k; i++)
	{
		cin >> input[i];
		product[input[i]]++;
	}

	// solve()
	vector<bool> isUse(k+1);
	int cnt = 0, result = 0;
	bool isContinue;
	for (int i = 0; i < k; i++)
	{
		isContinue = false;
		product[input[i]]--;

		// �̹� ��� ��
		if (isUse[input[i]] == true)
			continue;

		// �÷��װ� �������
		if (cnt != n)
		{
			isUse[input[i]] = true;
			cnt++;
			continue;
		}

		// ���� �ϳ� ������

		result++;

		// �� �̻� ������� ���� ��ǰ
		for (int j = 1; j <= k; j++)
			if (isUse[j] && !product[j])
			{
				isContinue = true;
				isUse[j] = false;
				isUse[input[i]] = true;
				break;
			}

		if (isContinue)
			continue;


		// �̹� �����ִ� ��ǰ�� �� (������) ����� ��ǰ�� �߿� ���� �������� ������ ��ǰ
		vector<int> lastpro(k+1);
		int maxIndex = 0;
		for (int j = i+1; j < k; j++)
			if (isUse[input[j]] && !lastpro[input[j]])
				lastpro[input[j]] = j;

		for (int j = 1; j <= k; j++)
			if (lastpro[j] > lastpro[maxIndex])
				maxIndex = j;

		isUse[maxIndex] = false;
		isUse[input[i]] = true;
	}

	cout << result;
	return 0;
}