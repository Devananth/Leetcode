/*
Problem  :  Given the root of a binary tree, return the sum of values of its deepest leaves.


Appoach : 

    Recursive way : i)  Find the max Depth 
                    ii) Now , find the sum of nodes at that depth
                    
                    TimeComplexity : O(N) + O(N)
                    SpaceComplexity : O(1)
                    
    Iterative way : i) Doing level order traversal and finding sum if queue is empty then previous sum would be the answer.
    
                    TimeComplexity : O(N)
                    SpaceComplexity : O(N)
      
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        
        int sum = 0 ;
        
        queue<TreeNode*> qu;
        
        qu.push(root);
        
        while(!qu.empty())
        {
            int len = qu.size();
            
            sum = 0 ;
            
            for(int i = 0 ; i<len ; i++)
            {
                auto it = qu.front();
                
                sum+=it->val;
                
                if(it->left)
                    qu.push(it->left);
                
                if(it->right)
                    qu.push(it->right);
                
                qu.pop();
                
            }
        }
        
        return sum ;
        
    }
};
