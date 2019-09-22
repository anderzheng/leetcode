/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* recursion method */
bool isSymmetricTree(struct TreeNode *t1, struct TreeNode *t2)
{
    if (t1 == NULL && t2== NULL)
        return true;
    if (t1 == NULL || t2 == NULL)
        return false;
    
    if (t1->val != t2->val)
        return false;
    else
        return isSymmetricTree(t1->left, t2->right) && isSymmetricTree(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root){
    
    
    if (NULL == root)
        return true;        // empty tree is symmetric
    
    return isSymmetricTree(root, root);

}

