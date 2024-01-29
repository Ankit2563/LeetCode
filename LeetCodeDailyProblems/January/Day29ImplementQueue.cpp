
#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    stack<int> inp, out;
    MyQueue()
    {
    }

    void push(int x)
    {
        inp.push(x);
    }

    int pop()
    {
        int x = 0;
        if (!out.empty())
        {
            x = out.top();
            out.pop();
        }
        else
        {
            while (!inp.empty())
            {
                out.push(inp.top());
                inp.pop();
            }
            x = out.top();
            out.pop();
        }
        return x;
    }

    int peek()
    {
        if (!out.empty())
            return out.top();
        else
        {
            while (!inp.empty())
            {
                out.push(inp.top());
                inp.pop();
            }
            return out.top();
        }
    }

    bool empty()
    {
        if (inp.empty() && out.empty())
            return true;
        return false;
    }
};
int main()
{
    MyQueue q;
    q.push(4);
    q.push(5);
    cout << q.peek() << endl;
    q.push(3);
    q.push(7);

    cout << q.pop() << endl;
    cout << q.peek() << endl;

    return 0;
}
