#include <algorithm>
#include <array>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>

#include <getopt.h>
#include <string.h>

#include <bits/stdc++.h>

using namespace std;


int main(int argc, char* argv[]) {
    string line;
    unordered_map<string, vector<string>> probs;
    unordered_map<string, int> dict;
    //! \n isn't treated as readible sequence
    //! Some punctuation gets read into the same string as words
    string prev = "\n";
    probs["\n"];
    dict["\n"] = 0;
    int index = 1;
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
                if (dict.find(onlychars) == dict.end()) {
                    dict[onlychars] = index++;
                }
                probs[prev].push_back(onlychars);
                prev = onlychars;
            }
        }
        cout << "\n";
        probs[prev].emplace_back("\n");
        prev = "\n";
    }
    int size = dict.size();
    double transform[size][size];
    memset(transform, 0, size * size * sizeof(int));
    int i2 = 0;
    for (auto& prob : probs) {
        for (int j = 0; j < prob.second.size(); j++) {
            cout << prob.second[j] << " * ";
            transform[i2][dict[prob.second[j]]] += (1 / prob.second.size());
        }
        i2++;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << transform[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
