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
	cout << root->data << ",";

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

node* buildTreefromArray(int* a, int s, int e) {
	if (s > e) {
		return NULL;
	}

	int mid = (s + e) / 2;
	node* n = new node(a[mid]);

	n->left = buildTreefromArray(a, s, mid - 1);
	n->right = buildTreefromArray(a, mid + 1, e);

	return n;
}


void printkthlevel(node* root, int k) {

	if (root == NULL) {
		return;
	}

	//Kaam karna hain.
	if (k == 1) {
		cout << root->data << " ";
		return;
	}

	printkthlevel(root->left, k - 1);
	printkthlevel(root->right, k - 1);
}

//Print all the level of the tree: Print the tree level by level.
//O(n^2): Tree height: No of nodes hojaaye

void printAllLevel(node* root) {
	int H = height(root); //O(no of nodes)

	for (int i = 1; i <= H; i++) {//1 se n tak aap koi kaam karo

		printkthlevel(root, i);//Ye kaam kitni time complexity O( no of nodes)
		cout << endl;
	}
}


void bfs(node* root) {
	queue<node*>q;

	q.push(root);

	while (!q.empty()) {

		node* Infront = q.front();
		cout << Infront->data << " ";
		q.pop();

		if (Infront->left != NULL) {
			q.push(Infront->left);
		}

		if (Infront->right != NULL) {
			q.push(Infront->right);
		}
	}
}


void bfs2(node* root) {
	queue<node*>q;

	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* Infront = q.front();

		if (Infront == NULL) {
			cout << endl;
			q.pop();

			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << Infront->data << " ";
			q.pop();
			if (Infront->left != NULL) {
				q.push(Infront->left);
			}

			if (Infront->right != NULL) {
				q.push(Infront->right);
			}
		}
	}
}

// int i = 0;
node* buildTreefrompreandin(int* in, int* pre, int s, int e) {
	if (s > e) {
		return NULL;
	}

	static int i = 0;
	node* root = new node(pre[i]);

	int index = -1;

	for (int j = s; j <= e; j++) {
		if (in[j] == pre[i]) {
			index = j;
			break;
		}
	}

	//root->left===s--->index-1
	//root->right===index+1--->e

	i++;

	root->left = buildTreefrompreandin(in, pre, s, index - 1);
	root->right = buildTreefrompreandin(in, pre, index + 1, e);

	return root;
}


void printLeftView(node* root, int level, int &maxlevel) {
	if (root == NULL) {
		return;
	}

	if (maxlevel < level) {
		cout << root->data << " ";
		maxlevel = level;
	}

	printLeftView(root->left, level + 1, maxlevel);

	printLeftView(root->right, level + 1, maxlevel);
}

void printRightView(node* root, int level, int &maxlevel) {
	if (root == NULL) {
		return;
	}

	if (maxlevel < level) {
		cout << root->data << " ";
		maxlevel = level;
	}

	printRightView(root->right, level + 1, maxlevel);

	printRightView(root->left, level + 1, maxlevel);

}


//Top View of a Tree (H.W.)

node* InsertAtBST(node* &root, int value) {

	if (root == NULL) {
		root = new node(value);
		return root;
	}

	//Varna aapko correct position dhundni hain value ki
	//is bst me:

	if (value < root->data) {
		root->left = InsertAtBST(root->left, value);
	}

	if (value > root->data) {
		root->right = InsertAtBST(root->right, value);
	}

	return root;
}

node* buildbst() {
	int x;
	cin >> x;

	node* root = NULL;

	while (x != -1) {
		//cout << x << " ";
		root = InsertAtBST(root, x);
		cin >> x;
	}
	return root;
}

bool searchinbst(node* root, int key) {

	if (root == NULL) {
		return false;
	}


	if (root->data == key) {
		return true;

	} else if (root->data < key) {

		return searchinbst(root->right, key);

	} else {

		return searchinbst(root->left, key);
	}
}



int main() {
	//node* root = buildTree();
	//Preorder(root);
	// cout << endl;
	// Inorder(root);
	// cout << endl;
	// Postorder(root);
	// cout << endl;

	// cout << Countnodes(root) << " " << SumofNodes(root) << endl;
	// cout << height(root) << endl;
	// Mirror(root);
	// Preorder(root);
	// cout << endl;
	// cout << Diameter(root) << endl;

	// Pair2 x = fastdiameter(root);
	// cout << x.height << " " << x.diameter << endl;

	// pair<int, int>x2 = fastdiameter2(root);

	// cout << x2.first << " " << x2.second << endl;

	// Pair3 x3 = isheightbalanced(root);
	// cout << x3.height << " " << x3.isbalanced << endl;

	// int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

	// node* root2 = buildTreefromArray(a, 0, 10);

	// Preorder(root2);
	// cout << endl;
	// Pair3 x4 = isheightbalanced(root2);
	// cout << x4.height << " " << x4.isbalanced << endl;


	// int k;
	// cin >> k;
	// printkthlevel(root, k);
	// cout << endl;
	// printAllLevel(root);
	// bfs(root);
	// cout << endl;
	//bfs2(root);
	//cout << endl;


	// int pre[] = {8, 10, 1, 16, 9, 17, 3, 14, 13};
	// int in[] = {1, 10, 9, 16, 17, 8, 3, 13, 14};

	// node* root3 = buildTreefrompreandin(in, pre, 0, 8);

	// int maxlevel = -1;
	// printLeftView(root, 0, maxlevel);
	// cout << endl << endl;
	// int maxlevel2 = -1;
	// printRightView(root, 0, maxlevel2);


	node* root2 = buildbst();
	Inorder(root2);
	cout << endl;
	int key;
	cin >> key;
	cout << searchinbst(root2, key) << endl;;
}


//Bit Manipulation

//Stacks Queue Priority Queue Deque
//Maths and Number Theory (Prime Seive and Segmented Seive) and Bitmasking
//CP me jada
//DP start:
//Graph: