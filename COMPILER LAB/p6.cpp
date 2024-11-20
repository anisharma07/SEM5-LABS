// write a program to check whether a string belongs to the grammar or not. write a program to generate a parse tree.
#include <bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

char selectedChar = 'x';
bool checkStringInGrammar(string s, vector<string> &parseTree)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i == 0)
        {
            if (s[i] == 'c')
            {
                parseTree.push_back("cA");
                selectedChar = 'A';
            }
            else if (s[i] == 'd')
            {
                parseTree.push_back("dB");
                selectedChar = 'B';
            }
            else
            {
                return false;
            }
        }
        else if (selectedChar == 'A')
        {
            if (s[i] == 'a')
            {
                parseTree.push_back("aA");
                selectedChar = 'A';
            }
            else if (s[i] == 'b')
            {
                parseTree.push_back("bB");
                selectedChar = 'B';
            }
            else
            {
                return false;
            }
        }
        else if (selectedChar == 'B')
        {
            if (s[i] == 'b')
            {
                parseTree.push_back("bB");
                selectedChar = 'B';
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

void printParseTree(vector<string> tree)
{
    cout << "Parse Tree:" << endl;
    cout << " S" << endl;
    cout << "/ \\" << endl;
    for (int i = 0; i < tree.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        cout << tree[i][0] << "  " << tree[i][1] << endl;
        for (int j = 0; j <= i; j++)
        {
            cout << "  ";
        }
        if (i != tree.size() - 1)
        {
            cout << "/ \\" << endl;
        }
    }
    for (int i = 0; i < tree.size(); i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
}

int main()
{
    init_code();
    string s;
    cin >> s;
    vector<string> parseTree;
    if (checkStringInGrammar(s, parseTree))
    {
        cout << "The string '" << s << "' belongs to the grammar." << endl;
        printParseTree(parseTree);
    }
    else
    {
        cout << "The string '" << s << "' does not belong to the grammar." << endl;
    }
    return 0;
}

// Define the structure of a parse tree node

// S->cA | dB;
// A->  aB| ε;
// B->  bB | ε;
