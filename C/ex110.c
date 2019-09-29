/* passed 8ms */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isBalancedTree2(struct TreeNode *root, int *depth)
{
    bool res = false;
    int left=0, right=0;
    if (NULL == root)
    {
        return true;
    }
    
    res = isBalancedTree2(root->left, &left);
    if (!res)
    {
        return res;
    }
    res = isBalancedTree2(root->right, &right);
    if (!res)
    {
        return res;
    }
    
    if (abs(left - right) > 1)
        return false;
    else
    {
        *depth =  left>right? left+1: right+1;        
        return true;
    }
}


/* useing recursive method */
bool isBalanced(struct TreeNode* root){
    int depth = 0;
    
    if (NULL == root)
    {
        return true;
    }
    
    return isBalancedTree2(root, &depth);
}

