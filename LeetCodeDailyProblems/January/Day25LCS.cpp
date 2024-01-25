
#include <bits/stdc++.h>
using namespace std;
int LCS(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (text1[ind1] == text2[ind2])
    {
        dp[ind1][ind2] = 1 + LCS(ind1 - 1, ind2 - 1, text1, text2, dp);
        return 1 + LCS(ind1 - 1, ind2 - 1, text1, text2, dp);
    }
    else
    {
        return dp[ind1][ind2] = 0 + max(LCS(ind1 - 1, ind2, text1, text2, dp), LCS(ind1, ind2 - 1, text1, text2, dp));
    }
}
int longestCommonSubsequence(string text1, string text2)
{
    int ind1 = text1.size() - 1, ind2 = text2.size() - 1;
    vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, -1));
    return LCS(ind1, ind2, text1, text2, dp);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestCommonSubsequence(s1, s2) << endl;

    return 0;
}
