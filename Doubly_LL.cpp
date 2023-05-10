#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class node {

public:
	int data;
	node *next;
	/*Type kya hoga :: Pointer ka type vo hota hain jis type ke data ko vo
	point karta hain //Self Referencing Pointer*/
	node* prev;

	node(int inputdata) {
		data = inputdata;
		prev = NULL;
		next = NULL;
	}
};

void ReverseLL(node* &head) {


	node* p = NULL;
	node* current = head;

	while (current != NULL) {
		p = current->prev;
		current->prev = current->next;
		current->next = p;

		//Aage badhna hain
		current = current->prev;
	}

	//Tumhari LL reverse ho chuki hain.
	if (p != NULL) {//Agar ll khali thi toh reverse kaise karoge?
		head = p->prev;
	}

}

void InsertAtHead(node* &head, int inputdata) {
	node* n = new node(inputdata);//Constructor

	// node* n = new node();
	// n->data = inputdata;

	n->prev = NULL;
	n->next = head;

	if (head != NULL) {
		head->prev = n;
	}

	head = n;
}

int length(node* head) {
	int ans = 0;
	while (head != NULL) {
		ans++;
		head = head->next;
	}
	return ans;
}

void Print(node* head) {
	while (head != NULL) {

		cout << head->data << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
}

//Insert at head in LL;

int main() {
	node* head = NULL;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		InsertAtHead(head, x);
	}

	Print(head);
	cout << length(head) << endl;

	ReverseLL(head);
	Print(head);
}


//50 40 30 20 10

/*
	10->20->30->40->50->NULL;

*/


//H.W. Functions : Saare Doubly LL.
//Singly LL Function : Try DLL.


//STL: