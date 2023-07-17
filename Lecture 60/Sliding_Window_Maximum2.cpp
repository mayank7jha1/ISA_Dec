#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& a, int k) {
		deque<int>dq;

		int n = a.size();
		if (k == 1) {
			return a;
		}

		vector<int>ans;

		//First Window ka task kar rahe hain.
		for (int i = 0; i < k; i++) {

			while (!dq.empty() and a[i] >= a[dq.back()]) {
				dq.pop_back();
			}

			dq.push_back(i);
		}

		//First ka maximum mujhe deque ke starting me milega.
		for (int i = k; i < a.size(); i++) {

			ans.push_back(a[dq.front()]);

			/*Check karo ki deque me jo sabse pehla element hain
			kya vo next window ka part hain.*/

			while (!dq.empty() and dq.front() <= i - k) {
				dq.pop_front();
			}

			while (!dq.empty() and a[i] >= a[dq.back()]) {
				dq.pop_back();
			}

			dq.push_back(i);
		}

		ans.push_back(a[dq.front()]);

	}
};

// index:  0 1 2 3 4 5 6 7 8 9

// k = 5
//     dq:  2 3 4

//     2<=7-5=2

int main() {

}