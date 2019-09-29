/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* recursed method */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct TreeNode *pNode = NULL;
    int left=0, mid=0, right = 0;
    
    if(NULL == nums || numsSize == 0)
    {
        return NULL;
    }
    
    mid = numsSize/2;
    pNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    if (NULL == pNode)
    {
        return NULL;
    }
    pNode->val = nums[mid];
    /* recursed method to get BST */
    pNode->left = sortedArrayToBST(&nums[0], mid);
    pNode->right = sortedArrayToBST(&nums[mid+1], numsSize-mid-1);
    
    
    return pNode;
    
}

