#include <iostream>
#include <map>

using namespace std;

map<char, pair<char, char>> tree;

void preorder(char node);
void inorder(char node);
void postorder(char node);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    char parent, left, right;
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> parent >> left >> right;
        tree[parent] = make_pair(left, right);
    }

    preorder('A');
    cout << '\n';

    inorder('A');
    cout << '\n';

    postorder('A');
}

void preorder(char node)
{
    cout << node;

    if (tree[node].first != '.')
        preorder(tree[node].first);
    
    if (tree[node].second != '.')
        preorder(tree[node].second);
}

void inorder(char node)
{
    if (tree[node].first != '.')
        inorder(tree[node].first);
    
    cout << node;

    if (tree[node].second != '.')
        inorder(tree[node].second);
}

void postorder(char node)
{
    if (tree[node].first != '.')
        postorder(tree[node].first);
    
    if (tree[node].second != '.')
        postorder(tree[node].second);

    cout << node;
}