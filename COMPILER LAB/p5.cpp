
#include <bits/stdc++.h>
using namespace std;

// Helper function to split a string based on a delimiter
vector<string> split(const string &s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to check for left recursion
bool isLeftRecursive(const vector<string> &productions)
{
    for (const string &rule : productions)
    {
        string left = rule.substr(0, 1); // Extract the non-terminal
        string right = rule.substr(3);   // Extract the productions part

        // Check if the production starts with the same non-terminal
        vector<string> alternatives = split(right, '|');
        for (const string &alt : alternatives)
        {
            if (!alt.empty() && alt[0] == left[0])
            {
                return true; // Left recursion detected
            }
        }
    }
    return false;
}

// Function to check for left factoring
bool needsLeftFactoring(const vector<string> &productions)
{
    for (const string &rule : productions)
    {
        string left = rule.substr(0, 1); // Extract the non-terminal
        string right = rule.substr(3);   // Extract the productions part
        vector<string> alternatives = split(right, '|');

        // Use a map to track prefixes
        vector<string> prefixes;
        for (const string &alt : alternatives)
        {
            if (!alt.empty())
            {
                string prefix = alt.substr(0, 1); // Take the first character as the prefix
                if (find(prefixes.begin(), prefixes.end(), prefix) != prefixes.end())
                {
                    return true; // Left factoring needed
                }
                prefixes.push_back(prefix);
            }
        }
    }
    return false;
}

int main()
{
    int numRules = 1;
    cout << "Enter the number of production rules: ";
    cin >> numRules;
    cin.ignore(); // ready the numRules to be used in productions vector

    vector<string> productions(numRules);
    cout << "Enter each production rule in the format left->right:" << endl;
    for (int i = 0; i < numRules; ++i)
    {
        getline(cin, productions[i]);
    }

    bool lRec = isLeftRecursive(productions);
    bool lFac = needsLeftFactoring(productions);

    cout << "The grammar is" << (lRec ? "" : " not") << " Left recursive." << endl;
    cout << "The grammar" << (lFac ? "" : " does not") << " needs left factoring.";
    return 0;
}
