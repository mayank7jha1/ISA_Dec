#include<iostream>
using  namespace std;
#define int long long


int n, d;
int a[20100];

void Credit_Card() {
	//By Default agar mera answer -1 nahi hain to main bhi nahi banunga
	//Main bank me jab bhi visit karu and ustime mera
	//bank balance is -ve so in oreder to check ki answer -1 toh nahi
	//main bank balance 0 banaunga. (Bank Balance)

	int BankBalance = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {

			if (BankBalance < 0) {
				BankBalance = 0;
			}

		} else {
			BankBalance += a[i];
			if (BankBalance > d) {
				cout << "-1";
				return;
			}
		}
	}

	//Agar main lin number 33 par khada hu: Iska matlab hain ki reeturn nahi hua
	//iska matlab hain mera answer will exist: -1 nahi //ISka matlab hain
	//ki aap bank me jaake kuch paisa deposit karsakte ho and answer -1 nahi aayga.

	//Minimise karrna hain visit ko:
	//Bank me maximum paisa deposit kardunga jo possible i.e i will make bank balance as high as
	//possible but agar iske karam mera answwer >d hojaaye to main vapas se bankbalance ko d
	//bana dunga kyu becausee mujh pata hain answer exist.

	BankBalance = 0;
	int visits = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (BankBalance < 0) {
				BankBalance = d;
				visits++;
			}

		} else {
			BankBalance += a[i];
			if (BankBalance > d) {
				BankBalance = d;
			}
		}
	}

	cout << visits << endl;

}





int32_t main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	Credit_Card();
	//cout << "jbgjbj";
}



// #define int long long


// int : long long

//PC: int  : 64 bit : int : 4 byte

//#define int long long by deafult saare 64 bit ke according
//vaale int ko long long mee reeplace







// Pehle check karo ki kya answer = -1 hosakta hain.


//                                  Agar aap bank me jaarahee ho matlab ai == 0 hain and
//                                  aapne kaha main bank BankBalance ko minimum possible bananta
//                                  hu and uskee baad bhi aage ke amount ko add karke mera
//                                  BankBalance > d hogaya to aap kuch bhi karlete answer was
//                                  - 1.








































