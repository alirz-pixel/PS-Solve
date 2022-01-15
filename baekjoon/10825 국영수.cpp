/*
���� 10825�� ������ || �ǹ� 4
https://www.acmicpc.net/problem/10825


�׻� compare �Լ��� �ۼ��ϴ� �κп��� �������µ� �� ����� ��α� ���п�
������ ���� �� �־���, �����ε� �ܿ� �� ���� �� ����.

compare �Լ��� '<'�� ������ ��ȣó�� �ڿ��� ���� Ŀ���ٶ�� �������� �ڵ带 �ۼ��ϸ� ���ϰ�
               '>'�� �ݴ�� �ڿ��� ���� �۾����ٶ�� �������� �ڵ带 �ۼ��ϸ� �ȴ�.


[���� ����Ʈ] :
 - https://urbangy.tistory.com/43
 - https://artbooks.tistory.com/42
 - https://leeeegun.tistory.com/5


���۽ð� : 9:37  
����ð� : 10:01     �ɸ��ð� : 24��  |  �õ�Ƚ�� 1ȸ
*/

  
  
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct _score {
    int korean;
    int english;
    int math;
    string name;
} score;

bool compare(const score& x, const score& y);
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);


    int n;
    cin >> n;

    vector<score> input(n);
    for (auto &i : input) {
        cin >> i.name >> i.korean >> i.english >> i.math;
    }   

    sort(input.begin(), input.end(), compare);

    for (auto i : input) {
        cout << i.name << "\n";
    }

    return 0;
}

bool compare(const score& x, const score& y) {
    // ��ȯ���� true�� ������ �����ʺ��� �۴ٰ� �����Ѵ�.
    if (x.korean == y.korean) {
        if (x.english == y.english) {
            if (x.math == y.math) {
                return x.name < y.name;
            } 
            return x.math > y.math;
        }
        return x.english < y.english;
    }
    return x.korean > y.korean;
}