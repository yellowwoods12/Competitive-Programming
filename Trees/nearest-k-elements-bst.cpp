//problem link : https://www.lintcode.com/problem/closest-binary-search-tree-value-ii/description


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
     
    int returnclosest(vector<int> sorted, double t){
        int s= 0;
        int e = sorted.size()-1;
        int mid;
        int pos =sorted.size();
        while(s<=e){
            mid = (s+e)/2;
            
            if(sorted[mid]>t){
               pos = mid;
               e = mid-1;
            }
           else{
             s= mid+1;
              
            }
                
        }
        return pos;
    }
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        
        vector<int> sorted;
        stack<TreeNode*> st;
        if(root == NULL)
          return {};
          
    
        TreeNode *temp = root;
        
        while(temp!= NULL || !st.empty() ){
            
            
            
             while(temp != NULL)
             {
                 st.push(temp);
                 temp = temp->left;
             }
             
            temp = st.top();
            st.pop();
            sorted.push_back(temp->val);
        
                temp = temp->right;
            
            
        }
         int closest = returnclosest(sorted,target);
         
         int ptr1 = closest-1;
         int ptr2 = closest;
        vector<int> result;
        while(k>0){
            if(ptr1 == -1){
                result.push_back(sorted[ptr2++]);
            }
            else if(ptr2 == sorted.size()){
                result.push_back(sorted[ptr1--]);
            }
            else{
                double leftval = abs(target - sorted[ptr1]);
                double rightval = abs(target - sorted[ptr2]);
                if(leftval<rightval){
                    result.push_back(sorted[ptr1--]);
                }
                else{
                    result.push_back(sorted[ptr2++]);
                }
            }
            k--;
        }
         
         return result;
        // write your code here
    }
};