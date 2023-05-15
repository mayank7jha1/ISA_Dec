#include<iostream>
#include "Hashmap.h"
using namespace std;


//Key-->string and value-->int
//Key-->generic; value-->generic

//template class: jis tarah ka data user dega main vahi data ka class bana dunga

int main() {
	hashmap<string>mp;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s; int v;
		cin >> s >> v;
		mp.insert(s, v);
	}

	mp.print();
}


//Ache stl easy hain.

//STL ka overview dedeta hu