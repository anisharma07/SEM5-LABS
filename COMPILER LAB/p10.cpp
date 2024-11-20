#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

struct Production
{
    char lhs;
    string rhs;
};

void printStack(stack<char> s)
{
    vector<char> v;
    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    reverse(v.begin(), v.end());
    for (char c : v)
    {
        cout << c;
    }
}

bool canReduce(stack<char> &st, const vector<Production> &productions)
{
    for (const auto &prod : productions)
    {
        string rhs = prod.rhs;
        if (st.size() >= rhs.size())
        {
            string top;
            for (size_t i = 0; i < rhs.size(); ++i)
            {
                top = st.top() + top;
                st.pop();
            }
            if (top == rhs)
            {
                for (char c : top)
                {
                    st.push(c);
                }
                return true;
            }
            else
            {
                for (char c : top)
                {
                    st.push(c);
                }
            }
        }
    }
    return false;
}

void reduce(stack<char> &st, const vector<Production> &productions)
{
    for (const auto &prod : productions)
    {
        string rhs = prod.rhs;
        if (st.size() >= rhs.size())
        {
            string top;
            for (size_t i = 0; i < rhs.size(); ++i)
            {
                top = st.top() + top;
                st.pop();
            }
            if (top == rhs)
            {
                st.push(prod.lhs);
                return;
            }
            else
            {
                for (char c : top)
                {
                    st.push(c);
                }
            }
        }
    }
}

int main()
{
    int numProductions;
    cout << "Enter Number of productions: ";
    cin >> numProductions;

    vector<Production> productions(numProductions);
    cout << "Enter productions:\n";
    for (int i = 0; i < numProductions; ++i)
    {
        string prod;
        cin >> prod;
        productions[i].lhs = prod[0];
        productions[i].rhs = prod.substr(3);
    }

    string input;
    cout << "Enter Input: ";
    cin >> input;

    stack<char> st;
    size_t ip = 0;

    cout << "Stack\tInput\tAction\n";

    while (ip < input.size() || canReduce(st, productions))
    {
        if (ip < input.size())
        {
            st.push(input[ip]);
            // cout << "(";
            printStack(st);
            cout << "\t" << input.substr(ip + 1) << "\tShifted\n";
            ip++;
        }

        while (canReduce(st, productions))
        {
            reduce(st, productions);
            // cout << "(";
            printStack(st);
            cout << "\t" << input.substr(ip) << "\tReduced\n";
        }
    }

    if (st.size() == 1 && st.top() == 'E' && ip == input.size())
    {
        cout << "String Accepted\n";
    }
    else
    {
        cout << "String Rejected\n";
    }

    return 0;
}

// Enter Number of productions: 4
// Enter productions:
// E->E+E
// E->E*E
// E->(E)
// E->a
// Enter Input: (a+a)*a