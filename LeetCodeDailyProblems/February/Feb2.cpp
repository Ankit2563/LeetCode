#include <bits/stdc++.h>
using namespace std;
int reverseDigit(int n)
{
    int reversed_number = 0, remainder;
    while (n != 0)
    {
        remainder = n % 10;
        reversed_number = reversed_number * 10 + remainder;
        n /= 10;
    }
    return reversed_number;
}
void solve(int digit, int low, int high, int no, int p, vector<int> &ans)
{
    if (p >= 9 || digit >= 10)
        return;
    no = no + ((int)pow(10, p) * digit);
    int n = reverseDigit(no);
    if (n > high)
        return;
    if (n >= low && n <= high)
    {
        ans.push_back(n);
    }
    solve(digit + 1, low, high, no, p + 1, ans);
}
vector<int> sequentialDigits(int low, int high)
{
    vector<int> ans;

    for (int i = 1; i <= 8; i++)
    {
        int no = 0;
        int pow = 0;
        solve(i, low, high, no, pow, ans);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int low,high;
    cin >> low >> high;

    vector<int> v = sequentialDigits(low, high);
    return 0;
}