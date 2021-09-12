/*  2021-09-12  1:31
���� 1744�� �� ����  ||  ���4
https://www.acmicpc.net/problem/1744


Ʋ�Ƚ��ϴ� 1:
 - ó������ �Է°��� ������ �Ŀ� �տ������� ���� üũ�ϸ�
   { (�� ���� ���) * (�� ���� ���) = ��� } ���ϰ�,
   { �ƴ� ��� } �� ���� ��Ҹ� ���ذ��� �������� ¥�� �Ǿ���.

   Ʋ������ :
     ������ ���ؼ� �ݷʰ� ���� �����Ͽ� (������ ���� ���ϱ��� �ִ��� ������������ �ؾ���.)
     Ʋ���� �Ǿ���.


Ʋ�Ƚ��ϴ� 2:
 - ���/������ ������ �ٸ��� �ؾ� �ȴٴ� ���� ���ݰ�, 
   {negative, positive} �迭�� ���εּ� ������ �Ͽ� Ǯ����.
   
   Ʋ������ :
     ����� �������� {�� ��/�� ���� ���} �� �ϳ��� 1�� ���� ������
     �������� ������ �� ũ�ٴ� �� ������ Ʋ���� �Ǿ���.


Ʋ�Ƚ��ϴ� 3:
 - ���� ���̽����� �� ���� ó���Ͽ�����, ����� �̹����� "Ʋ�Ƚ��ϴ�.."
   �̹��� ������ ��ã�ھ ���� �˻��� ���� Ʋ������ �����̾����� Ȯ���Ͽ���.

   Ʋ������ :
    ������ �������� ������� �ƴ� 0�� ���� ���ؼ��� ����� �ʿ䰡 �־���.
	(������ ���� < 0 �̹Ƿ�)
	 

���۽ð� : 1:31
����ð� : 1:50    ����õ� : 4ȸ  ||  �ɸ��ð� : 30��?
*/



#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);


	int n, temp;
	cin >> n;

	vector<int> positive, negative;
	while (n--)
	{
		cin >> temp;

		if (temp > 0)
			positive.push_back(temp);

		else
			negative.push_back(temp);
	}


	// solve();
	sort(positive.begin(), positive.end(), less<int>());
	sort(negative.begin(), negative.end(), greater<int>());

	int ans = 0, back;
	while (!positive.empty())
	{
		back = positive.back();
		positive.pop_back();

		if (positive.empty())
		{
			ans += back;
			break;
		}

		if (back != 1 && positive.back() != 1)
		{
			ans += (back * positive.back());
			positive.pop_back();
		}

		else
			ans += back;
	}

	while (!negative.empty())
	{
		back = negative.back();
		negative.pop_back();

		if (negative.empty())
		{
			ans += back;
			break;
		}

		if (back * negative.back() >= 0)
		{
			ans += (back * negative.back());
			negative.pop_back();
		}

		else
			ans += back;
	}

	cout << ans;
	return 0;
}