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
  void dfs(TreeNode * root, double target, int k, priority_queue<pair<double,TreeNode*>>& maxH){
        
        if(!root) return;
        
        dfs(root->left,target,k,maxH);
        if(root){
            maxH.push({abs(root->val-target),root});
            if(maxH.size()>k)
                maxH.pop();
        }
        dfs(root->right,target,k,maxH);
    } 
     
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        priority_queue<pair<double,TreeNode*>> maxH; 
        if(!root) return {};
        vector<int> ans;
        dfs(root,target,k,maxH);
        while(maxH.size()>0){
            ans.push_back(maxH.top().second->val);
            maxH.pop();
        }
        return ans;
    }
};