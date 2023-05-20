#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {
	//Array ka har ek element ek pair hain.
	// int n;
	cin >> n;
	pair<string, int>p[n];

	vector<pair<string, int>>p1;

	//vector ka ek element kya hain? : Pair hain type : string int

	for (int i = 0; i < n; i++) {
		string s; int x;
		cin >> s >> x;

		//p1.push_back(make_pair(s, x));
		p1.push_back({s, x});
	}

	for (int i = 0; i < n; i++) {
		cout << p1[i].first << " " << p1[i].second << endl;
	}
}