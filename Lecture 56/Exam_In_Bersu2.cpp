#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long

int Total_Students, Maximum_Exam_Time;

int Each_Student_Time[N];

int Frequency_Array_For_Maximum_Time_Student[101] = {0};


void Exam_In_Bersu() {
	int Abtak_Ka_time_Consumed = 0;

	for (int i = 0; i < Total_Students; i++) {

		int Extra_Time = Abtak_Ka_time_Consumed - Maximum_Exam_Time + Each_Student_Time[i];

		double Students_Removed = 0;

		if (Extra_Time > 0) {

			for (int j = 100; j > 0; j--) {
				int contribution = j * Frequency_Array_For_Maximum_Time_Student[j];

				if (Extra_Time <= contribution) {

					Students_Removed += ((Extra_Time - 1 + j) / j);
					break;
				}
				Students_Removed += Frequency_Array_For_Maximum_Time_Student[j];
				Extra_Time = Extra_Time - contribution;
			}
		}

		Abtak_Ka_time_Consumed += Each_Student_Time[i];
		Frequency_Array_For_Maximum_Time_Student[Each_Student_Time[i]]++;

		cout << Students_Removed << " ";
	}
}

int32_t main() {


	cin >> Total_Students >> Maximum_Exam_Time;

	for (int i = 0; i < Total_Students; i++) {
		cin >> Each_Student_Time[i];
	}

	Exam_In_Bersu();
}







