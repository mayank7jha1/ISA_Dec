#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {

	int n;
	cin >> n;
	queue<int>q;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		q.push(x);
	}

	cout << q.front() << " " << q.back() << endl;

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}



	//Back se remove nahi kar sakte and simultaneously front se
	//insert nahi kar sakte.
	cout << endl;
	//Deque:

	deque<int>dq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		dq.push_back(x);
	}


	cout << endl;

	cout << dq.front() << " " << dq.back() << endl;
	dq.pop_back();
	dq.pop_front();
	dq.push_back(20);
	dq.push_front(1991);


	while (!dq.empty()) {
		cout << dq.front() << " ";
		dq.pop_front();
	}


}