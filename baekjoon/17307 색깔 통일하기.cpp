/*  2021-08-31  4:58
���� 17307�� ���� �����ϱ�   ||  ���2
https://www.acmicpc.net/problem/17307


�˰��� ��� :

�پ��ִ� ���鿡 ���� ������ ��� �ٲ���ϴ� ���� ����ġ�� �ΰ� ���� �׷����� �����.
�׸��� �� ����ġ�� ���� ������ �˰����� �̿��� �ִ� ��θ� ���� ���̴�.

�켱 1��°���� �����Ͽ� n��°�� ���� ����ġ���� ��� ���Ѵ�.
(������ init)

�׸��� 2��°���ʹ� max('2->1'�� ���� �ִܰ��, '2->n'���� ���� �ִܰ��)�� ��� ����ϸ鼭
�� ���� ���� ���� ���� ������� �������� �ȴ�.



���۽ð� : 2:40
����ð� : ?:??       �ɸ��ð� : �뷫 105��  ||  ����Ƚ�� : 4ȸ
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);


	int n, k;
	cin >> n >> k;

	vector<int> button(n);
	for (auto& i : button)
		cin >> i;


	// solve();

	// first : ����, second : ������
	vector<pair<int, int>> graph(n);
	graph[n - 1].second = -1;

	graph[0].first = graph[n - 1].second = 0;
	// �׷��� ����
	for (int i = 0; i < n - 1; i++)
	{
		int nextChange = button[i] - button[i + 1];
		if (nextChange > 0)
			nextChange = k - nextChange;
		else
			nextChange *= -1;


		graph[i].second = nextChange;
		graph[i + 1].first = (k - nextChange)%k;
	}

	// ���� �� ����
	long long temp[2] = { 0, };
	for (int i = 0; i < n; i++)
		temp[0] += graph[i].second;

	// ���� �� solve()
	long long minIndex = 1, min = temp[0], now;
	for (int i = 1; i < n; i++)
	{
		temp[0] -= graph[i - 1].second;
		temp[1] += graph[i].first;

		now = max(temp[0], temp[1]);
		if (min > now)
		{
			min = now;
			minIndex = i+1;
		}
	}

	cout << minIndex << "\n" << min;
	return 0;
}