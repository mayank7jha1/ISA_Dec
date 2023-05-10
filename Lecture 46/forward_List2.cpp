
#include<bits/stdc++.h>
using namespace std;
const int N = 0;

//Containers can be passed as arguments and can be returned also.

void Print(forward_list<int>f) {

	// int x = 20;

	// auto x = 20; auto int
	//auto = forward_list<int>::iterator

	for (forward_list<int>::iterator  it = f.begin(); it != f.end(); it++) {
		cout << *it << "-->";
	}
	cout << "NULL" << endl;

}

int main() {

	forward_list<int>f;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		f.push_front(x);
	}



	forward_list<int>::iterator it;

	it = f.begin();
	cout << (*it) << endl;

	Print(f);

	f.pop_front();
	Print(f);

	f.reverse();
	Print(f);

	f.sort();
	Print(f);

	f.resize(10);
	Print(f);

	if (f.empty() == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	forward_list<int>f2 = {1, 2, 3, 4, 5};

	//f2 = f;

	//Print(f2);

	f.swap(f2);

	Print(f);
	Print(f2);

	//Delete pop_front()-->O(1);
}


//auto: jis type ka data hota hain ye khud ba khud itendify karta hain
//and fill kardeta hain.