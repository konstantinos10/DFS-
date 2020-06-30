#include <iostream>
#include <list>
#include <queue>
#include <vector> 

using namespace std ;

class Graph {
public:
  Graph(int n);
  void addEdge(int u, int v);
  bool hasEdge(int u, int v) const;
  int vertices() const;
  const list<int> & edges(int u) const;
};
enum state { UNVISITED, SEEN, VISITED };
void dfs_help(int u, int &time,const Graph &g, vector<int> &p,vector<int> &A, vector<int> &T,vector<state> &status) {
  status[u] = SEEN;
  A[u] = ++time;
  for (int v: g.edges(u))
    if (status[v] == UNVISITED) {
      p[v] = u;
      dfs_help(v, time, g, p, A, T, status);  
    }
  status[u] = VISITED;
  T[u] = ++time;
}
void dfs(const Graph &g, vector<int> &p,vector<int> &A, vector<int> &T) {
  int N = g.vertices();
  vector<state> status(N);
  for (int u = 0; u < N; ++u) {
    p[u] = -1; status[u] = UNVISITED;
}
  int time = 0;
  for (int u = 0; u < N; ++u)
    if (status[u] == UNVISITED)
      dfs_help(u, time, g, p, A, T, status);
}

