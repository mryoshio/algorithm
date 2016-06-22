#include <vector>
using namespace std;

/*
  p: parent of node x
  r: rank (representative of set including x)
  ref: http://bit.ly/28TtaLs
*/
class DisjointSet {
  vector<int> p, r;
  DisjointSet() {}

public:
  DisjointSet(int size) {
    p.resize(size, 0);
    r.resize(size, 0);
    for (int i = 0; i < size; i++) makeSet(i);
  }

  void makeSet(int i) {
    p[i] = i;
    r[i] = 0;
  }

  bool same(int a, int b) {
    return (findSet(a) == findSet(b));
  }

  void unite(int a, int b) {
    link(findSet(a), findSet(b));
  }

  void link(int a, int b) {
    if (r[a] < r[b]) {
      p[a] = b;
    } else {
      p[b] = a;
      if (r[a] == r[b]) r[a]++;
    }
  }

  int findSet(int i) {
    if (i != p[i]) p[i] = findSet(p[i]);
    return p[i];
  }
};
