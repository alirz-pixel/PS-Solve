/*  2021-09-01  8:29
���� 7578�� ����  ||  �÷�Ƽ��5
https://www.acmicpc.net/problem/7578



���׸�Ʈ Ʈ���� ������ Ǯ�� �; ���� ������ ���� �Ǿ���.
������ ���׸�Ʈ Ʈ���� ���� ���ط��� �����ʾ� ���ͳ��� �� �����ϰ� �Ǿ���.

lineA�� ��ȸ�ϸ鼭 lineB�� ��� ������ �� �Ǵ��ؾ� �ϴµ�,
�� �κп��� N^2 -> N * log N -> N �̷������� ���İ��� 3���̳� Ʋ���� �Ǿ���.


�׸��� lineB���� lineA�� ���� ���� ã�Ҵٸ�, ���׸�Ʈ Ʈ���� �� �ε����� ����
1�� ������ְ� j+1 ~ n���� Ž���ϸ鼭 1�� ������ ���ָ� �Ǵ� ���̴�.

   

���۽ð� : 8:30
����ð� : 9:00       �ɸ��ð� : 30��  ||  ����Ƚ�� : 3ȸ
*/


#include <iostream>
#include <vector>

using namespace std;

struct seg {
	int n;
	using _T = int;
	vector<_T> S;
	_T(*op)(_T, _T);
	_T e;
	seg(const vector<_T>& A, _T(*op)(_T, _T), _T e) :op(op), e(e) {
		n = A.size();
		S.resize(4 * n);
		init(A, 0, n - 1, 1);
	}
	_T init(const vector<_T>& A, int nodeleft, int noderight, int node) {
		if (nodeleft == noderight) {
			return S[node] = A[nodeleft];
		}
		int mid = (nodeleft + noderight) / 2;
		return S[node] = op(init(A, nodeleft, mid, node * 2),
			init(A, mid + 1, noderight, node * 2 + 1));
	}

	_T query(int left, int right, int node, int nodeleft, int noderight) {
		if (right < nodeleft || noderight < left) return e;
		if (left <= nodeleft && noderight <= right) return S[node];

		int mid = (nodeleft + noderight) / 2;
		return op(query(left, right, node * 2, nodeleft, mid),
			query(left, right, node * 2 + 1, mid + 1, noderight));
	}
	_T query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}
	void update(int index, _T newvalue, int node, int nodeleft, int noderight) {
		if (index < nodeleft || noderight < index) return;
		if (nodeleft == noderight) {
			S[node] = newvalue;
			return;
		}
		int mid = (nodeleft + noderight) / 2;
		update(index, newvalue, node * 2, nodeleft, mid);
		update(index, newvalue, node * 2 + 1, mid + 1, noderight);
		S[node] = op(S[node * 2], S[node * 2 + 1]);
	}
	void update(int index, _T newvalue) {
		update(index, newvalue, 1, 0, n - 1);
	}
};


int add(int a, int b) {
    return a + b;
}


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    // input();
    int n, temp;
    cin >> n;

    vector<int> lineA(n);
    for (auto &i : lineA)
        cin >> i;
    
    vector<int> lineB(1000001);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        lineB[temp] = i;
    }


    // solve();
    int j;
    long long result = 0;

    vector<int> connect(n, 0);
    seg segment(connect, add, 0);
    for (auto i : lineA)
    {
        j = lineB[i];
        segment.update(j, 1);

        if (j != n-1)
            result += segment.query(j+1, n-1);
    }

    cout << result;
    return 0;
}