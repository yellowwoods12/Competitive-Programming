//question link : https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0)
            return 0;
        if(n==1)
            return heights[0];
        stack<int> st;
        int curarea = 0, maxarea =0;
        for(int i=0;i<n;i++){
            
            while(!st.empty() && heights[st.top()]>= heights[i]){
                int toph = st.top();
                st.pop();
                int len = i;
                if(st.size()>0){
                    len = len - st.top() -1;
                }
               curarea = heights[toph]* len;
             maxarea = max(maxarea,curarea);
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int toph = st.top();
            st.pop();
            int len = n;
            if(st.size() > 0){
                len = len - st.top() -1;
            }
             curarea = heights[toph]* len;
             maxarea = max(maxarea,curarea);
        }
        
        return maxarea;
    }
};