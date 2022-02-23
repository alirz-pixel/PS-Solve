/* 2022-02-23  11:27
���� 15649�� N�� M(1) || �ǹ� 3
https://www.acmicpc.net/problem/45649


�о� : [��Ʈ��ŷ]


���۽ð� : 11:27
����ð� : 11:42  || �� �õ�Ƚ�� : 1��,  ** (����)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> v;
void _loop(vector<int> bT, int N, int M, int loopCnt, int cnt) {
    if (loopCnt == M) {
        for (auto i : bT) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (!v[i]) {
            v[i] = true;
            bT[loopCnt] = i+1;
            _loop(bT, N, M, loopCnt+1, i+1);
            v[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    v = vector<bool>(M);
    vector<int> bT(M);
    _loop(bT, N, M, 0, 0);

    return 0;
}