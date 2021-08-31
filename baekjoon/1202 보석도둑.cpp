/*  2021-09-01  8:15
���� 1202�� �ּ� ���д� Ʈ��  ||  ���4
https://www.acmicpc.net/problem/1202




step 1. ������ �������� ������ ���Ը� �������� �������� �����Ѵ�.
        (�켱���� ť�� ����)
step 2. ���濡 ���� �� �ִ� �ִ� ���Ը� ������������ �����Ѵ�.

step 3. ���� ������ �ִ� ���� �� �ִ� ������ ���Ը� ���� �ʴ� �ѿ��� 
        (��������)�켱���� ť�� ������ �ϳ��� ���鼭 ���ο� �켱���� ť�� �����Ѵ�.
step 4. (3)�� ������ ���� ��, ���� ��� ������ ��⵵�� ���ο� �켱���� ť���� ��� �ϳ� �� �Ŀ� result�� �־��ش�.


���۽ð� : 8:17
����ð� : 8:40       �ɸ��ð� : 23��  ||  ����Ƚ�� : 2ȸ
*/


#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void solve(vector<int>& bag, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq_dia);
int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.tie(0);


  int n, k;
  cin >> n >> k;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_dia;
  pair<int, int> input_dia;
  for (int i = 0; i < n; i++)
  {
    cin >> input_dia.first >> input_dia.second;
    pq_dia.push(input_dia);
  }

  vector<int> bag(k);
  for (int i = 0; i < k; i++)
    cin >> bag[i];

  sort(bag.begin(), bag.end());

  solve(bag, pq_dia);

  return 0;
}


void solve(vector<int>& bag, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq_dia)
{
  priority_queue<int> pq;
  long long result = 0;

  for (auto i : bag)
  {
    while(!pq_dia.empty())
    {
      if (pq_dia.top().first > i)
        break;
      pq.push(pq_dia.top().second);
      pq_dia.pop();
    }

    if (pq.empty())
      continue;

    result += pq.top();
    pq.pop();
  }

  cout << result;
}