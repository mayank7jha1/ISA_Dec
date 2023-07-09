#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {
	set<int>s;

	int ans[] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 9, 9, 12};
	int n = sizeof(ans) / sizeof(int);
	cout << n << endl;

	//Array has index from 0---16.

	/*This returns the first element ka address that will be greater
	than or equal to 3.*/

	cout << ans << endl;
	cout << ans + 1 << endl;
	cout << ans + 2 << endl;
	cout << *lower_bound(ans, ans + n, 3) << endl;
	cout << lower_bound(ans, ans + n, 3) - ans << endl;

	/*This returns the first element ka address that will be greater
	than 3.*/
	cout << upper_bound(ans, ans + n, 3) - ans << endl;

	//If you want to find occurrences of an element inside a array/vector
	//in log(n) time just do upper_bound-lower_bound.

	cout << upper_bound(ans, ans + n, 3) - lower_bound(ans, ans + n, 3) << endl;

	cout << lower_bound(ans, ans + n, 15) - ans << endl;


	vector<int>v{1, 2, 3, 4, 5};

	/*	This returns a iterator and you cannot print
		a iterator directly but you can compare / apply arithmetic operations on them.*/

	cout << lower_bound(v.begin(), v.end(), 7) - v.begin() << endl;;


	//This address will be equal to v.end():
	//.end()--->last element se ek kadam aage:
	if (lower_bound(v.begin(), v.end(), 7) == v.end()) {
		cout << "YES" << endl;
	}

	set<int>s2{5, 4, 3, 17, 18, 18, 9, 12, 14, 19, 19, 17, 2, 1};

	//for every element that is inside this container do this task.

	for (int x : s2) {
		cout << x << " ";
	}
	cout << endl;

	//You cannot do this:
	// cout << s.lower_bound(13); Basically cannot print an iterator.


	cout << *s2.lower_bound(15); //First Element ka address/iterator that is greater than/equal to to 3.

	if (s.lower_bound(25) == s.end()) {
		cout << "YO" << endl;
	}
}