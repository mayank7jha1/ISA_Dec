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

	vector<int>cost;

	int Total_Trip_Cost_Without_Travel_Cards = 0;

	for (pair<pair<string, string>, int> x : mp) {
		cost.push_back(x.second);
		Total_Trip_Cost_Without_Travel_Cards += x.second;
	}


	int Total_Cost = Total_Trip_Cost_Without_Travel_Cards;

	sort(cost.rbegin(), cost.rend());

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

