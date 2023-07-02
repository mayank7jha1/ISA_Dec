#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	queue<int>q;

	for (int i = 0; i < 6; i++) {
		int x;
		cin >> x;
		q.push(x);
	}

	// 1 2 3 4 5 6

	cout << q.size() << endl;
	cout << q.empty() << endl;

	cout << q.front() << endl;
	cout << q.back() << endl;

	q.pop();



	while (!q.empty()) {
		int front = q.front();
		cout << front << " " << q.back() << endl;
		q.pop();
	}
}


