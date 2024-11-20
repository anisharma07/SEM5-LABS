#include <iostream>
using namespace std;

// Function to check if the string follows the grammar S -> aSb | ε
bool checkGrammar(const string &s, int &index)
{
    // Base case: empty production (ε)
    if (index >= s.length())
    {
        return true;
    }
    // Check for 'a' followed by recursive descent on S, then 'b'
    if (s[index] == 'a')
    {
        index++;
        if (checkGrammar(s, index) && index < s.length() && s[index] == 'b')
        {
            index++;
            return true;
        }
    }
    // Otherwise, return false
    return false;
}

// Function to validate if the string belongs to the grammar
bool belongsToGrammar(const string &s)
{
    int index = 0;
    return checkGrammar(s, index) && index == s.length();
}

int main()
{
    string s = "aabb"; // Test string
    if (belongsToGrammar(s))
    {
        cout << "The string '" << s << "' belongs to the grammar." << endl;
    }
    else
    {
        cout << "The string '" << s << "' does not belong to the grammar." << endl;
    }
    return 0;
}
