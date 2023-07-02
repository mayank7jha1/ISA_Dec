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
    unordered_map<TreeNode*, bool>visited;
    int camera;
public:

    void PlaceCamera(TreeNode* root, TreeNode* parent) {

        if (root == NULL) {
            return;
        }

        PlaceCamera(root->left, root);
        PlaceCamera(root->right, root);


        // (parent == NULL and visited.count(root) == 0) : Edge case: Assume a Tree like this
        //             x
        //         y
        //     z
        // p

        if ( (parent == NULL and visited.count(root) == 0) or visited.count(root->left) == 0 or visited.count(root->right) == 0) {

            camera++;
            visited[root] = 1;
            visited[root->left] = 1;
            visited[root->right] = 1;
            visited[parent] = 1;

        }

    }

    int minCameraCover(TreeNode* root) {
        camera = 0;
        visited.insert({NULL, true});//Leave Node par kabhi camera nahi lagege

        PlaceCamera(root, NULL);
        return camera;

    }
};

