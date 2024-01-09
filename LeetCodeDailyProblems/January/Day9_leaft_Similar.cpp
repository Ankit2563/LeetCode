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
void solve(TreeNode *root, vector<int> &v1)
{
    if (root->left == NULL && root->right == NULL)
    {
        v1.push_back(root->val);
        return;
    }

    if (root->left != NULL)
        solve(root->left, v1);
    if (root->right != NULL)
        solve(root->right, v1);
}
bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> v1, v2;
    solve(root1, v1);
    solve(root2, v2);
    return v1 == v2;
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
    TreeNode *root1 = NULL;

      root1 = insert(root1, 43);
    root1 = insert(root, 60);
    root1 = insert(root, 20);
    root1 = insert(root1, 40);
    root1 = insert(root, 30);
    root1 = insert(root1, 50);
    root1 = insert(root1, 70);

       cout << leafSimilar(root, root1) << endl;

       return 0;
}
