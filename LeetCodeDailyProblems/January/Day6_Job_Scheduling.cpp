#include <bits/stdc++.h>
using namespace std;

int solve(int index, int n, vector<vector<int>> &v, vector<int> &dp)
{
    if (index >= n)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int maxi = 0, maxi2 = 0;

    int s = v[index][0], e = v[index][1], p = v[index][2];
    vector<int> temp = {e, 0, 0};
    int firstIndex = lower_bound(v.begin(), v.end(), temp) - v.begin();//using the binary_search in order to find out middle most profit index
    maxi = solve(index + 1, n, v, dp);

    maxi2 = solve(firstIndex, n, v, dp) + p;

    return dp[index] = max(maxi, maxi2);
}
int jobScheduling(vector<int> &s, vector<int> &e, vector<int> &p)
{
    int n = s.size();
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({s[i], e[i], p[i]});
    }
    sort(v.begin(), v.end());
    vector<int> dp(n, -1);
    return solve(0, n, v, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> s(n),e(n),p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
       
    }
    for (int i = 0; i < n; i++)
    {
        cin >> e[i];
       
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
       
    }

    cout << jobScheduling(s,e,p) << endl;

    return 0;
}