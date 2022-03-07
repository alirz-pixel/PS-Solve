// ���۽ð� | 15:07
// ����ð� | 15:43       [  �ɸ��ð� : 36�� | ����õ� : 2ȸ  ]

// cin.eof() �� �̼����� ����߳׿�..


#include <iostream>
#include <vector>

using namespace std;

// ���׸�Ʈ Ʈ��
vector<int> arr;
vector<int> seg;
 // �ʱ�ȭ
int init(int start, int end, int node) {
	if (start == end) return seg[node] = arr[start]; // leafnode �ʱ�ȭ
	int mid = (start + end) / 2;
	return seg[node] = init(start, mid, node * 2) * init(mid + 1, end, (node * 2) + 1); // ��,������ �ڽ��� ���� ���� node�� ���ذ��� ���׸�Ʈ Ʈ�� �ϼ�
}

 // ����
void update(int start, int end, int node, int index, int value) {
	if (index < start || end < index) return;  // ������ ����� ���
	if (start == end) {    // �����Ϸ��� index�� �� ���
		seg[node] = value; // ���׸�Ʈ Ʈ���� �ش��ϴ� index�� value�� ����
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, value); // ���� �ڽ� (start ~ mid)
	update(mid + 1, end, (node * 2) + 1, index, value); // ������ �ڽ� (mid+1 ~ end)
	seg[node] = seg[node * 2] * seg[(node * 2) + 1]; // ������ ����
}

 // ����
int query(int start, int end, int node, int nodeLeft, int nodeRight) {
	if (end < nodeLeft || nodeRight < start) return 1; // ������ ���Ե��� ���� ���, 1�� ���� (�����̹Ƿ�)
	if (nodeLeft <= start && end <= nodeRight) return seg[node]; // ������ ���Ե� ���, �̸� ���� ������ ����
	int mid = (start + end) / 2; 
	return query(start, mid, node * 2, nodeLeft, nodeRight) * query(mid + 1, end, (node * 2) + 1, nodeLeft, nodeRight);
}



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, c1, c2;
	char cmd;
	while (true) {
        cin >> N >> K;
        if (cin.eof() == true) break; // �Է��� ���� ���� ��, ���α׷��� ����ǵ��� ��.
        
		arr = vector<int>(N);
		seg = vector<int>(N * 4);

		// ���� �Է�
		for (auto& i : arr) {
			cin >> i;
			if (i < 0) {
				i = -1; // overflow ������ ���� ������ ���, -1�� ����
			} else if (i > 0) {
				i = 1;  // overflow ������ ���� ������ ���, 1�� ����
			}
		}


		// ���׸�Ʈ init;
		init(0, N - 1, 1);
		
		for (int i = 0; i < K; i++) {
			// Ŀ�ǵ�, { i, V } �Ǵ� { i, j }
			cin >> cmd >> c1 >> c2;
		
			// ����
			if (cmd == 'C') {
				c1--;
				if (c2 < 0) { // overflow ������ ���� ������ ���, -1�� ����
					c2 = -1;
				} else if (c2 > 0) {
					c2 = 1;   // overflow ������ ���� ����� ���, 1�� ����
				}
				update(0, N - 1, 1, c1, c2);
			} // ����
			else if (cmd == 'P') {
				c1--; c2--;  // index�� 0���� �����ϹǷ� left ~ right�� ������ �Է°����� �ϳ��� ���ܽ�����
				int result = query(0, N - 1, 1, c1, c2); // �������
				
				// ���
				if (result == 0) {
					cout << 0;
				} else if (result < 0) {
					cout << "-";
				} else {
					cout << "+";
				}
			}
		}

		cout << "\n";
	}
	return 0;
}