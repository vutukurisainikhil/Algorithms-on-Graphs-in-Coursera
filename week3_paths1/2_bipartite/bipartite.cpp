#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

bool check_bipartite(vector<vector<int>> &adj, vector<int> &color, int v){
  color[v] = 1;
  queue<int> q;
  q.push(v);
  while(!q.empty()){
    int k=q.front();
    q.pop();
    vector<int>:: iterator itr;
    for(itr=adj[k].begin();itr!= adj[k].end();itr++){
      if(*itr==k){
        return false;
      }
      if(color[*itr]==-1){
        q.push(*itr);
        color[*itr] = 1 - color[k];
      }
      else if(color[*itr]==color[k]){
        return false;
      }
    }
  }
  return true;
}

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector<int> color(adj.size(),-1);
  for(int i=0;i<adj.size();i++){
    if(color[i]==-1){
        if(!check_bipartite(adj, color, i)){
        return 0;
        }
    }
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
