#include<iostream>
#include<bits/stdc++.h>
using  namespace std;
#define int long long
#define mod 1000000007
int k;
int a, b;
int pre[100010] = {0};
int dp[100010];

//100000+5=100005

int Flowers(int len) {

	if (len == 0) {
		return 1;
	}

	if (dp[len] != -1) {
		return dp[len];
	}

	int Option1 = Flowers(len - 1);
	int Option2 = 0;

	if (len >= k) {
		Option2 = Flowers(len - k);
	}

	return dp[len] = Option2 + Option1;
}


void Precompute() {
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < 100010; i++) {
		pre[i] = pre[i - 1] + Flowers(i);
		pre[i] = pre[i] % mod;
	}
}


int32_t main() {
	int t; cin >> t;
	cin >> k;

	Precompute();//Main 10^5 tak har flower ko khane ka way nikal lunga.

	while (t--) {
		cin >> a >> b;
		cout << pre[b] - pre[a - 1] << endl;//sum[a,b]
	}
}

//b==1: pre[1]-pre[0];

//DP Array:ki koi particular no of flower ko khanee ka way.
//dp[4]== Number of ways to eat 4 flowers.

//Pre[]==Precomputation: yaha tak ke number of flower ko khane ka way from 1.
//pre[4]=dp[1]+dp[2]+dp[3]+dp[4].
//pre[5]=dp[1]+dp[2]+dp[3]+dp[4]+dp[5].
//pre[5]=pre[4]+dp[5];





