/*  2021-09-14  13:07
���� 11497 �볪�� �ǳʶٱ�  ||  �ǹ�1
https://www.acmicpc.net/problem/11497


�˰��� ��� :
 - �켱 �־��� ���� ������������ �����Ѵ�. (�迭 �̸� : height)
   �׸��� height�� n-1��° ���� �̿��Ͽ� �ʱ� ���̵��� �����Ѵ�. max(height[n-1] - height[n-2], height[n-1] - height[n-3]);

   ���� ������ ����� ���� ������ ������ ������ �̿��ϵ�,
   2���� ¦��� 1��°�� ��ť�� �� ��,
                 2��°�� ��ť�� �� �տ� �����Ͽ� ���̵��� å���Ѵ�.
				 
	��� height�� ������ ��ť�� �ְ� �� �Ŀ��� dq.back - dq.front �� �̿��ؼ� ���������� ���̵��� �ѹ� �� å���Ѵ�.




���۽ð� : 13:08 (+5��)
����ð� : 13:28     ����õ� : 1ȸ  ||  �ɸ��ð� : 28�� + (5��)
*/



// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <cmath>

// using namespace std;

// int main(void)
// {
// 	cin.tie(0);
// 	ios::sync_with_stdio(false);


// 	int t, n;
// 	cin >> t;

// 	while (t--)
// 	{
// 		cin >> n;
// 		vector<int> height(n);

// 		for (auto &i : height)
// 			cin >> i;


// 		// solve();
// 		int result;

// 		sort(height.begin(), height.end(), less<int>());


// 		deque<int> dq;
// 		dq.push_back(height.back());
// 		height.pop_back();

// 		result = dq.back() - height.back();
// 		dq.push_back(height.back());
// 		height.pop_back();

// 		result = max(dq.front() - height.back(), result);
// 		dq.push_front(height.back());
// 		height.pop_back();


// 		while(!height.empty())
// 		{
// 			result = max(result, dq.back() - height.back());
// 			dq.push_back(height.back());
// 			height.pop_back();

// 			if (height.empty())
// 				break;

// 			result = max(result, dq.front() - height.back());
// 			dq.push_front(height.back());
// 			height.pop_back();
// 		}

// 		result = max(result, abs(dq.front() - dq.back()));
// 		cout << result << "\n";
// 	}

// 	return 0;
// }


// ------------------------------------------------------------
/*  2021-09-14  13:50


�˰��� ��� : 
 - ���� Ǯ��ó�� ��ư� Ǯ �ʿ� ����
   �����ϰ� ������������ �����ϰ� ��Ģ�� ã����, ���� Ǯ �� �ִ�.

   1. �־��� ������ ������������ �����Ѵ�.
   2. result ���� max(height[0] - height[1], height[0] - height[2])�� �����Ѵ�.
   3. �� �� 1 ~ n-2���� Ž���ϸ�, height[i] - height[i+2]�� Ȯ���ذ��� �ִ��� �����Ѵ�.
   4. �̷��� Ž���� �Ŀ� �ִ�(result)�� ����ϸ� �ȴ�.

���۽ð� : 13:50
����ð� : 14:00     ����õ� : 1ȸ  ||  �ɸ��ð� : 10��
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);


	int t, n;
	cin >> t;

	while (t--)
	{
		int result = 0;

		cin >> n;
		vector<int> height(n);

		for (auto &i : height)
			cin >> i;

		sort(height.begin(), height.end(), greater<int>());

		result = max(height[0] - height[1], height[0] - height[2]);
		for (int i = 1; i < n-2; i++)
			result = max(result, height[i] - height[i+2]);

		cout << result << "\n";
	}

	return 0;
}