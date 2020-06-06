#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, int i, bool visited[]){
  visited[i]=true;
  vector<int>::iterator itr;
    for(itr=adj[i].begin();itr!=adj[i].end();itr++){
        if(!visited[*itr]){
          dfs(adj, *itr , visited);
        }
    }
}


int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
  bool *visited = new bool[adj.size()];
  for(int i=0;i<adj.size();i++){
    visited[i]=false;
  }
  for(int i=0;i<adj.size();i++){
    
    if(!visited[i]){
        res++;
        dfs(adj, i, visited);   
    }
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
