#include<iostream>
using  namespace std;
#define mod 1000000007


int n, m, p;
int grid[1001][1001];

int Robot_and_Path() {

	int dp[n + 1][m + 1];

	if (grid[1][1] == -1 or grid[n][m] == -1) {
		return 0;
	}

	dp[1][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (i == 1 and j == 1) {
				continue;
			}
			if (grid[i][j] == -1) {
				dp[i][j] = 0;
			} else {

				if (i == 1) {

					dp[i][j] = (dp[i][j - 1]) % mod;

				} else if (j == 1) {

					dp[i][j] = (dp[i - 1][j]) % mod;

				} else {
					dp[i][j] = ((dp[i - 1][j]) % mod + (dp[i][j - 1]) % mod) % mod;
				}
			}
		}
	}
	return dp[n][m];
}

// (a+b)% m =   (a%m + b%m)%m;

int main() {
	cin >> n >> m >> p;
	while (p--) {
		int x, y;
		cin >> x >> y;
		grid[x][y] = -1;
	}

	cout << Robot_and_Path() << endl;
}