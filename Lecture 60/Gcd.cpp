#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long

int GCD(int x, int y) {

	if (y == 0) {
		return x;
	}

	return GCD(y, x % y);
}


int32_t main() {
	int x, y;
	cin >> x >> y;
	if (y > x) {
		swap(x, y);
	}
	cout << GCD(x, y) << endl;


	//This doesn't work on long integers:
	cout << __gcd(x, y) << endl;
}



