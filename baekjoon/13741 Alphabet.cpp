/*  2021-08-31  4:58
���� 13741�� Alphabet   ||  �ǹ�1
https://www.acmicpc.net/problem/13741




a~z�� �ǵ��� �ϴ� ���ڿ��� ������ �Ѵ�.
���⼭ �Է� �� ���� �ؾߵǴ� ������ �߿����� �����Ƿ�
�߰��ؾ� �ϴ� ���ĺ��� ���� LIS�� �̿��Ͽ� ���� �� �ִ�.
((a~z) ���̿� �̻��� �� ���ִٸ� �����ص� ������� ��)

LIS �˰����� �̿��Ͽ� �ִ� ���� �� �����ϴ� �κм����� ���ߴٸ�,
���� ���ĺ��� ������ 26 - max_LIS�� ���ָ� �ȴ�.


���۽ð� : 11:45
����ð� : 11:55       �ɸ��ð� : 10��  ||  ����Ƚ�� : 1ȸ
*/


#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);


	string input;
	cin >> input;

	// solve();
	vector<int> dp(input.size(), 0);
	int result = 0, LIS_Max;

	for (int i = 0; i < input.size(); i++)
	{
		LIS_Max = 0;
		for (int j = 0; j < i; j++)
		{
			if (input[i] > input[j])
				LIS_Max = max(LIS_Max, dp[j]);
		}

		dp[i] = LIS_Max + 1;

		if (dp[i] > result)
			result = dp[i];
	}

	cout << 26-result;
	return 0;
}