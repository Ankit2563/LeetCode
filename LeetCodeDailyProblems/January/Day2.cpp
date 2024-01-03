#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> findMatrix(vector<int> &nums)
{
    unordered_map<int, int> m;
    int maxcount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
        maxcount = max(maxcount, m[nums[i]]);
    }

    vector<vector<int>> v(maxcount);
    for (int i = 0; i < maxcount; i++)
    {
        for (auto itr : m)
        {
            int count = itr.second;
            int val = itr.first;
            if (count != 0)
            {
                v[i].push_back(val);
                m[val]--;
            }
        }
    }

    return v;
}

int main()
{
    int n;
    cin >> n;
    vector<int> bank(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bank[i];
    }
   vector<vector<int>>ans= findMatrix(bank);
   for (int i = 0; i < ans.size();i++){
       for (int j = 0; j < ans[i].size();j++){
           cout << ans[i][j] << " ";
       }
       cout << endl;
   }

       return 0;
}