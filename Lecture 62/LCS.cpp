#include<iostream>
#include<bits/stdc++.h>
using  namespace std;
string s, t;
int dp[3001][3001];

string GetLCS(int len) {
	string ans;
	int i = 0;
	int j = 0;

	while (len > 0) {
		if (s[i] == t[j]) {
			ans.push_back(s[i]);
			i++, j++;
			len--;
		} else {
			if (dp[i][j + 1] > dp[i + 1][j]) {
				j++;
			} else {
				i++;
			}
		}
	}
	return ans;
}



int LengthLCS(int i, int j) {
	if (i >= s.length() or j >= t.length()) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}


	if (s[i] == t[j]) {

		return dp[i][j] = 1 + LengthLCS(i + 1, j + 1);
	} else {

		int Option1 = LengthLCS(i + 1, j);
		int Option2 = LengthLCS(i, j + 1);

		return dp[i][j] = max(Option1, Option2);
	}
}

string Solve() {
	memset(dp, -1, sizeof(dp));
	int len = LengthLCS(0, 0);

	string str = GetLCS(len);
	return str;
}


int main() {

	cin >> s >> t;
	cout << Solve() << endl;

}





