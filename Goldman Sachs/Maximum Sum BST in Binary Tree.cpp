//link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
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
    struct data{
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int sum=0;
        bool bst=true;
    };
    data solve(TreeNode* root, int &ans){
        if(root==NULL){
            data t;
            return t;
        }
        data l = solve(root->left, ans);
        data r = solve(root->right, ans);
        
        if(l.bst && r.bst && l.maxi<root->val && r.mini>root->val){
            ans = max(ans, (root->val+l.sum+r.sum));
            return {max(root->val,r.maxi),min(root->val,l.mini),(root->val+l.sum+r.sum),true};
        }
        return {max(root->val,r.maxi),min(root->val,l.mini),(root->val+l.sum+r.sum),false};
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        auto t = solve(root, ans);
        return ans;
    }
};
