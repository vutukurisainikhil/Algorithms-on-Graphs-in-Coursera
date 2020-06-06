#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
using std::vector;
// The algorithm is very simple, but first we need to understand the following things:
//
// 1. Some points are given in the plane, with their x and y coordinates. The graph is not
// given directly, so we need to assume that the graph is given implicitly.
//
// 2. We need to connect using minimum cable, so it means that all the nodes are reachable
// from each other and then we need to find the minimum spanning tree.
//
// 3. Weights of each edge is also not given directly, we need to apply the simple formula
// and calculate the weight of each edge.
//
// So as the preprocessing step, we need to create the graph with all the edges having the
// weights.
//
// Next we can apply for kruskal algorithm using rank, which needs the notion of a node
// having a rank and a parent.
struct edge{
  int u,v; //points u(x1,y1) and v(x2,y2) 
  double weight;
  edge(int a,int b, double c){
    u=a;
    v=b;
    weight=c;    
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
    parent = c;
    rank  = d;
  }
};

double distance(int x1, int y1, int x2,int y2){
  double k = pow(x1-x2,2)+ pow(y2-y1,2);
  return sqrt(k);
}

bool cmp(edge e1, edge e2){
  return e1.weight < e2.weight;  //ascending order
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
      nodes[r2].parent=r1;
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

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  vector<node> nodes;    //creating all Nodes with (x,y) points in order i;
  for(int i=0;i<y.size();i++){
    nodes.push_back(node(x[i],y[i],i));
  }
  
  vector<edge> edges;
  for(int i=0;i<x.size();i++){
    for(int j=0;j<y.size();j++){
      edges.push_back(edge(i,j,distance(x[i],y[i],x[j],y[j])));
    }
  }
  sort(edges.begin(),edges.end(),cmp);
  for(int i=0;i<edges.size();i++){
    edge current_edge = edges[i];
    if(find(current_edge.u, nodes)!= find(current_edge.v, nodes)){
      result += current_edge.weight;
      union_graph(current_edge.u, current_edge.v, nodes);
    }
  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
