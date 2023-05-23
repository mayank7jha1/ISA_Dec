#include<bits/stdc++.h>
using namespace std;
const int N = 0;

//Nodes connected in an hierarachical structure is tree;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int inputdata) {
		data = inputdata;
		left = NULL;
		right = NULL;
	}

};


node* buildTree() {
	int x;
	cin >> x;

	if (x == -1) {
		return NULL;
	} else {
		// Data is x = 8: isko node ke form me store karna hain.
		//8 ka input lo : 8->left recursiion
		//8-->right:  recursion
		//8 ko return kardo

		node* n = new node(x);
		n->left = buildTree();
		n->right = buildTree();

		return n;
	}
}


void Preorder(node* root) {
	if (root == NULL) {
		return;
	}

	//Root:
	cout << root->data << " ";

	Preorder(root->left);

	Preorder(root->right);
}

void Inorder(node* root) {
	if (root == NULL) {
		return;
	}


	Inorder(root->left);
	//Root:
	cout << root->data << " ";

	Inorder(root->right);
}

void Postorder(node* root) {
	if (root == NULL) {
		return;
	}


	Postorder(root->left);

	Postorder(root->right);

	//Root:
	cout << root->data << " ";
}

//Now You have understood how to traverse on a binary tree.
//Total Number of Nodes in a Tree?


int Countnodes(node* root) {

	if (root == NULL) {
		return 0;
	}

	int left_side = Countnodes(root->left);
	int right_side = Countnodes(root->right);

	int ans = left_side + right_side + 1;

	return ans;
}

int SumofNodes(node* root) {
	if (root == NULL) {
		return 0;
	}

	int left_side_sum = SumofNodes(root->left);
	int right_side_sum = SumofNodes(root->right);

	int ans = left_side_sum + right_side_sum + root->data;
	return ans;
}

int height(node* root) {

	if (root == NULL) {
		return 0;
	}

	int left_subtree_height = height(root->left);
	int right_subtree_height = height(root->right);

	int ans = max(left_subtree_height, right_subtree_height) + 1;
	return ans;

}


//Mirror of the Tree
void Mirror(node* root) {
	if (root == NULL) {
		return;
	}

	swap(root->left, root->right);
	Mirror(root->left);
	Mirror(root->right);
}


int Diameter(node* root) {
	if (root == NULL) {
		return 0;
	}

	int option1 = Diameter(root->left);
	int option2 = Diameter(root->right);

	//Height of left subtree and right subtree gives us op3 diameter
	int option3 = height(root->left) + height(root->right);

	return max({option1, option3, option2});
}

//For evry node you are calculating the height of that node sepatedly and hence
//if there are n nodes and height caculation process in itself takes
//O(n) time then the overall time would be n(fo no. of nodes) * O(n) (for height)  i.e. O(n*n)==O(n^2).


int main() {
	node* root = buildTree();
	Preorder(root);
	cout << endl;
	Inorder(root);
	cout << endl;
	Postorder(root);
	cout << endl;

	cout << Countnodes(root) << " " << SumofNodes(root) << endl;
	cout << height(root) << endl;
	Mirror(root);
	Preorder(root);
	cout << endl;
	cout << Diameter(root) << endl;
}



//Function call is over : changes main ke ander reflect nahi hote na
//tum chahte ho ki ye tree mirror image bann jaaye


//H.W. Please try to solves diameter in O(n) time without looking on internet.