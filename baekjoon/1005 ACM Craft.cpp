/*  2021-09-30  4:20
���� 1005�� ACM Craft  ||  ���3
https://www.acmicpc.net/problem/1005




����Բ��� �� ������ ���������� �̿��ؼ� Ǫ�� ������ �˷��ּż�
�������� �˰����� ó�� �˻��Ͽ� Ǯ��. (���������� �����ϴ� �ҽ��ڵ�� �������� �ʰ�, ������ Ǯ����.)

(���������� ����Ŭ�� �����ϴ� ��� ����� �� ����.)
���������� ������ ���� :
 ������ ���ǿ��� '�Ǽ������� ��� �ǹ��� �Ǽ� �����ϵ��� �־�����.' ��� ������ �ִµ�
 ����, ������ �Է¿��� ����Ŭ�� �����ϰ� �� ���
  X �ǹ��� Y �ǹ��� ���� ������ �Ǽ��� �����ϸ�,
  Y �ǹ��� X �ǹ��� ���� ������ �Ǽ��� �����ϴ�
 ��� ����� �߻��ϰ� �Ǿ� ����Ŭ�� ������ ���� ���� �Ǵ� ���̴�.


���۽ð� : 3:53
����ð� : 4:19     ����õ� : 1ȸ  ||  �ɸ��ð� : 26��
*/


#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort(vector<vector<int>>& graph, vector<int>& buildTime, vector<int>& connect, int n, int w);
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);


	int t, n, k, sv, ev, w;
	cin >> t;

	while (t--) {
		cin >> n >> k;

		vector<vector<int>> graph(n);
		vector<int> buildTime(n), connect(n);
		for (auto &i : buildTime)
			cin >> i;

		while (k--) {
			cin >> sv >> ev;
			sv--; ev--;

			// DAG �� ���������� ���� ����
			graph[sv].push_back(ev);
			connect[ev]++;
		}
		cin >> w;
		w--;

		topologicalSort(graph, buildTime, connect, n, w);
	}
	return 0;
}


void topologicalSort(vector<vector<int>>& graph, vector<int>& buildTime, vector<int>& connect, int n, int w)
{
	vector<int> creatTime(n);
	vector<bool> v(n);
	queue<int> q;

	for (int i = 0; i < n; i++)
		if (connect[i] == 0)
			q.push(i);

	int front;
	while (!q.empty()) {
		front = q.front();
		q.pop();

		if (v[front]) continue;
		v[front] = true;
		creatTime[front] += buildTime[front];

		for(auto i : graph[front]) {
			connect[i]--;
			creatTime[i] = max(creatTime[front], creatTime[i]);
		}

		for (int i = 0; i < n; i++)
			if (connect[i] == 0 && v[i] == false)
				q.push(i);
	}

	cout << creatTime[w] << "\n";
}