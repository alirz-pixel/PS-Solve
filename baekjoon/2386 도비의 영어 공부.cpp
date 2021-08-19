/*  2021-08-20  2:35
���� 2386�� ������ ���� ���� || �����2
https://www.acmicpc.net/problem/2386


ȸ��
 - ���⵵ �Է¹��� �� �ִ� getline �Լ��� ��Ծ��ٴ� ��.
 - �빮�ڵ� same�� ��ġ�ϴ��� Ȯ���ؾ� �ߴٴ� ��.

�� 2���� ���� ICPC���� �и� Ʋ�Ƚ��ϴٳ� Ǯ�� ������ ���̴�..


���۽ð� 2:45
����ð� 2:51     �ɸ��ð� : 6��  ||  �õ�Ƚ�� : 1ȸ
*/


#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int cnt;
    string same, sentence;
    while (1)
    {
        cnt = 0;
        cin >> same;

        if (same == "#")
            break;
        
        getline(cin, sentence);

        for (int i = 0; i < sentence.size(); i++)
            if (same[0] - 'a' == sentence[i] - 'a' || same[0] - 'a' == sentence[i] - 'A')
                cnt++;

        cout << same << " " << cnt << "\n";
    }


    return 0;
}