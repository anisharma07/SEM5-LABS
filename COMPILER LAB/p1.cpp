// write a cpp program to search the number of occurences of any word, string and sub sequence in a given string
#include <bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int countWordOccurrences(string str, string word)
{
    int j = 0;
    int count = 0;
    for (char c : str)
    {
        if (c == word[j])
        {
            j++;
            if (j == word.length())
            {
                count++;
                j = 0;
            }
        }
        else if (j > 0)
        {
            j = 0;
        }
    }
    return count;
}

int countSubstringOccurrences(string str, string sub)
{
    int j = 0;
    int count = 0;
    for (char c : str)
    {
        if (c == sub[j])
        {
            j++;
            if (j == sub.length())
            {
                count++;
                j = 0;
            }
        }
        else
            j = 0;
    }
    return count;
}

int countSubsequenceOccurrences(string str, string subseq)
{
    int m = str.length();
    int n = subseq.length();
    if (n == 0)
        return 1;
    if (m == 0)
        return 0;
    int count = 0;
    int j = 0;
    vector<int> dp(m, -1);

    for (int i = 0; i < m; i++)
    {
        j = 0;
        for (int x = i; x < m; x++)
        {
            if (str[x] == subseq[j] && dp[x] != 1)
            {
                dp[x] = 1;
                j++;
                if (j == n)
                {
                    count++;
                    j = 0;
                }
            }
        }
    }

    return count;
}
int countOccurrences(const std::string &text, const std::string &pattern)
{
    int count = 0;
    size_t pos = 0;
    while ((pos = text.find(pattern, pos)) != std::string::npos)
    {
        pos += pattern.length();
        count++;
    }
    return count;
}

// Function to count occurrences of a subsequence in a string
int countSub2(const string &str, const string &subseq)
{
    int m = str.length();
    int n = subseq.length();
    if (n == 0)
        return 1;
    if (m == 0)
        return 0;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; ++i)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (str[i - 1] == subseq[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}

int main()
{
    init_code();
    string str;
    string word;
    string sub;
    string subseq;
    getline(cin, str);
    getline(cin, word);
    getline(cin, sub);
    getline(cin, subseq);
    cout << "word: " << countWordOccurrences(str, word) << endl;
    cout << "substring: " << countSubstringOccurrences(str, sub) << endl;
    cout << "uniqueCharSubsequence: " << countSubsequenceOccurrences(str, subseq) << endl;
    cout << "subsequence: " << countSub2(str, subseq) << endl;
    cout << "subsequence: " << countOccurrences(str, subseq) << endl;
    return 0;
}