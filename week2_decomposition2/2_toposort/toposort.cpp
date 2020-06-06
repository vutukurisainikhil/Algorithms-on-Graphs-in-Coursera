#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

// void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
//   //write your code here
// }    
void topo(vector<vector<int>> &adj, bool visited[], int v, vector<int> &order){
  visited[v]=true;
  vector<int> :: iterator itr;
  for(itr = adj[v].begin();itr!=adj[v].end();itr++){
    if(!visited[*itr]){
      topo(adj, visited, *itr, order);
    }
  }
  order.push_back(v);
}

vector<int> toposort(vector<vector<int> > adj) {
  //vector<int> used(adj.size(), 0);
  vector<int> order; // stack can be used....
  //write your code here
  bool *visited = new bool[adj.size()];
  for(int i=0;i<adj.size();i++){
    visited[i] = false;
  }
  for(int i=0;i<adj.size();i++){
      if(!visited[i]){
        topo(adj, visited, i, order);
      }
  }
  reverse(order.begin(),order.end()); //No need to reverse if we use stack here ..
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
