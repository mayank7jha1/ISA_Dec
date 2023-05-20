#include<bits/stdc++.h>
using namespace std;
const int N = 0;



//Jitne bhi containers hain they can be used inside one another.

int main() {

	/*
		Mayank 100 : pair<string,int>p1;
		Samyak 200 : pair<string,int>p2;
		.
		.
		.
	*/
	int n;
	cin >> n;
	pair<string, int>p[n];

	//p[0]--  Ek Pair
	//p[1]--> ek paIR
	//P[2]--> PAIR
	//P[3]-->
	//p[4]-->

	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}

	for (int i = 0; i < n; i++) {
		cout << p[i].first << " " << p[i].second << endl;
	}

}