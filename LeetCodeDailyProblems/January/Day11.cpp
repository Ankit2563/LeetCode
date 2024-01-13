
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

int ans = INT_MIN;

pair<int, int> helper(TreeNode *root)
{
    if (!root)
    {
        pair<int, int> p;
        p.first = -1;
        p.second = 100001;
        return p;
    }
    pair<int, int> l = helper(root->left);
    pair<int, int> r = helper(root->right);
    pair<int, int> p;

    p.first = max({r.first, l.first, root->val});
    p.second = min({r.second, l.second, root->val});
    ans = max({ans, abs(root->val - p.first), abs(root->val - p.second)});
    return p;
}

int maxAncestorDiff(TreeNode *root)
{
    if (!root)
        return 0;
    helper(root);
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
    cout << maxAncestorDiff(root) << endl;

    return 0;
}
