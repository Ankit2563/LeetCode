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
void solve(TreeNode *root, int low, int high, int &sum)
{
    if (root == NULL)
        return;

    solve(root->left, low, high, sum);
    if (root->val >= low && root->val <= high)
        sum += root->val;
    solve(root->right, low, high, sum);
}
int rangeSumBST(TreeNode *root, int low, int high)
{
    int sum = 0;
    solve(root, low, high, sum);
    return sum;
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

    int low = 25;
    int high = 55;
    int ans = rangeSumBST(root, low, high);

    cout << ans << endl;

    return 0;
}
