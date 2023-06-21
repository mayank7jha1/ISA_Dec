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

    vector<int>Path_In_Consideration;
    vector<vector<int>>ans;


public:


    void FindPath(TreeNode* root, int sum) {

        if (root == NULL) {
            return;
        }

        Path_In_Consideration.push_back(root->val);

        if (root->val == sum and !root->left and !root->right) {
            ans.push_back(Path_In_Consideration);
        } else {

            FindPath(root->left, sum - root->val);
            FindPath(root->right, sum - root->val);

        }

        Path_In_Consideration.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        FindPath(root, targetSum);
        return ans;
    }
};



// 5->4->11->?
// sum=2: node->val=2