/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/* using recursion method (DFS) */
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL || q == NULL)
    {
        if (p == q)
            return true;
        else 
            return false;
    }
    
    if (p->val == q->val)
    {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    else
        return false;
    
}

