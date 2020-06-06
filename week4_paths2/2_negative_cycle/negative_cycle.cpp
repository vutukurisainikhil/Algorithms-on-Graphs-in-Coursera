#include <iostream>
#include <vector>
#include <climits>
using namespace std;

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  vector<int> dist(adj.size(),1000000);  // Adding in INT_MAX doesnt increase so need to change datatype to long or intitialize with value less than INT_MAx; 
  vector<int> prev(adj.size(),0);
  dist[0]=0;
  for(int i=0;i<adj.size();i++){
    for(int j=0;j<adj.size();j++){
      for(int itr=0; itr<adj[j].size();itr++){
          //cout<<"j-"<<j<<"  itr-"<<adj[j][itr]<<endl;
          //cout<<dist[adj[j][itr]]<<">"<<dist[j]<<"+"<<cost[j][itr]<<endl;
          if(dist[adj[j][itr]] > dist[j] +cost[j][itr] ){
            dist[adj[j][itr]] = dist[j] +cost[j][itr];
            prev[adj[j][itr]] = j;
          if(i==(adj.size()-1)){
              return 1;
          }
        }
      }
    }
  }
  return 0;
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
  std::cout << negative_cycle(adj, cost);
}
