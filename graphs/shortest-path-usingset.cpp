#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<pair<int,int>> *adj;
    public:
      
      Graph(int v){
          this->v = v;
          adj = new list<pair<int,int>>[v];
      } 
      
      void addEdge(int u,int v,int w){
          adj[u].push_back({v,w});
          adj[v].push_back({u,w});
      }
      
      void shortestPath(int src){
          set<pair<int,int>> s;
          vector<int> dist(v,INT_MAX);
          
          s.insert({0,src});
          dist[src] = 0;
          
          while(!s.empty()){
              
              pair<int,int> temp = *(s.begin());
              s.erase(temp);
              
              list<pair<int,int>> :: iterator it;
              for(it = adj[temp.second].begin();it != adj[temp.second].end(); it++){
                  
                  int v = (*it).first;
                  int w = (*it).second;
                  if(dist[v]> dist[temp.second]+w){
                      
                      if(dist[v] != INT_MAX){
                          s.erase({dist[v],v});
                      }
                      
                      s.insert({dist[temp.second]+w,v});
                      dist[v] = dist[temp.second]+w;
                  }
              }
          }
          
          for(int i=0;i<dist.size();i++){
              cout<<dist[i]<<" ";
          }
      }
};

int main() 
{ 
    // create the graph given in above fugure 
    int V = 9; 
    Graph g(V); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.shortestPath(0); 
  
    return 0; 
} 