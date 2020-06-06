#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;
using std::vector;
using std::pair;

struct edge{
  int u;
  int v;
  double weight;
  edge(int a, int b, double c){
    u=a;
    v=b;
    weight =c;
  }
};

struct node{
  int x;
  int y;
  int parent;
  int rank;
  node(int a, int b, int c=-1, int d=0){
    x=a;
    y=b;
    parent =c;
    rank =d;
  }
};
double distance(int x1,int y1,int x2,int y2){
  return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

bool cmp (edge e1, edge e2){
  return e1.weight<e2.weight;
}

int find(int i, vector<node> &nodes){
  if(i!=nodes[i].parent){
    nodes[i].parent = find(nodes[i].parent, nodes);
  }
  return nodes[i].parent;
}

void union_graph(int u, int v, vector<node> &nodes){
  int r1 = find(u, nodes);
  int r2 = find(v, nodes);
  if(r1!=r2){
    if(nodes[r1].rank > nodes[r2].rank){
      nodes[r2].parent = r1;
    }
    else if(nodes[r1].rank < nodes[r2].rank){
      nodes[r1].parent = r2;
    }
    else{
      nodes[r1].parent = r2;
      nodes[r2].rank++;
    }
  }
}

double clustering(vector<int> x, vector<int> y, int k) {
  //write your code here
  int count_clusters=0;
  vector<node> nodes;
  vector<edge> edges;
  for(int i=0;i<x.size();i++){
    nodes.push_back(node(x[i],y[i],i));
  }
  for(int i=0;i<x.size();i++){
    for(int j=0;j<y.size();j++){
      edges.push_back(edge(i,j, distance(x[i],y[i],x[j],y[j])));     
    }
  }
  sort(edges.begin(),edges.end(), cmp);
  for(int i=0;i<edges.size();i++){
    edge current_edge = edges[i];
    if(find(current_edge.u, nodes)!=find(current_edge.v,nodes)){
      count_clusters++;
      union_graph(current_edge.u,current_edge.v, nodes);
      if(count_clusters > x.size()-k){
        return current_edge.weight;
      }
    }
  }
  return -1.;
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
