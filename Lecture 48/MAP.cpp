#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
const int N = 0;


/*
	Map: Key Unique, Key are sorted and searching time is O(logn)
	Hashmap: Unordered_Map : Key are unique and key are not sorted(Hashing is used)
	//Searching ka time is O(Constant)

*/

int main() {

	//Syntax is same for map and unordered map
	map<string, int>mp;
	unordered_map<string, int>ump;


	//Pair ki tarah values insert hoti hain.
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s; int x;
		cin >> s >> x;

		// make_pair(s,v);
		mp.insert(make_pair(s, x));

	}

	for (int i = 0; i < n; i++) {
		string s; int x;
		cin >> s >> x;
		ump.insert({s, x});
	}


	//For Each LOOP and Iterator


	//For Each: FOr every Element that is inside my ds do this:
	//x kya hain:

	for (pair<string, int> x : mp) {
		cout << x.first << " " << x.second << endl;
	}

	cout << endl << endl;

	for (pair<string, int> x : ump) {
		cout << x.first << " " << x.second << endl;
	}


}

//Container me function

//.insert(make_pair());

//{key,value}

//For Each: For each revise

//QUestion Advance hashing

//:Revise karna and map stl khudse padhna and for each loop padh lena
//Github code dekh lena.

