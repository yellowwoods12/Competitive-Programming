class Solution {
public:
    
    void util(vector<int> adj[],bool visited[],stack<int> &st,int u){
        
        visited[u] = true;
        
        for(auto it = adj[u].begin();it!=adj[u].end();it++){
            
           if(!visited[*it]){
               util(adj,visited,st,*it);
           }
        }
        
        st.push(u);
       
    }
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        
        int n = numCourses;
        vector<int> vis(n);
        
       vector<int> adj[n];
        
        for(int i=0;i<p.size();i++){
            adj[p[i][0]].push_back(p[i][1]);
        }
        
        bool visited[n];
        memset(visited,false,sizeof(visited));
       
        stack<int> st;
       
        for(int i=0;i<n;i++){
            
            if(!visited[i]){
              util(adj,visited,st,i);
        }
        }
        
        vector<int> pos(n);
        int index = 0;
        
        while(!st.empty()){
            pos[st.top()] = index;
            st.pop();
            index++;
        }
        for(int i=0;i<n;i++){
            for(auto it = adj[i].begin(); it!=adj[i].end();it++){
                if(pos[*it] < pos[i])
                    return false;
            }
        }
        return true;
    }
};