#include<iostream>
using  namespace std;
#include<bits/stdc++.h>
#define int long long

const int N = 1e5 + 10;

int n, k;
int *taste;
int *calorie;

int dp[105][2 * N];


int Dima_and_Salad(int index, int sum) {

	if (index == n) {
		if (sum == 0) {
			//This was a valid path.//Aapne is path me travel karte  time
			//taste already is  path ka calculate  kar liya hoga.
			return 0;

		} else {
			//This is not a valid path and you can never take its path ka taste
			//into consideration and since hum log  baad me maximum nikal rahe
			//and i know i ye path consider nahi karna so i will return something so small that  jo bhi dusra option hoga jab iske sath
			//max karega to vahi  answer banega ye nahi.
			return -1e10;
		}
	}


	if (dp[index][sum + N] != -1) {
		return dp[index][sum];
	}

	int Option1 = taste[index] +
	              Dima_and_Salad(index + 1, sum + (taste[index] - k * calorie[index]));

	int Option2 = 0 + Dima_and_Salad(index + 1, sum);

	return dp[index][sum + N] = max(Option1, Option2);

}


int32_t main() {
	cin >> n >> k;
	taste = new int[n];
	calorie = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> calorie[i];
	}

	memset(dp, -1, sizeof(dp));

	int ans = Dima_and_Salad(0, 0);

	if (ans <= 0) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}