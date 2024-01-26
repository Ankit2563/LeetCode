
#include <bits/stdc++.h>
using namespace std;
long long solve(int x, int y, int move, int m, int n, vector<vector<vector<int>>> &dp)
{

    if (x >= 0 && y >= 0 && x < m && y < n && move <= 0)
    {
        return 0;
    }
    if (x < 0 || y < 0 || y >= n || x >= m)
    {
        if (move >= 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[x][y][move] != -1)
        return dp[x][y][move];
    int arx[4] = {0, 1, 0, -1};
    int ary[4] = {1, 0, -1, 0};
    long long maxi = 0;
    for (int i = 0; i < 4; i++)
    {
        long long temp = solve(x + arx[i], y + ary[i], move - 1, m, n, dp);
        maxi = (maxi % 1000000007 + temp % 1000000007) % 1000000007;
    }
    return dp[x][y][move] = maxi;
}
int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    vector<vector<vector<int>>> dp(
        m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
    return (int)solve(startRow, startColumn, maxMove, m, n, dp);
}
int main()
{
    int m, n, maxMove, s, e;
    cin >> m >> n >> maxMove >> s >> e;
    cout << findPaths(s, e, maxMove, m, n);
    return 0;
}
