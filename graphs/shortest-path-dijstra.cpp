#include <bits/stdc++.h>
using namespace std;
#define v 9

int mindis(int dis[],bool grset[]){
    
    int minv = INT_MAX, index;
    for(int i=0;i<v;i++){
        if(minv>dis[i] && grset[i] == false){
            minv = dis[i];
            index =i;
        }
    }
    return index;
}
void dijkstra(int graph[v][v],int src){
    
    int dis[v];
    bool grset[v];
    
    for(int i=0;i<v;i++){
        dis[i] = INT_MAX;
        grset[i] =false;
    }
    
    dis[src] = 0;
    
    for(int i=0;i<v;i++){
        int node = mindis(dis,grset);
        
        grset[node] = true;
        for(int j=0;j<v;j++){
            
            if(!grset[v] && graph[node][j] && dis[node] + graph[node][j] <= dis[j] && dis[node] != INT_MAX){
                dis[j] = dis[node] + graph[node][j];
               
            }
        }
    }
    
    for(int i=0;i<v;i++){
        cout<<dis[i]<<" ";
    }
    
}
int main() 
{ 
    /* Let us create the example graph discussed above */
    int graph[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
} 