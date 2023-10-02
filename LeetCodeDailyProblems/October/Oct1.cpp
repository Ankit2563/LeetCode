// 557. Reverse Words in a String III

    // Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    int l = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            reverse(s.begin() + l, s.begin() + i);
            l = i + 1;
        }
    }
    reverse(s.begin() + l, s.end());
    return s;
}

int main()
{
    string s;
    cin >> s;
    cout << reverseWords(s) << endl;
}
