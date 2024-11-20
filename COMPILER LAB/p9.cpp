#include <bits/stdc++.h>
using namespace std;

bool isLeftFactoring(string &p)
{
    char start = '\0';
    for (int i = 1; i < p.length(); ++i)
    {
        if (p[i - 1] == '>')
        {
            start = p[i];
        }
        else if (p[i - 1] == '|' && p[i] != start)
        {
            return false;
        }
    }
    return true;
}

bool isLeftRecursion(string &p)
{
    char start = p[0];
    for (int i = 1; i < p.length(); ++i)
    {
        if ((p[i - 1] == '>' || p[i - 1] == '|') && (p[i] == start))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int numProductions;
    cout << "Enter the number of productions: ";
    cin >> numProductions;
    cin.ignore(); // Clear the newline character from the input buffer
    bool flag = false;
    for (int i = 0; i < numProductions; ++i)
    {
        cout << "Enter production " << (i + 1) << ": ";
        string p;
        getline(cin, p); // Use getline to allow spaces in the production

        bool leftRecursive = isLeftRecursion(p);
        bool leftFactoring = isLeftFactoring(p);
        if (leftRecursive || leftFactoring)
            flag = true;
    }
    if (flag)
    {
        cout << "The given grammar is not LL(1)." << endl;
    }
    else
    {
        cout << "The given grammar is LL(1)." << endl;
    }
    return 0;
}