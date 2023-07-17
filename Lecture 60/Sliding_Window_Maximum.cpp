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

		/*


		*/
	}
};

// K = 5

// Index:     0 1 2 3 4
// Elements:  2 3 7 4 x

// //First Window Task: First k elements
// /*
// 	We want to store some elements which would help me in
// 	finding the maximum.

// */

// /*i = 0--->a[0]-- > 2
// i=  1--->a[1]---> 3

// a[1]>=a[dq.back()]==a[1]>=a[0]: Iska matlab ye 0 index ka Element
// kabhi bhi kisi bhi window ka maximum nahi ban sakta why?? Because
// aise koi window nahi hain iska part index 0 ka element i.e 2 ho aur
// index 1 ka element i.e 3 naho!!! That's why we can just remove this element.*/

// // i=2--->a[2]-->7: 7>=
// //i=3: --->a[3]-->4:   4>=a[2](x).

// /*

// 	NOw since a[3] is not greater than or equal to a[2] i.e a[dq.back()]
// 	we cannot just remove 7 and insert 4. Now there is a window that will
// 	jiska part 4 hoga  and 7 nahi hoga so us case me kya pata 4 hi maximum
// 	bann jaata isliye hume 4 ka index bhi store karna padega.
// */

// /*

// 	i==4=---->a[4]--->9    x<7:
// */

// Deque: 2 3


int main() {

}