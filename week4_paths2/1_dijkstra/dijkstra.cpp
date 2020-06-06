#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility> 

using namespace std;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  vector<int> dis(adj.size(), INT_MAX);
  vector<int> prev(adj.size(), -1);
  priority_queue<pair<int,int>> pq;
  pq.push(make_pair(0,s));
  dis[s]=0;
  while(!pq.empty()){
    pair<int,int> k = pq.top();
    int u = k.second;
    pq.pop();
    //vector<int>:: iterator itr;
    for(int itr=0; itr<adj[u].size();itr++){
      int w = cost[u][itr];
      int v = adj[u][itr];
      if(dis[v] > dis[u]+w){
        dis[v] = dis[u]+ w;
        pq.push(make_pair(dis[v], v));
        prev[v] = u;  //finding the path from end to start by iterating backwards;
      }
    }
  }
  if(dis[t] == INT_MAX){
    return -1;
  }
  return dis[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
