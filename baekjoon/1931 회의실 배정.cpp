/*
���� 1931�� ȸ�ǽ� ���� || �ǹ� 2
https://www.acmicpc.net/problem/1931

���� �˰��� �з� : �׸��� �˰���
vector<pair<int, int>> �� �̿��Ͽ�, sort�� ��
BFS�� ���Ʈ���� ������ �� �� ������


�ᱹ �𸣰ھ ������ ã�ƺôµ�,
�������� �ʹ� �����ؼ� ���� ���� ������;;

���� �Ϸ��� ����� ȸ�� ���۽ð��� ������ �Ŀ� �߰����� ������ ����, �ִ� ȸ�Ǽ��� �����ϴ� ���̾�����
https://jaimemin.tistory.com/391   || ���⼭ ã�� �ڷ�δ� ȸ�� ����ð��� ������ �Ŀ�, �� �ڿ� ���� �������� ȸ�� ���� �ð��� ã���� �ִ� ȸ�Ǽ��� ã����
�����ϰ� Ǯ �� �־��� ��������..

------------------------------------------------
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int N, begin, end, cnt = 1;
    cin >> N;

    vector<pair<int, int>> meet(N);
    for (int i = 0; i < N; i++)
        cin >> meet[i].second >> meet[i].first;

    sort(meet.begin(), meet.end()); //ȸ�ǰ� ���� ������ �ð����� ����


    end = meet[0].first; // ȸ�� �ѹ� ����
    for (int i = 1; i < N; i++)
        if (end <= meet[i].second)
        {
            end = meet[i].first;
            cnt++;
        }
    
    cout << cnt;
    return 0;
}