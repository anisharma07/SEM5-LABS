// write a C/C++ program to find the number of occurrences of any word in a file and replace that word with another word.

#include <bits/stdc++.h>
using namespace std;
#include <fstream>
#include <sstream>

int countOccurrencesAndReplace(string filename, const string &targetWord, const string &replacementWord)
{
    ifstream inputFile(filename);
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "Error opening files." << endl;
        return -1;
    }

    string line;
    int count = 0;
    while (getline(inputFile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(targetWord, pos)) != string::npos)
        {
            count++;
            line.replace(pos, targetWord.length(), replacementWord);
            pos += replacementWord.length();
        }
        outputFile << line << '\n';
    }
    inputFile.close();
    outputFile.close();
    return count;
}
int main()
{
    string filename = "replace.txt";
    string targetWord = "C++", replacementWord = "CPP";
    int count = countOccurrencesAndReplace(filename, targetWord, replacementWord);
    if (count == -1)
    {
        cerr << "Error occurred while processing the file." << endl;
    }
    else if (count == 0)
    {
        cout << "The word was not found in the file." << endl;
    }
    else
    {
        cout << "Replaced " << count << " occurrences of the word with the replacement." << endl;
    }
    return 0;
}