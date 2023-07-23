#include<bits/stdc++.h>
using namespace std;


int LCS(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
	if (i >= text1.size() || j >= text2.size()) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	if (text1[i] == text2[j]) {
		dp[i][j] = 1 + LCS(i + 1, j + 1, text1, text2, dp);
	}
	else {
		int opt1 = LCS(i + 1, j, text1, text2, dp);
		int opt2 = LCS(i, j + 1, text1, text2, dp);
		dp[i][j] = max(opt1, opt2);
	}
	return dp[i][j];
}


string solve(string &text1, string &text2) {
	vector<vector<int>>dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
	int maxLCS = LCS(0, 0, text1, text2, dp);
	string s = "";
	int i = 0, j = 0;
	while (maxLCS > 0) {
		if (text1[i] == text2[j]) {
			s = s + text1[i];
			//cout << s << endl;
			i++;
			j++;
			maxLCS--;
		}
		else {
			if (dp[i + 1][j] > dp[i][j + 1]) i++;
			else j++;
		}
	}
//	cout<<i<<" "<<j;
	return s;
}

int main() {
	string text1, text2;
	cin >> text1 >> text2;
	cout << solve(text1, text2);
}