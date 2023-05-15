#include<bits/stdc++.h>
using namespace std;
const int N = 0;

template<typename T>
// <>
//Jaha Jaha aapne T likha hoga main jo user mujhe data type batayega main
//t ko usse replace kardungaa:

//Main Sirf Key ko generic bana raha hu

class node {
public:
	int value;
	T key;
	node<T> *next;

	node(T s, int d) {
		key = s;
		value = d;
		next = NULL;
	}
};

template<typename T>
class hashmap {
	node<T> **table;

	int table_size;
	int current_size;

	//Hash Function

	int hashfunction(T key) {
		//Prime Number: 23
		int multiply = 1;
		int sum = 0;

		for (int i = 0; i < key.length(); i++) {

			sum += ((key[i] % table_size) * (multiply % table_size));
			multiply = multiply * 23;
			multiply = multiply % table_size;
		}

		sum = sum % table_size;
		return sum;
	}

	void reshashing() {
		node<T> **oldtable = table;

		int old_table_size = table_size;

		table = new node<T>*[2 * table_size];
		table_size = 2 * table_size;

		for (int i = 0; i < table_size; i++) {
			table[i] = NULL;
		}

		current_size = 0;

		//Copy Karne ka Process:

		for (int i = 0; i < old_table_size; i++) {
			node<T>* head = oldtable[i];

			while (head != NULL) {
				insert(head->key, head->value);
				head = head->next;
			}
		}
		delete[] oldtable;
	}

public:

	//Constructor:

	hashmap(int size = 7) {
		table_size = size;
		current_size = 0;

		table = new node<T>*[size];

		for (int i = 0; i < table_size; i++) {
			table[i] = NULL;
		}
	}


	void insert(T s, int v) {
		int HashIndex = hashfunction(s);
		node<T>* n = new node<T>(s, v);
		current_size++;

		n->next = table[HashIndex];
		table[HashIndex] = n;


		if ((current_size / table_size * 1.0) >= 6.0) {
			reshashing();
		}
	}

	node<T>* search(string k) {
		int HashIndex = hashfunction(k);

		node<T>* head = table[HashIndex];

		while (head != NULL) {
			if (head->key == k) {
				return head;
			}
			head = head->next;
		}
		return NULL;
	}

	void print() {
		for (int i = 0; i < table_size; i++) {
			cout << i << "--> ";

			node<T>* head = table[i];
			while (head != NULL) {
				cout << head->key << " " << head->value << "-->";
				head = head->next;
			}
			cout << endl;
		}
	}

};

