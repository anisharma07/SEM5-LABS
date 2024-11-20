#include <iostream>
#include <fstream>
#include <string>
// its compiler design lab

using namespace std;

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }
// comment 2
    string line;
    bool inBlockComment = false;
    bool inString = false;
    int commentLines = 0;
// comment 3 

/* 
line 1
line 2
*/ 
    while (getline(inFile, line)) {
        string newLine;
        size_t i = 0;

        while (i < line.size()) {
            if (!inString && !inBlockComment && line[i] == '/' && i + 1 < line.size() && line[i + 1] == '/') {
                
                commentLines++;
                break; 
            } else if (!inString && !inBlockComment && line[i] == '/' && i + 1 < line.size() && line[i + 1] == '*') {
                inBlockComment = true;
                i += 2; 
            } else if (inBlockComment && line[i] == '*' && i + 1 < line.size() && line[i + 1] == '/') {
                
                inBlockComment = false;
                commentLines++;
                i += 2; 
            } else if (!inBlockComment && line[i] == '"') {
                inString = !inString;
                newLine += line[i++];
            } else if (!inBlockComment) {
                newLine += line[i++];
            } else {
                i++; 
            }
        }

        if (!newLine.empty() && !inBlockComment) {
            outFile << newLine << endl;
        } else if (inBlockComment) {
            commentLines++;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Number of comment lines: " << commentLines << endl;

    return 0;
}
