#include <bits/stdc++.h>
using namespace std;

class edge{
    
    public:
    int src,dst,w;
};

class Graph{
    
     public:
    int v,e;
    edge *ed;
    
   
    Graph(int v,int e){
        this->v = v;
        this->e = e;
    }
};

Graph* createGraph(int v,int e){
    Graph *g = new Graph(v,e);
    g->ed = new edge[v];
    return g;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        Graph *g = createGraph(v,e);
        for(int i=0;i<e;i++){
            int x,y,z;
            cin>>x>>y>>z;
            g->ed[i].src = x;
            g->ed[i].dst = y;
            g->ed[i].w = z;
        }
        int dis[v];
        for(int i=0;i<v;i++){
            dis[i] = INT_MAX;
        }
        dis[0] = 0;
        
        for(int i=0;i<v-1;i++){
          for(int j=0;j<e;j++){
              int u= g->ed[j].src;
              int v = g->ed[j].dst;
              int w = g->ed[j].w;
              
              if(dis[u]!= INT_MAX && dis[u]+w <dis[v]){
                  dis[v] = dis[u] + w;
              }
          }
        }
        
        int flag = 0;
        for(int i=0;i<e;i++){
            int u= g->ed[i].src;
            int v = g->ed[i].dst;
            int w = g->ed[i].w;
            
            if(dis[u]!= INT_MAX && dis[u]+w < dis[v]){
                flag = 1;
            }
        }
        
        if(flag == 1){
            cout<<"1"<<endl;
            
        }
        else{
            cout<<"0"<<endl;
        }
        
    }
	//code
	return 0;
}