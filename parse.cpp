#include <algorithm>
#include <array>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>

#include <getopt.h>
#include <stdlib.h>
#include <strin./pparknow


#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
  // input initial state as well, e.g. ./parse know 5 >
  string initial = argv[1];
  int num = atoi(argv[2]);
  cout << initial << "\n" << num << " \n";
  string line;
  map<string, vector<string> > probs;
  map<string, int> dict;
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
          dict[onlychars] = 0;
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
  memset(transform, 0, size * size * sizeof(double));
  int i2 = 0;
  cout << "\n\n";
  for (auto &d : dict) {
    d.second = i2;
    i2++;
  }
  i2 = 0;
  for (auto &prob : probs) {
    for (int j = 0; j < prob.second.size(); j++) {
      transform[i2][dict[prob.second[j]]] +=
          (static_cast<double>(1) / prob.second.size());
    }
    i2++;
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << transform[i][j] << " ";
    }
    cout << "\n";
  }

  fstream fout;
  fout.open("transformnew.csv", ios::out | ios::app);
  fout << initial << "\n" << num << "\n";
  int k = 0;
  for (auto &i : dict) {
    if (i.first[0] != '\n') {
      fout << i.first;
      if (k != size - 1) {
        fout << ",";
      }
    }
    k++;
  }
  fout << "\n";
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      fout << transform[i][j];
      if (j != size - 1) {
        fout << ",";
      }
    }
    fout << "\n";
  }
  remove("transform.csv");
  rename("transformnew.csv", "transform.csv");

  return 0;
}
