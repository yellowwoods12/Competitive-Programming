#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define fill1d(x,val) memset(x,val,sizeof(x))
#define fill2d(x,val) fill_n(*x, sizeof(x)/sizeof(**x),val);
using namespace std;


class Graph{
    int v;
    list<int> *adj;
    
    public:
    
    Graph(int s){
        v = s;
        adj = new list<int>[s];
    }
    void addEdge(int u,int v){
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    
    int longestPathLength();
    
    pair<int,int> bfs(int);
};


pair<int,int> Graph::bfs(int root){
    
    int visited[v];
    memset(visited,-1,sizeof(visited));
    
   queue<int> q;
   q.push(root);
   visited[root] = 0;
   while(!q.empty()){
       
       int top = q.front();
       q.pop();
       
       for(auto it = adj[top].begin();it!= adj[top].end();it++){
           
           int l = *it;
           if(visited[l] == -1){
               q.push(l);
               visited[l] = visited[top] +1;
           }
       }
   }
  
   int maxd = 0;
   int idx;
   for(int i=0;i<v;i++){
    //   cout<<visited[i]<<" ";
       if(maxd < visited[i]){
           maxd = visited[i];
           idx = i;
          // cout<<maxd<<" ";
       }
   }
   
   return make_pair(idx,maxd);
}
int Graph::longestPathLength(){
    
    pair<int,int> p1 = bfs(0);
    
    pair<int,int> p2 = bfs(p1.first);
    
    return p2.second;
}

int main() 
{ 
    // Create a graph given in the example 
    Graph g(10); 
    g.addEdge(0, 1); 
    g.addEdge(1, 2); 
    g.addEdge(2, 3); 
    g.addEdge(2, 9); 
    g.addEdge(2, 4); 
    g.addEdge(4, 5); 
    g.addEdge(1, 6); 
    g.addEdge(6, 7); 
    g.addEdge(6, 8); 
  
    cout<<g.longestPathLength(); 
    return 0; 
} 