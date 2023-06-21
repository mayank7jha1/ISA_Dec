/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

	unordered_map<TreeNode*, TreeNode*>um;
	unordered_set<TreeNode*>visited;

	void Connect_Parent(TreeNode* root, TreeNode* parent) {

		if (root == NULL) {
			return;
		}

		//Root Left and Right
		//Kaam kaha karte hain: root par hote hain.

		um[root] = parent;
		Connect_Parent(root->left, root);
		Connect_Parent(root->right, root);
	}

	void Dfs(TreeNode* target, int k, vector<int>&ans) {

		if (target == NULL or visited.count(target) == 1) {
			return;
		}

		visited.insert(target);

		if (k == 0) {
			ans.push_back(target->val);
		}

		Dfs(target->left, k - 1, ans);
		Dfs(target->right, k - 1, ans);

		//Uppar: jao and parent se k-1 k nodes nikal lo.
		Dfs(um[target], k - 1, ans);
	}

public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
		vector<int>ans;
		if (root == NULL) {
			return ans;
		}

		//Establish the Node and Parent Connection in Map
		Connect_Parent(root, NULL);

		Dfs(target, k, ans);
		return ans;
	}
};


// Node     Parent
//Node: all the nodes that ar visited
