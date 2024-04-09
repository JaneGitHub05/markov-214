#include <algorithm>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>

#include <getopt.h>

#include <bits/stdc++.h>

using namespace std;


int main(int argc, char* argv[]) {
    string line;
    unordered_map<string, vector<string>> probs;
    //! \n isn't treated as readible sequence
    //! Some punctuation gets read into the same string as words
    string prev = "\n";
    probs["\n"];
    while (getline(cin, line, '\n')) {
        stringstream st(line);
        string word;
        while (getline(st, word, ' ')) {
            string onlychars;
            for (int i = 0; i <= static_cast<int>(word.length()); i++) {
                if (isalpha(word[i]) != 0) {
                    onlychars += tolower(word[i]);
                }
            }
            if (onlychars.length() > 0) {
                cout << onlychars << " ";
                probs[onlychars];
                probs[prev].push_back(onlychars);
                prev = onlychars;
            }
        }
        cout << "\n";
        probs[prev].emplace_back("\n");
        prev = "\n";
    }
    return 0;
}
