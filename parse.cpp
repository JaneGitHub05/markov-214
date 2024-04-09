#include "ctype.h"
#include <algorithm>
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <map>
using namespace std;

// TODO: Parse contents of input file

int main(int argc, char *argv[]) {
  string word;
  unordered_map<string, int> count;
  //! \n isn't treated as readible sequence
  while (cin >> word) {
    if (isupper(word[0])) {
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