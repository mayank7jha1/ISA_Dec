#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int dp[10005];//static fastest
// map<int, int>m;

//int *dp;
//Top Down: Recursion + Memorisation

int fib(int n) {
	if (n <= 1) {
		return n;
	}

	//Calculate Karne se Pehle Check ki Current State ka
	//answer pehle se toh nahi calculated hain?
	if (dp[n] != -1) {
		return dp[n];
	}

	int Option1 = fib(n - 1);
	int Option2 = fib(n - 2);

	int ans = Option1 + Option2;

	//Jab aapne answer already calculate kar liya hain
	//of the current state then store this answer
	//for future reference.
	return dp[n] = ans;
}

//Iterative DP
//O(n) and O(n);
int fib1(int n) {

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main() {
	int n;
	cin >> n;

	// for (int i = 0; i < 10005; i++) {
	// 	dp[i] = -1;
	// }
	//dp = new int[n + 1];
	memset(dp, -1, sizeof(dp));

	// By Function Definition:
	//Dp[n]= nth Fibonacci Number
	cout << fib(n) << endl;

	memset(dp, -1, sizeof(dp));

	cout << fib1(n) << endl;
}