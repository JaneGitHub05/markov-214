#include <algorithm>
#include <cstring>
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
        stringstream st(tolower(line));
        string word;
        while (getline(st, word, ' ')) {}
    }
    return 0;
}
