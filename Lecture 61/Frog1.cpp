#include<bits/stdc++.h>
using namespace std;
const int N = 0;
//Top Down
//Solve(h,x)==min cost to reach the 0th Stone from xth stone.
int dp[100010];


/*
Space and Time Complexity
O(n) and O(n):

O(state)=O(n)
O(Transition Time)=O(1)
O(n)*O(1)==O(n)

*/

int Solve(int* height, int x) {

	if (x <= 0) {
		return 0;
	}

	if (dp[x] != -1) {
		return dp[x];
	}

	int Option1 = INT_MAX, Option2 = INT_MAX;

	if (x - 1 >= 0) {
		Option1 = Solve(height, x - 1) + abs(height[x] - height[x - 1]);
	}

	if (x - 2 >= 0) {
		Option2 = Solve(height, x - 2) + abs(height[x] - height[x - 2]);
	}

	int ans = min(Option2, Option1);
	return dp[x] = ans;
}

//Solve2(h,0,x): min cost to reach the xth stone from 0.

int Solve2(int* height, int x, int n) {

	if (x == n) {
		return 0;
	}

	if (dp[x] != -1) {
		return dp[x];
	}

	int Option1 = INT_MAX, Option2 = INT_MAX;
	if (x + 1 <= n) {
		Option1 = Solve2(height, x + 1, n) + abs(height[x] - height[x + 1]);
	}

	if (x + 2 <= n) {
		Option2 = Solve2(height, x + 2, n) + abs(height[x] - height[x + 2]);
	}

	int ans = min(Option2, Option1);
	return dp[x] = ans;
}

//Solve3-->dp[x]==min cost to reach the xth stone from 0.
int Solve3(int* height, int x) {

	dp[0] = 0;
	dp[1] = abs(height[0] - height[1]);

	for (int i = 2; i <= x; i++) {

		int Option1 = dp[i - 1] + abs(height[i - 1] - height[i]);
		int Option2 = dp[i - 2] + abs(height[i - 2] - height[i]);

		dp[i] = min(Option1, Option2);
	}
	return dp[x];
}



int main() {
	int n;
	cin >> n;


	int height[n];

	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	memset(dp, -1, sizeof(dp));
	cout << Solve(height, n - 1) << endl;

	memset(dp, -1, sizeof(dp));
	cout << Solve2(height, 0, n - 1) << endl;


	memset(dp, 0, sizeof(dp));
	cout << Solve3(height, n - 1) << endl;



}