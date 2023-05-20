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

	cout << "Printing using a normal for Loop in case of vectors " << endl;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}

	cout << endl << endl;

	cout << "Print using For Each Loop in case of vectors " << endl;


	for (auto x : v) {
		//Task:
		cout << x.first << " " << x.second << endl;
	}

	cout << endl << endl;

	cout << "Printing the vector using Iterators " << endl;

	for (auto it = v.begin(); it != v.end(); it = it + 1) {
		cout << (*it).first << " " << (*it).second << endl;
	}

	cout << endl << endl;


	//Since Map does not have a concept of indexing : WE CANNOT ITERATOR USING FOR LOOP:
	//pair<string,int>==auto

	for (auto x : m) {
		cout << x.first << " " << x.second << endl;
	}

	/*
		auto: map<string,int>::iterator it;
	*/

	for (auto it = m.begin(); it != m.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl;
	}


	/*
		IMP Functions of Map and Unordered Map:

		1. Find Function:

		This is the function that is used to find a element inside the container map,
		and when used it will return the address of the bucket where the element is found.

		Sir, what if element is not found?? THen this fuction will return
		the address of one bucket ahead of last element i.e. the address of .end() iterator.


		2. Count Function:

		THis is also used to find/check a element is present or not but the difference
		is this fuction returns true/false rather than address when element is found or not.

	*/


	/*

		Since Map/Unordered_map is a key value pair and it symbolises the properties of
		arrays: to agar aapko key pata hain to aapko value bhi pata hain.

		cout<<a[3]<<endl;


		map[key]=value;

		cout<<map[key]<<endl;

		map[key]=map[key]+100;

		map[key]=1000;
	*/


	auto it = m.find("Sarthak");

	cout << (*it).second << endl;

	/*
		m.find() aapko ek address deraha hain jo
		m.end() ke equal nahi hai iska matalb element is
		present.
	*/

	if (m.find("Sarthak") != m.end()) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	if (m.count("Sarthak") == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}


}


/*
	It is not possible to study each and every function of a container in class
	, H.W> Study about the other fucntions of map and unordered map.

*/