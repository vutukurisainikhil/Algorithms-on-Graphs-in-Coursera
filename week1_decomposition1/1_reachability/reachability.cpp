#include <iostream>
#include <vector>
#include <iterator>
#include <queue>

using namespace std;


int reach(vector<vector<int> > &adj, int x, int y) {
    //cout<<x<<"-"<<y<<endl;
    vector<int>::iterator itr;
    queue<int> q;
    q.push(x);
    bool *visited = new bool[adj.size()];
    for(int i=0;i<adj.size();i++){
        visited[i]=false;
    }
    visited[x]=true;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        visited[k]= true;
        for(itr = adj[k].begin();itr!=adj[k].end();itr++){
            //cout<<*itr<<endl;
            
            if(*itr==y){
                return 1;
            }
            if(!visited[*itr]){
                q.push(*itr);
            }
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
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
