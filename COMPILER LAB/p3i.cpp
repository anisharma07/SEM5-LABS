// write a cpp program to find the number of characters, words,
// spaces and lines in a text file.

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> countRequired(string str)
{
    int cnt = 0;
    int flag = 0;
    int space = 0;
    int num_ch = 0;
    for (char c : str)
    {
        if (c == ' ')
        {
            flag = 0;
            space++;
        }
        else
        {
            num_ch++;
            if (flag == 0)
            {
                cnt++;
                flag = 1;
            };
        }
    }
    return {space, cnt, num_ch};
}

int main()
{
    init_code();
    int space = 0;
    int num_ch = 0;
    int word = 0;

    string line;
    int num_lines = 0;
    ifstream inputFile("text.txt");
    while (!inputFile.eof())
    {
        getline(inputFile, line);
        vector<int> res = countRequired(line);
        space += res[0];
        word += res[1];
        num_ch += res[2];
        num_lines++;
    }
    inputFile.close();
    cout << "No. of characters are : " << num_ch << endl;
    cout << "No. of spaces are : " << space << endl;
    cout << "No. of words are : " << word << endl;
    cout << "No. of lines are : " << num_lines << endl;
    return 0;
}