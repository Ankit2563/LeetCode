

// 746. Min Cost Climbing Stairs

//     You are given an integer array cost where cost[i] is the cost of ith step on a staircase.Once you pay the cost,
//     you can either climb one or two steps.

//                                 You can either start from the step with index 0,
//     or the step with index 1.

//         Return the minimum cost to reach the top of the floor.
#include <bits/stdc++.h>
using namespace std;

int dp[1000];
int funct(int idx, vector<int> &cost)
{
    if (idx >= cost.size())
        return 0;
    if (dp[idx] != -1)
        return dp[idx];

    if (idx <= cost.size() - 2)
    {
        return dp[idx] = min(cost[idx] + funct(idx + 1, cost), cost[idx] + funct(idx + 2, cost));
    }

    return dp[idx] = cost[idx] + funct(idx + 1, cost);
}
int minCostClimbingStairs(vector<int> &cost)
{
    memset(dp, -1, sizeof(dp));

    return min(funct(0, cost), funct(1, cost));
}

int main()
{
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0; i < n;i++)
        cin >> cost[i];

        cout <<  minCostClimbingStairs(cost) << endl;
}
