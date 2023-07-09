#include<bits/stdc++.h>
using namespace std;
const int N = 0;

//Running Stream Of Numbers



int main() {

	//Max Heap
	priority_queue<int>maxi;

	//Min Heap
	priority_queue<int, vector<int>, greater<int>>mini;

	//nlogn
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		maxi.push(x);
		mini.push(x);
	}

	while (!maxi.empty()) {
		int Sabse_Bada = maxi.top();
		maxi.pop();
		cout << Sabse_Bada << " ";
	}
	cout << endl;
	while (!mini.empty()) {
		int Sabse_Chota = mini.top();
		mini.pop();
		cout << Sabse_Chota << " ";
	}

}