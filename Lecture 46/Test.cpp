#include<bits/stdc++.h>
using namespace std;
const int N = 0;


int Increase1(int x) {
	return x + 10;
}

//General Program likhna jisme main apne increment function
//ko apne according change kar saku.

//Functions jo pass hos=rahe hain as argument
//unme aap argument pass kar sako

//Functors:
class Increase {
public:
	int n;

	Increase(int x) {
		n = x;
	}

	int operator()(int p) {
		//p=30,40,50,60,70
		return p + n;
	}
};


//+

//()--->Overloaded: Operator Overloading:
//int a=10,b=20;
//a+b;

//a="amayank"
//b=sjksdk
//a+b;


int main() {
	cout << max(10, 15) << endl;

	int a[] = {10, 20, 30, 40, 50};

	for (int i = 0; i < 5; i++) {
		a[i] = a[i] + 10;
	}

	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}


	//This is not imp for you.
	//STL ke algorithm: address of the first block
	//and address of the last+1 block
	cout << a << endl;
	cout << a + 1 << endl;

	int x = 250;

	transform(a, a + 5, a, Increase(x));

	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
}


// transform: array ke har element ko +10

// +20
// +30


//a--->6422252
//a+1-->6422256


//vector ke ander find function: vo aapko element ka address laake
//deta hain: element present nahi ?

//taaki samne ko pata cahle ki bhai aapke vector me element nahi hain.

//Vector: Dynamic Array


//Idea:

//