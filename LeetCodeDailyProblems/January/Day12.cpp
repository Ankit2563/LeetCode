
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *insert(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }

    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = insert(root->right, val);
    }

    return root;
}

int noVowel(int index, int n, string &s)
{
    int v1 = 0;
    for (int i = index; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'I' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U')
        {
            v1++;
        }
    }
    return v1;
}
bool halvesAreAlike(string s)
{
    return noVowel(0, s.size() / 2, s) == noVowel(s.size() / 2, s.size(), s);
}
int main()
{
    string s;
    cin >> s;

    cout<<halvesAreAlike(s);
    return 0;
}
