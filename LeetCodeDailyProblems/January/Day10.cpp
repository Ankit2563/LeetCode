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
void solve(TreeNode*root,int parent, map<int,map<int,int>>&m){
    if(root==NULL)return;

    if(root->left!=NULL){
        int val1=root->left->val;
        m[root->val][val1]++;
    }

    if(root->right!=NULL){
        int val1=root->right->val;
         m[root->val][val1]++;
    }
    if(parent!=-1){
        m[root->val][parent]++;
    }
    solve(root->left,root->val,m);
    solve(root->right,root->val,m);

}
    int amountOfTime(TreeNode* root, int start) {
        queue<pair<int,int>>q;
        map<int,map<int,int>>m;
        
        solve(root,-1,m);
        q.push({start,0});
        map<int,int>vis;
        for(auto it:m){
        vis[it.first]=0;
        }
        vis[start]=1;
        int tm=0;
        while(!q.empty()){
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            tm=max(tm,time);
            for(auto it:m[node]){

                if(vis[it.first]==0){
                    q.push({it.first,time+1});
                    vis[it.first]=1;
                } 
            }
        }
        return tm;
        
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
    cout << amountOfTime(root, 30) << endl;

    return 0;
}
