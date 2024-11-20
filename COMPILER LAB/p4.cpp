
#include <bits/stdc++.h>

using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

string infixToPostfix(const string &infix)
{
    stack<char> operators;
    string postfix;
    for (char token : infix)
    {
        if (isspace(token))
        {
            continue;
        }
        else if (isdigit(token) || isalpha(token))
        {
            postfix += token;
        }
        else if (token == '(')
        {
            operators.push(token);
        }
        else if (token == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else
        {

            while (!operators.empty() && precedence(operators.top()) >= precedence(token))
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

int main()
{
    init_code();
    string infix;
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}