//link: https://leetcode.com/problems/trim-a-binary-search-tree/description/
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL)
            return NULL;
        
        if(root->val<low)
            root = trimBST(root->right, low, high);
        else if(root->val>high)
            root = trimBST(root->left, low, high);
        else{
            root->left =  trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        return root;
    }
};
