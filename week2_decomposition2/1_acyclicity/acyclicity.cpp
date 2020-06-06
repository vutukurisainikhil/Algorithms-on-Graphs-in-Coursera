#include <iostream>
#include <vector>
#include<iterator>

using std::vector;
using std::pair;

bool check_cycle(vector<vector<int> > &adj, bool visited[], bool revisited[], int v){
  if(visited[v]==false){
    visited[v] = true;
    revisited[v] = true;
    vector<int>::iterator itr;
    for(itr = adj[v].begin(); itr!=adj[v].end();itr++){
      if(!visited[*itr]  && check_cycle(adj, visited, revisited, *itr )){
        return true;
      }
      else if (revisited[*itr]){
        return true;
      }
    }
  }
  revisited[v] = false;
  return false;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  bool *visited = new bool[adj.size()];
  bool *revisited = new bool[adj.size()];
  for(int i=0;i<adj.size();i++){
    visited[i] = false;
    revisited[i] = false;
  }
  for(int i=0;i<adj.size();i++){
    if(check_cycle(adj, visited, revisited, i)){
      return 1;
    }
  }
  return 0;
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
  std::cout << acyclic(adj);
}
