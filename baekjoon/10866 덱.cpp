/*
���� 10866�� �� || �ǹ� 4
https://www.acmicpc.net/problem/10866


���� string ��ü�� ������ �Ŀ� �Է¹޴� ��� ó���ϸ� �� ��


���۽ð� : 3:37
����ð� : 3:48
*/


#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    deque<int> DQ;
    int N, data;   string command;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> command;

        if (command == "front")
        {
            if (DQ.empty())
                cout << "-1\n";

            else
                cout << DQ.front() << "\n";
        }
        
        else if (command == "back")
        {
            if (DQ.empty())
                cout << "-1\n";

            else
                cout << DQ.back() << "\n";
        }


        else if (command == "push_back")
        {
            cin >> data;
            DQ.push_back(data);
        }

        else if (command == "push_front")
        {
            cin >> data;
            DQ.push_front(data);
        }


        else if (command == "pop_front")
        {
            if (DQ.empty())
                cout << "-1\n";

            else
            {
                cout << DQ.front() << "\n";
                DQ.pop_front();
            }
        }

        else if (command == "pop_back")
        {
            if (DQ.empty())
                cout << "-1\n";

            else
            {
                cout << DQ.back() << "\n";
                DQ.pop_back();
            }
        }
        

        else if (command == "empty")
        {
            if (DQ.empty())
                cout << "1\n";

            else
                cout << "0\n";
        }

        else if (command == "size")
            cout << DQ.size() << "\n";

    }

    return 0;
}