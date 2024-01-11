//link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        
        return 1+max(height(root->right), height(root->left));
    }

    int solve(TreeNode* root, int &start, int &ans) {
        if(root==NULL)
            return -1;

        if(root->val==start){
            ans = max(height(root->left), height(root->right));
            return 1;
        }    

        int t = solve(root->left, start, ans);
        if(t!=-1){
            ans = max(ans, t+height(root->right));
            return t+1;
        }

        t = solve(root->right, start, ans);
        if(t!=-1){
            ans = max(ans, t+height(root->left));
            return t+1;
        }
        return -1;
    }

    int amountOfTime(TreeNode* root, int target) {
        int maxi = 0;
        int s = solve(root, target, maxi);
        return maxi;
    }
};
