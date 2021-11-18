#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std ;

int N ;

const int UNDISCOVERED = 0 ;
const int DISCOVERED = 1 ;
const int PROCESSED = 2 ;

void set_dists_dfs(int s, vector< set<int> > &adj_list, vector< vector<int> > &ds) {
  vector<int> &ds_s = ds.at(s) ;

  stack<int> container ;
  vector<int> node_status(N) ;
  for (int u = 0 ; u < N ; u++)
    node_status.at(u) = UNDISCOVERED ;

  container.push(s) ;
  node_status.at(s) = DISCOVERED ;

  while (! container.empty()) {
    int u = container.top() ;
    container.pop() ;
    for (int v : adj_list.at(u)) {
      if (node_status.at(v) != UNDISCOVERED)
        continue ;
      container.push(v) ;
      node_status.at(v) = DISCOVERED ;
      ds_s.at(v) = ds_s.at(u) + 1 ;
    }
    node_status.at(u) = PROCESSED ;
  }
}
int find_max_dist(vector< vector<int> > &ds) {
  int max_dist = 0 ;
  for (int u = 0 ; u < N - 1 ; u++) {
    for (int v = u + 1 ; v < N ; v++)
      max_dist = max(max_dist, ds.at(u).at(v)) ;
  }
  return max_dist ;
}

int main() {
  cin >> N ;
  vector< set<int> > adj_list(N) ;
  for (int i = 0 ; i < N - 1 ; i++) {
    int u, v ;
    cin >> u >> v ;
    u-- ;
    v-- ;
    adj_list.at(u).insert(v) ;
    adj_list.at(v).insert(u) ;
  }

  vector< vector<int> > dists(N, vector<int>(N)) ;
  for (int u = 0 ; u < N ; u++) {
    for (int v = 0 ; v < N ; v++)
      dists.at(u).at(v) = 0 ;
  }

  for (int u = 0 ; u < N - 1 ; u++)
    set_dists_dfs(u, adj_list, dists) ;

  cout << find_max_dist(dists) + 1 << endl ;
}
