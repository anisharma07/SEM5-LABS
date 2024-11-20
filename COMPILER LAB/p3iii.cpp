#include <bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool isValidIdentifier(char c)
{
    return isalnum(c) || c == '_';
}

bool isValidOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' || c == '<' || c == '>' || c == '!';
}

bool isBalancedParentheses(const string &expression)
{
    stack<char> s;
    for (char c : expression)
    {
        if (c == '(')

        {
            s.push(c);
        }
        else if (c == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

bool isValidArithmeticExpression(const string &expression)
{
    if (!isBalancedParentheses(expression))
    {
        return false;
    }

    bool expectOperand = true;
    for (size_t i = 0; i < expression.length(); ++i)
    {
        char c = expression[i];
        if (isspace(c))
        {
            continue;
        }

        if (expectOperand)
        {
            if (isValidIdentifier(c) || isdigit(c) || c == '(')
            {
                expectOperand = false;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (isValidOperator(c) || c == ')')
            {
                expectOperand = true;
            }
            else if (isValidIdentifier(c) || isdigit(c))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return !expectOperand;
}

int main()
{
    init_code();

    string expression = "a=b+c * (d-e) / f";

    if (isValidArithmeticExpression(expression))
    {
        cout << "The expression is a valid arithmetic expression." << endl;
    }
    else
    {
        cout << "The expression is not a valid arithmetic expression." << endl;
    }

    string currentToken;
    cout << "Identifiers in the expression:" << endl;
    for (char c : expression)
    {
        if (isValidIdentifier(c))
        {
            currentToken += c;
        }
        else if (!currentToken.empty())
        {
            cout << currentToken << endl;
            currentToken.clear();
        }
    }
    if (!currentToken.empty())
    {
        cout << currentToken << endl;
        currentToken.clear();
    }

    cout << "Operators in the expression:" << endl;
    for (char c : expression)
    {
        if (isValidOperator(c))
        {
            cout << c << endl;
        }
    }

    return 0;
}