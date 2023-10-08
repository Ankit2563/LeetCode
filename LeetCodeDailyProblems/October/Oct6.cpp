// 343. Integer Break

    // Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

    // Return the maximum product you can get.

#include <bits/stdc++.h>
using namespace std;
int counting(int elem, vector<int> &nums)
{
    int count = 0;
    for (auto i : nums)
    {
        if (i == elem)
            count++;
    }
    return count;
}
int integerBreak(int n)
{
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int div = n / i;
        int mod = n % i;
        int no = pow(div, i) * mod;
        int no1 = pow(div, i - 1) * (n - div * (i - 1));
        int no2 = mod * (pow((n - mod) / (i - 1), i - 1));
        ans = max(ans, max(no1, no));
        ans = max(ans, no2);
    }

    return ans;
}
void input(int n, vector<int> &nums)
{
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
}

int main()
{
    int n;
    cin >> n;
    cout << integerBreak(n) << endl;
}
