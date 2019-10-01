/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* using DFS or recursive */

/*  recursive method : passed 12ms */
bool isSumEq(struct TreeNode *root, int sum, int target)
{
    if (NULL == root)
        return false;
    
    sum += root->val;
    if (target == sum && 
       root->left == NULL &&        // notice: need to be a leaf 
       root->right == NULL)
    {
        return true;
    }
    
    return isSumEq(root->left, sum, target) || 
            isSumEq(root->right, sum, target);
}

bool hasPathSum(struct TreeNode* root, int sum){
    if (NULL == root)
        return false;
    
    return isSumEq(root, 0, sum);
}

