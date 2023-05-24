#include<bits/stdc++.h>
using namespace std;
const int N = 0;

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

//Idea for Fast Diameter is: You are calculating height and diameter at run time/ simultaneously and
//hence the order of complexity reduces.

//In order to store the info for every node : Do i know a data ??

//STL:

class Pair2 {
public:
	int height;
	int diameter;
};


Pair2 fastdiameter(node* root) {
	Pair2 p;

	if (root == NULL) {
		p.height = 0;
		p.diameter = 0;
		return p;
	}


	Pair2 left_subtree = fastdiameter(root->left);
	Pair2 right_subtree = fastdiameter(root->right);

	p.height = max(left_subtree.height, right_subtree.height) + 1;

	p.diameter = max({left_subtree.diameter, right_subtree.diameter,
	                  left_subtree.height + right_subtree.height
	                 });

	return p;
}

//pair<int,int>x===x.first==height and x.second==diamter


pair<int, int>fastdiameter2(node* root) {
	pair<int, int>p;

	if (root == NULL) {
		p.first = 0;
		p.second = 0;
		return p;
	}

	pair<int, int> left_subtree = fastdiameter2(root->left);

	pair<int, int> right_subtree = fastdiameter2(root->right);

	p.first = max(left_subtree.first, right_subtree.first) + 1;

	p.second = max({left_subtree.second, right_subtree.second,

	                left_subtree.first + right_subtree.first
	               });

	return p;
}

class Pair3 {
public:

	int height;
	int isbalanced;
};

Pair3 isheightbalanced(node* root) {

	Pair3 p;
	if (root == NULL) {
		p.isbalanced = true;
		p.height = 0;
		return p;
	}

	Pair3 left_subtree = isheightbalanced(root->left);
	Pair3 right_subtree = isheightbalanced(root->right);

	p.height = max(left_subtree.height, right_subtree.height) + 1;

	if (left_subtree.isbalanced == 1 and right_subtree.isbalanced == 1
	        and abs(left_subtree.height - right_subtree.height) <= 1) {
		p.isbalanced = true;
	} else {
		p.isbalanced = false;
	}

	return p;
}

// ~O(no of nodes): O(n): computations : bach

node* buildTreefromArray(int* a, int s, int e) {
	if (s > e) {
		return NULL;
	}

	int mid = (s + e) / 2;
	//a[mid]===pehle apne data type me store karna hain.

	node* n = new node(a[mid]);

	n->left = buildTreefromArray(a, s, mid - 1);
	n->right = buildTreefromArray(a, mid + 1, e);

	return n;
}


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

	Pair2 x = fastdiameter(root);

	//x--> tree ke diameter ki and tree ki height ki

	cout << x.height << " " << x.diameter << endl;

	pair<int, int>x2 = fastdiameter2(root);

	cout << x2.first << " " << x2.second << endl;

	Pair3 x3 = isheightbalanced(root);
	cout << x3.height << " " << x3.isbalanced << endl;

	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

	node* root2 = buildTreefromArray(a, 0, 10);

	Preorder(root2);
	cout << endl;
	Pair3 x4 = isheightbalanced(root2);
	cout << x4.height << " " << x4.isbalanced << endl;


}


