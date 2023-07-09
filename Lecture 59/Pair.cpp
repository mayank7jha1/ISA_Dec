#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {
	vector<pair<int, int>>v;

	priority_queue<vector<int>>pq1;

	pq1.push({1, 9, 3, 4, 5});

	pq1.push({1, 6, 7, 8, 9});

	while (!pq1.empty()) {
		vector<int>ans = pq1.top();
		for (auto x : ans) {
			cout << x << " ";
		}
		cout << endl;
		pq1.pop();
	}

	cout << endl;

	priority_queue<string>pq2;//Max Heap
	pq2.push({"mayank"});
	pq2.push({"mamyak"});

	while (!pq2.empty()) {
		cout << pq2.top() << endl;
		pq2.pop();
	}

	cout << endl << endl;


	priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>>pq;

	pq.push({31, 19});
	pq.push({31, 7});
	pq.push({31, 0});
	pq.push({31, -5});
	pq.push({29, 5});
	pq.push({28, 8});

	while (!pq.empty()) {
		cout << pq.top().first << " " << pq.top().second << endl;
		pq.pop();
	}


	cout << endl << endl << endl;

	v.push_back({31, 0});
	v.push_back({31, 5});
	v.push_back({30, 19});
	v.push_back({31, 8});
	v.push_back({31, -5});
	v.push_back({31, 7});
	v.push_back({29, 13});


	sort(v.begin(), v.end());

	for (auto x : v) {
		cout << x.first << " " << x.second << endl;
	}
}