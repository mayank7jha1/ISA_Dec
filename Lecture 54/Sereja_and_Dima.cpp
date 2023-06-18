#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int i = 0;
	int j = n - 1;

	int Sereja = 0, Dima = 0;

	int k = 0;//Even meaning Sereja ki chance and odd meaning Dima ki chance

	while (i <= j and k < n) {

		if (a[i] >= a[j] and k % 2 == 0) {
			Sereja = Sereja + a[i];
			i++;
		} else if (a[j] >= a[i] and k % 2 == 0) {
			Sereja = Sereja + a[j];
			j--;
		} else if (a[i] >= a[j] and k % 2 == 1) {
			Dima = Dima + a[i];
			i++;
		} else if (a[j] >= a[i] and k % 2 == 1) {
			Dima = Dima + a[j];
			j--;
		}
		k++;
	}


	// if (i == j and k % 2 == 0) {
	// 	Sereja += a[i];
	// }

	// if (i == j and k % 2 == 1) {
	// 	Dima += a[i];
	// }

	cout << Sereja << " " << Dima << endl;
}



// 1 2 3 4


// x y z t

// 1 and 4 compare:
// x and t ko compare kiya


// Sereja += t;


// Dima