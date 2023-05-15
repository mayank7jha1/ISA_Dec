#include<bits/stdc++.h>
using namespace std;
const int N = 0;

//Creating our own DSA: Hashmap: Run

//We will create this hashmap as generic
//Create the structure for the node:

class node {
public:
	int value;
	string key;

	//Ye apne jaise ek node ko point
	node *next;

	//Constructor:

	node(string s, int d) {
		key = s;
		value = d;
		next = NULL;
	}
};


class hashtable {
	node * *table;
	//ek dynamic array jo address ko store karta hain for the first linked list
	//vaali node ke: ye address ko store karta hain of node* type
	int table_size;
	int current_size;


	//Hash Function

	int hashfunction(string key) {
		//Prime Number: 23
		int multiply = 1;
		int sum = 0;

		for (int i = 0; i < key.length(); i++) {

			sum += ((key[i] % table_size) *
			        (multiply % table_size)) % table_size;

			multiply = multiply * 23;
			multiply = multiply % table_size;
		}

		sum = sum % table_size;
		return sum;
	}

public:

	//Constructor:

	hashtable(int size = 15) {
		table_size = size;
		current_size = 0;

		table = new node*[table_size];

		// int *a;
		// a = new int[100];


		for (int i = 0; i < table_size; i++) {
			table[i] = NULL;
		}
	}
};

// ascii * 23 ^ 0 + acii * 23 ^ 1 + ______ _ _ _ _ _.

/*
	Above is the DSA we are creating and
	it will store the address of the
	node/structure (in the form ll) we have created from line 8-23.
*/


/*
	table kya store karti hain?

	Address of the node( jo aapne upar line 8 me banaya).

	table ko main ek dynamic array ki tarah banaunga

	int* a=new int[100];

	*table;// Ye hain ek pointer jo point kar raha hain
	//kisko--> us array ko aapke node ke first address ko
	//store karta hain.

	//size double karna padega


*/

int main() {

}