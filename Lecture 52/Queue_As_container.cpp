#include<iostream>
#include<queue>
using namespace std;
const int N = 0;

void Print(queue<int>&qp) {


	// .end(): iterator(x)

	// qp.empty() == = kya qp empty hain.
	queue<int>z = qp;

	while (!qp.empty()) {
		cout << qp.front() << " " << qp.back() << endl;
		qp.pop();
	}
	// //cout << "jhjn";

	// cout << endl;

	// for (auto x : qp) {
	// 	cout << x << " ";
	// }
}

int main() {
	int n;
	cin >> n;

	queue<int>q;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	cout << q.size() << endl;
	Print(q);

	while (!q.empty()) {
		cout << q.front() << " " << q.back() << endl;
		q.pop();
	}

	// for (auto x : q) {
	// 	cout << x << " ";
	// }


}
