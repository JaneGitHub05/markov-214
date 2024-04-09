#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>

#include <getopt.h>

#include <bits/stdc++.h>

#include "ctype.h"
using namespace std;


int main(int argc, char* argv[]) {
    string line;
    unordered_map<string, int> count;
    //! \n isn't treated as readible sequence
    //! Some punctuation gets read into the same string as words
    while (getline(cin, line)) {
        stringstream st(line);
        if (isupper([0])) {
            cout << static_cast<char>(tolower(word[0])) << " ";
        }
        cout << word << " ";
        if (auto search = count.find(word); search != count.end()) {
            count[word] += 1;
            cout << word << ": " << count[word] << "\n";
        } else {
            count[word] = 1;
        }
        cout << "\n";
    }
    return 0;
}
