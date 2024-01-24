
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

void solve(TreeNode *root, int &ans, unordered_map<int, int> m)
{

    if (root->left == NULL && root->right == NULL)
    {
        int odd = 0, even = 0;
        m[root->val]++;
        for (auto it : m)
        {
            if (it.second > 0)
            {
                if (it.second % 2 == 0)
                    even++;
                else
                    odd++;
            }
        }
        if (odd <= 1 && even > 0)
        {
            ans++;
            return;
        }
        if (odd == 1 && even == 0)
        {
            ans++;
            return;
        }

        return;
    }
    m[root->val]++;
    if (root->left != NULL)
        solve(root->left, ans, m);

    if (root->right != NULL)
        solve(root->right, ans, m);
    m[root->val]--;
    ;
}

int pseudoPalindromicPaths(TreeNode *root)
{
    int ans = 0;
    unordered_map<int, int> m;
    solve(root, ans, m);
    return ans;
}

int main()
{

    TreeNode *root = NULL;

    root = insert(root, 43);
    root = insert(root, 30);
    root = insert(root, 60);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 70);
    cout << pseudoPalindromicPaths(root) << endl;

    return 0;
}
