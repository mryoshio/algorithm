#include <cassert>
#include <iostream>
#include <fstream>
#include "disjoint_set.cpp"

#define COMMAND_UNITE 0
#define COMMAND_SAME 1

using namespace std;

int main() {
  ifstream ifs("in.txt");

  if (ifs.fail()) {
    cout << "ERROR: read file" << endl;
    return -1;
  }

  int n; ifs >> n;
  DisjointSet s(n);

  while(!ifs.eof()) {
    int com, a, b;
    ifs >> com >> a >> b;
    if (com == COMMAND_SAME) {
      int ans; ifs >> ans;
      assert(s.same(a, b) == ans);
    } else {
      s.unite(a, b);
    }
  }
}
