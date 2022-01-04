/*  2022-01-04  20:04
���� 1316�� �׷� �ܾ� üĿ || �ǹ�5
https://www.acmicpc.net/problem/1316

=================================================

[�̷�]
�Է����� �־��� �� ���ڿ��� ���ؼ� '�� ���ڰ� �����ؼ� ��Ÿ���� ���'�� üũ�ϴ� �����
���� �ϳ��ϳ��� ��ȸ�ϸ鼭 �ش� ���ڰ� �� ���ڿ����� 'ó��'���� �����ߴ����� �Ǵ��ϸ� �ȴ�.

[�ҽ�]
�ٷ� ������ Ž���� ���ڸ� �����ϴ� previous ������ �ϳ� ������ ��,
previous�� ���� ���� ������ '�ش� ���ڿ� ���� �湮ó��'�� ���ش�.

���� previous�� ���� Ž������ ���ڰ� �ٸ� ��찡 �߻��Ͽ��� ��,
�ش� ���ڸ� �湮�� ���� �ִ��� Ȯ���Ѵ�.

 -> �湮�� ���� �ִٸ�, �� ���ڰ� �����ؼ� ��Ÿ���� ����
 -> �湮�� ���� ���ٸ�, previous ���� ���� + �湮ó���� �� �̾ ��� Ž��

=================================================

���۽ð�  20:04
����ð�  20:14       �ɸ��ð� : 10��  ||  ����Ƚ�� : 1ȸ

*/


// ---- [ ��Ǯ�� ] ----
#include <iostream>
#include <map>

using namespace std;

int solve(int n);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    cout << solve(n);


    return 0;
}

int solve(int n) {
    string input;
    int count = 0;
    bool isTrue;

    for (int i = 0; i < n; i++) {
        isTrue = true;
        cin >> input;

        map<char, bool> m;

        char previous = input[0];
        m[input[0]] = true;
        for (int j = 1; j < input.length(); j++) {
            // previous ����
            if (previous != input[j]) {
                // �̹� ���ŵ� ���� �ִٸ�
                if (m[input[j]]) {
                    isTrue = false;
                    break;
                }

                previous = input[j];
                m[input[j]] = true;
            }
        }

        if (isTrue)
            count++;
    }

    return count;
}





// ---- [ ���� Ǯ�� ] ----
// 2021-08-22  8:36

// ���۽ð� : 1:57
// ����ð� : 2:07       �ɸ��ð� : 10��  ||  ����Ƚ�� : 1ȸ


// #include <iostream>
// #include <vector>

// using namespace std;

// bool check(string& input);
// int main(void)
// {
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     cout.tie(0);


//     string input;
//     int n, cnt = 0;
//     cin >> n;

//     while(n--)
//     {
//         cin >> input;

//         if (check(input))
//             cnt++;
//     }

//     cout << cnt;
//     return 0;
// }


// bool check(string& input)
// {
//     vector<int> alphabet(26, 0);

//     for (int i = 0; i < input.length(); i++)
//     {
//         if (alphabet[input[i] - 'a'] == 0 || alphabet[input[i] - 'a'] == i)
//             alphabet[input[i] - 'a'] = i+1;
        
//         else    
//             return false;
//     }

//     return true;
// }