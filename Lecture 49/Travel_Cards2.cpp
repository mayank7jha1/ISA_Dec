#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int Travel_Cards() {
	int n, a, b, k, f;
	cin >> n >> a >> b >> k >> f;

	map<pair<string, string>, int>mp;

	string prev_dest = "";

	for (int i = 0; i < n; i++) {

		string start_point, end_point;
		cin >> start_point >> end_point;

		int price;

		if (prev_dest == start_point) {
			price = b;
		} else {
			price = a;
		}

		prev_dest = end_point;

		if (start_point > end_point) {
			swap(start_point, end_point);
		}

		if (mp.find({start_point, end_point}) != mp.end()) {
			mp[ {start_point, end_point}] = mp[ {start_point, end_point}] + price;

		} else {

			mp[ {start_point, end_point}] = price;
		}
	}


	//Kya Mujhe path se matlab hain? Cost se matlab hain.
	//Saare path ke cost ko ek new vector ke ander daal deta hu.

	vector<int>cost;

	int Total_Trip_Cost_Without_Travel_Cards = 0;

	//Iterate over the map and put the cost of every path inside this vector.

	//auto: pair<pair<string,string>,int>

	for (pair<pair<string, string>, int> x : mp) {

		//x---> pair<pair<string,string>,int>

		//x.first--->pair<string,string>

		// //cout<<x.first<<endl;

		// cout << x.first.first << " " << x.first.second << endl;
		// cout << x.second << endl;//cost

		cost.push_back(x.second);

		Total_Trip_Cost_Without_Travel_Cards += x.second;
	}


	//Cost ka vector hain and total cost withour travel cards pada hua hain.

	/*
		k=5;

		f=100;

		1. cost = 200
		2. cost = 150
		3. cost = 90 //Will i buy my travel card : NOT BUY
		4. cost = 80 //SHOULD I CHECK FOR THIS : DIRECT BREAK FROM THIS;
		5. cost = 70
		6. cost = 60


		when you will buy travel card aapko total cost - 200 + 100;
	*/

	//sort(cost.begin(), cost.end(), greater<int>());

	int Total_Cost = Total_Trip_Cost_Without_Travel_Cards;

	sort(cost.rbegin(), cost.rend());

	// sort(cost.begin(), cost.end());
	// reverse(cost.begin(), cost.end());


	for (int i = 0; i < k; i++) {

		if (cost[i] >= f) {
			Total_Cost = Total_Cost - cost[i] + f;
		} else {
			break;
		}

	}

	return Total_Cost;

}



int main() {
	cout << Travel_Cards();
}

