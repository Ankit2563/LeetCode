
#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    int x = stoi(tokens[0]);
    st.push(x);
    int i = 1;
    while (i != tokens.size())
    {

        if (tokens[i] == "*")
        {
            int tp = st.top();

            st.pop();
            if (st.empty())
                return tp;
            else
            {
                int x1 = st.top();
                st.pop();
                st.push(x1 * tp);
            }
        }
        else if (tokens[i] == "/")
        {
            int tp = st.top();

            st.pop();
            if (st.empty())
                return tp;
            else
            {
                int x1 = st.top();
                st.pop();
                st.push(x1 / tp);
            }
        }
        else if (tokens[i] == "-")
        {
            int tp = st.top();

            st.pop();
            if (st.empty())
                return tp;
            else
            {
                int x1 = st.top();
                st.pop();
                st.push(x1 - tp);
            }
        }
        else if (tokens[i] == "+")
        {
            int tp = st.top();

            st.pop();
            if (st.empty())
                return tp;
            else
            {
                int x1 = st.top();
                st.pop();
                st.push(x1 + tp);
            }
        }
        else
        {
            x = stoi(tokens[i]);
            st.push(x);
        }
        i++;
    }

    return st.top();
}
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    cout << evalRPN(v);

    return 0;
}
