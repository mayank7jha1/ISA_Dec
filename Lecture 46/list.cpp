#include<bits/stdc++.h>
using namespace std;
const int N = 0;

void Print(list<int>f) {

	// int x = 20;

	// auto x = 20; auto int
	//auto = forward_list<int>::iterator

	for (list<int>::iterator  it = f.begin(); it != f.end(); it++) {
		cout << *it << "-->";
	}
	cout << "NULL" << endl;

}

int main() {


	list<int>l, l1; //DLL
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		l.push_back(x);
	}

	Print(l);


	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		l1.push_front(x);
	}

	Print(l1);



	cout << l.front() << endl;
	cout << l.back() << endl;

	l.sort();
	l.reverse();

	l.pop_back();
	l.pop_front();

	Print(l);
}


