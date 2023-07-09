#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define AS 100005


int IPC_Trainers() {
	int Total_Trainers, Days;
	cin >> Total_Trainers >> Days;

	int Arrival_Day[100005] = {0}, Lectures[AS] = {0}, Sadness[AS] = {0};
	priority_queue<pair<int, int>>pq;

	for (int i = 0; i < Total_Trainers; i++) {
		cin >> Arrival_Day[i] >> Lectures[i] >> Sadness[i];
		pq.push({Sadness[i], i});
	}


	/*
		ith Teacher ka Info Batao:
		ith Teacher Arrives on Arrival_Day[i]
		he/she has to take Lectures[i] lectures and
		he/she will be sad to the amount sadness[i] if he/she
		is not able to take a lecture.

	*/

	int Lectures_Taken[AS] = {0};
	/*
		This above array tells you which teacher was able to take
		how many lectures successfully.

		Lectures_Taken[i]==ith teacher ne kitne successfully
		lectures leliye out of total lectures he/she has to take
		i.e. in lectures[i].
	*/

	//Set that will contain all the availble days.

	set<int>s;
	for (int i = 1; i <= Days; i++) {
		s.insert(i);
	}

	while (!pq.empty()) {
		pair<int, int> x = pq.top();
		pq.pop();

		int Index_of_teacher_we_are_taking = x.second;

		int Start_Date = Arrival_Day[Index_of_teacher_we_are_taking];

		int End_Date = Arrival_Day[Index_of_teacher_we_are_taking] +
		               Lectures[Index_of_teacher_we_are_taking] - 1;


		for (int i = Start_Date; i <= End_Date; i++) {
			auto it = s.lower_bound(i);
		}

		/*
			COntinue from the next file with same name;
		*/


		/*
			 4  6 7  9

			Assume:

			Teacher arrival day is 3:
			Teacher has to take 3 Lecture:

			Assuming all the days are available teacher would have
			taken lectures on day 3,day 4,day 5.

			Start_Data=3;
			End_Date=3+3-1=5;

			set me dhundo 3 ka lower_bound kya hain?

			Vo first day if day 3 is not available jaha par teacher
			apna day 3 ka lecture compensate karega.

			DAY 4 =*s.lower_bound(3);

			//Remove DAY 4:
			//Set LEFT: 6 7 9

			since day 4 is not available aap kehte:
			6=*s.lower_bound(4)

			Remove this 6:
			Set left: 7 9

			day 5 ko compensate karne ke liye konsa day hain.

			7=*s.lower_bound(5);

			Main Lectures technically lena day 3,4,5 par chahta tha
			par main lunga day 4,6,7 par.

		*/


	}

}

int32_t main() {
	int t;
	cin >> t;

	while (t--) {
		cout << IPC_Trainers() << endl;
	}
}