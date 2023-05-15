#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int table_size = 7;
int hashfunction(string key) {
	//Prime Number: 23
	int multiply = 1;
	int sum = 0;

	for (int i = 0; i < key.length(); i++) {

		sum += ((key[i] % table_size) *
		        (multiply % table_size)) % table_size;

		multiply = multiply * 23;
		multiply = multiply % table_size;
	}

	sum = sum % table_size;
	return sum;
}


int main() {

	cout << hashfunction("Rahul") << endl;
}