#include<iostream>
using  namespace std;
const int N = 2e5 + 10;
#define int long long
int n, Exam_Limit;
int a[N] = {0};
int Student_Time[N] = {0};

void Solve() {
	int Total_Time = 0;

	for (int i = 0; i < n; i++) {

		int difference = Total_Time - Exam_Limit;
		int Student_Removed = 0;

		if (difference > 0) {
			//Apko kuch student remove karne padenge

			for (int j = 100; j > 0; j--) {

			}
		}



		Total_Time += a[i];
		Student_Time[a[i]]++;

	}
}

int32_t main() {

}