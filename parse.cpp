#include <algorithm>
#include <fstream>
#include <getopt.h>
#include <iostream>
using namespace std;

// TODO: Parse contents of input file

int main(int argc, char *argv[]) {
  string word;
  while (cin >> word) {
    cout << word;
  }
  return 0;
}