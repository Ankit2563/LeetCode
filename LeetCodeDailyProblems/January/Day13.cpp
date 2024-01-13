
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

int minSteps(string s, string t)
{
    map<char, int> m, m1;
    for (int i = 0; i < t.size(); i++)
    {
        m[s[i]]++;
        m1[t[i]]++;
    }
    int sum = 0;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        sum += abs(m[ch] - m1[ch]);
    }

    return ceil(sum / 2);
}
int main()
{
    string s,t;
    cin >> s >> t;

    cout << minSteps(s,t);
    return 0;
}
