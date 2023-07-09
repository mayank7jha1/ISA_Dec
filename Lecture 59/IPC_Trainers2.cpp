#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define AS 1005


int IPC_Trainers() {
	int Total_Trainers, Days;
	cin >> Total_Trainers >> Days;

	int Arrival_Day[1005] = {0}, Lectures[AS] = {0}, Sadness[AS] = {0};
	priority_queue<pair<int, int>>pq;

	for (int i = 0; i < Total_Trainers; i++) {

		cin >> Arrival_Day[i] >> Lectures[i] >> Sadness[i];
		pq.push({Sadness[i], i});

	}

	int Lectures_Taken[AS] = {0};


	set<int>s;
	for (int i = 1; i <= Days; i++) {
		s.insert(i);
	}

	while (!pq.empty()) {
		pair<int, int> x = pq.top();
		pq.pop();

		int Index_of_teacher_we_are_taking = x.second;

		int Ideal_Start_Date = Arrival_Day[Index_of_teacher_we_are_taking];

		int Ideal_End_Date = Arrival_Day[Index_of_teacher_we_are_taking] +
		                     Lectures[Index_of_teacher_we_are_taking] - 1;


		for (int i = Ideal_Start_Date; i <= Ideal_End_Date; i++) {
			auto x = s.lower_bound(i);

			if (x == s.end()) {
				break;
			} else {
				Lectures_Taken[Index_of_teacher_we_are_taking]++;
				s.erase(x);
			}
		}
	}

	int Total_Sadness = 0;

	for (int i = 0; i < Total_Trainers; i++) {
		Total_Sadness += (Lectures[i] - Lectures_Taken[i]) * Sadness[i];
	}

	return Total_Sadness;
}

int32_t main() {
	int t;
	cin >> t;

	while (t--) {
		cout << IPC_Trainers() << endl;
	}
}




