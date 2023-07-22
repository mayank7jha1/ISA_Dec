#include<iostream>
using  namespace std;
const int N = 1001;
char grid[N][N];
#define mod 1000000007
#define int long long

//Macros:


int Solve(int h, int w) {
	int dp[h + 1][w + 1] = {0};

	dp[h][w] = 1;

	for (int i = h; i >= 1; i--) {
		for (int j = w; j >= 1; j--) {
			if (i == h and j == w) {
				continue;
			}
			if (grid[i][j] == '#') {
				dp[i][j] = 0;
			} else {
				if (i == h) {
					dp[i][j] = (dp[i][j + 1]) % mod;
				} else if (j == w) {
					dp[i][j] = (dp[i + 1][j]) % mod;
				} else {
					dp[i][j] = (dp[i + 1][j] % mod + dp[i][j + 1] % mod) % mod;
				}

			}
		}
	}

	return  dp[1][1];
}



int32_t main() {
	int h, w;
	cin >> h >> w;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> grid[i][j];
		}
	}

	cout << Solve(h, w) << endl;
}




// int: 10 ^ 9
// long long : 9 * 10 ^ 18
// __int128: 10 ^ 24;






//1000000000000000000000000 : Print??
//(1000000000000000000000000)%10^9+7=== (1----10^9)








