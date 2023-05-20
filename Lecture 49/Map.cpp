#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {

	int n;
	cin >> n;

	vector<pair<string, int>>v;
	map<string, int>m;
	unordered_map<string, int>um;

	//Vector of Pair(String,int)
	for (int i = 0; i < n; i++) {
		string s; int x;
		cin >> s >> x;
		v.push_back({s, x});
	}


	//Map
	for (int i = 0; i < n; i++) {
		string s; int x;
		cin >> s >> x;
		m.insert({s, x});
	}

	//Unordered_Map
	for (int i = 0; i < n; i++) {
		string s; int x;
		cin >> s >> x;
		um.insert({s, x});
	}


	/*
		Any Container can be printed using two things: Using a For Each loop and using a Iterator:

		When you should use a For Each LOOP: WHen you want to print each and every element of the continer.

		But in case of Iterator you can be FLexible as in what elements you want to print.

		Remember Every container has its own iterator.

		In both of the scenarios auto keyword will be wildly used : what does auto do???

		Basically it automatically assign the data type to the data you have put auto before.
	*/

	cout << "Printing using a normal for Loop in case of vectors " << endl;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}

	cout << endl << endl;

	/*
		What does For each states: For Every element of this container/Data structure that is represented
		by my variable (preferably x) do this task;

		For Example : Our task right now is to print the entire array.

	*/


	cout << "Print using For Each Loop in case of vectors " << endl;

	/*
		Every Element of this container i.e. Vector will be represented by this x.
		what will be the data type of x: so x ka data type vahi hoga jo har ek element of this
		vector is:

		Is vector ka har ek element kya hain?? : pair<string,int>

		Hence if you don't want to write auto you can here use pair<string,int> as your data type;
	*/

	for (auto x : v) {
		//Task:
		cout << x.first << " " << x.second << endl;
	}

	cout << endl << endl;


	/*

		Now I want to print my vector using iterators: What is a iterator:

		Iterator are objects that return the address of the subsequent bucket of the container.
		You should never print a iterator directly but you can print the value at the address using *(Dereferencing)


		NOw how to print using iterators: First You should understand how to iterator using iterators and then
		perform the task i.e to print:

		How to iterate:  Since iterators have address can i have the address of the first bucket:

		Yes:By using .begin() and do i know when to stop : Yes: using .end();

		how to move from one bucket address to another bucker address:

		aap array me kaise karte the: a+0, a+1,a+2 -- - -

		yes You can move like this in iterators also.
	*/

	/*
		Steps: Declare the iterator:

		How to Declate a iterator???

		iterator it;

		but this will cause an issue? why? Every container has its own iterator
		so compiler is asking this iterator class belongs to which container hence you have to
		define the what type of iterator this is.

		vector<pair<string,int>>::iterator it;

	*/

	// vector<pair<string, int>>::iterator it;

	cout << "Printing the vector using Iterators " << endl;

	for (auto it = v.begin(); it != v.end(); it = it + 1) {
		cout << (*it).first << " " << (*it).second << endl;
	}

	cout << endl << endl;

}