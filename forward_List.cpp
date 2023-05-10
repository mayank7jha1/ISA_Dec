
#include<bits/stdc++.h>
using namespace std;
const int N = 0;

//DSA: Banana Aana chahiye+ Iterate karna

int main() {

	forward_list<int>f;//Ye ek Singly LL hain.

	//Singly tail nahi hota.

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		f.push_front(x);
	}

	// 10 20 30 40 50

	//Iterator: Return address of the block you want.

	//This helps you in iterating over the Container.

	//Har ek Container me iterator class hoti hi hain

	//cout << "Mayank" << endl;

	forward_list<int>::iterator it;

	//Point/ Address deta hain block ka jo aap chahte ho

	//begin()
	//end()

	it = f.begin();

	// cout << it << endl;//Technically this is not a address:
	cout << (*it) << endl;

	//How do i print the complete ll;

	// it-->address : it+1-->next bucket ka address

	for (it = f.begin(); it != f.end(); it++) {
		cout << *it << "-->";
	}
	cout << "NULL" << endl;

}