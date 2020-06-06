#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  vector<int>d(adj.size(),-1);
  vector<bool> visited(adj.size(),false);
  queue<int> q;
  q.push(s);
  d[s]=0;
  while(!q.empty()){
    int k=q.front();
    q.pop();
    visited[k]=true;
    vector<int> :: iterator itr;
      for(itr=adj[k].begin();itr!=adj[k].end();itr++){
        if(d[*itr]==-1){
          d[*itr] = 1+ d[k];
        // if(!visited[*itr]){   //this code also works
        //   if(d[*itr]!=0){
        //     d[*itr] = min(d[*itr],d[k]+1);
        //   }
        //   else{
        //     d[*itr] = d[k]+1;
        //   }
        q.push(*itr);
      }
    }
  }
  if(d[t]!=0){
    return d[t];
  }
  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
