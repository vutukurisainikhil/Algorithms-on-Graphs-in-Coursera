#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility> 

using namespace std;


void distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s=0) {
  //write your code her
  int result= 0;
  int count = 0;
  vector<int> dis(adj.size(), INT_MAX);
  //vector<int> prev(adj.size(), -1);  //parent
  vector<bool> inMST(adj.size(),false);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
  pq.push(make_pair(0,s));
  dis[s]=0;
  cout<<"MST order";
  while(!pq.empty()){
    pair<int,int> k = pq.top();
    int u = k.second;
    int u_w = k.first;
    pq.pop();
    inMST[u]=true;
    if( count< adj.size()){    //MST Path and total result is caluclated here
        result = result+ int(k.first);
        cout<<k.second<<" ";
    }
    // this is used to push the correspoing edges with respect to u..into priority queue;
    for(int itr=0; itr<adj[u].size();itr++){
      int w = cost[u][itr];
      int v = adj[u][itr];
      if(inMST[v]==false  && dis[v] > w)
      {
        dis[v] = w;
        //cout<<"pushing.."<<dis[v]<<endl;
        pq.push(make_pair(dis[v], v));
        prev[v] = u;  //Parent (or) finding the path from END vertex to start by iterating backwards ;
      }
    }
    count++;
  }
  cout<<endl;
  cout<<"total - "<<result<<endl;
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
  std::cin >> s;
  s--;
  distance(adj, cost, s);
}
