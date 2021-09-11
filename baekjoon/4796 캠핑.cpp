/*  2021-09-12  12:9
���� 2156�� ������ �ý�  ||  �ǹ�1
https://www.acmicpc.net/problem/2156



�˰��� ��� :
 v % p = x
 (v / p) * l = y

 ans = x + y

 - �̷������� Ǯ�� �� �� �˾�����,
   v % p �� ���������� L���� �Ѿ������ �ݷʰ� �����Ͽ�
   ����ó���� �Ǿ���.


���۽ð� : 12:10
����ð� : 12:30     �ɸ��ð� : 20��  ||  �õ�Ƚ�� : 2ȸ
*/


#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int i = 0, ans, l, p, v, temp;
	while (++i)
	{
		cin >> l >> p >> v;
		if (!l && !p && !v)
			break;

		temp = v % p;
		if (l < temp)
			ans = l;
		else	
			ans = temp;

		ans += (v / p) * l;
		cout << "Case " << i << ": " << ans << "\n";
	}


	return 0;
}