/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* recursion method: passed 8ms */
int maxDepth(struct TreeNode* root){
    int maxL = 0, maxR = 0;
    if (NULL == root)
        return 0;
    
    if (NULL == root->left && NULL == root->right)
        return 1;
  
    maxL =  maxDepth(root->left);
    maxR =  maxDepth(root->right);
    return 1+(maxL> maxR? maxL:maxR);       // notice: need +1 
}

