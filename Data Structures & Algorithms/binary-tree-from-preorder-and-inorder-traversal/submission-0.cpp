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
private:
    unordered_map<int, int> inMap;
    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd){
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot=inMap[root->val];
        int numsLeft=inRoot-inStart;

        root->left=helper(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1);
        root->right=helper(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if(preorder.empty() || inorder.empty()) return nullptr;

        for(int i=0; i<n; i++) inMap[inorder[i]]=i;
        
        return helper(preorder, 0, n-1, inorder, 0, n-1);
    }
};