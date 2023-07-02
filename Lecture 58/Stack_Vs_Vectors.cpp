#include<bits/stdc++.h>
using namespace std;


int main() {

	// vector<int>ans = {1, 2, 3, 4, 5};
	// stack<int>check;

	// check.push(10);
	// check.push(20);
	// check.push(90);


	// stack<int>st = check;
	// vector<int>v = ans;

	int n;
	cin >> n;

	stack<char>st;
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		st.push(x);
	}

	vector<char>ans;
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		ans.push_back(x);
	}

	string s;
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		s.push_back(x);
	}

	cout << st.top() << endl;
	cout << ans[ans.size() - 1] << endl;
	cout << s.back() << endl;

	st.pop();
	ans.pop_back();
	s.pop_back();

	cout << st.top() << endl;
	cout << ans[ans.size() - 1] << endl;
	cout << s.back() << endl;

	cout << ans[0] << endl;
	cout << s.front() << endl;

}


//Stack: Empty-->O(1):
// Size--->O(1)
// push-- > O(1)
// pop-- > top element ko remove karta hain O(1).
// top-- > top element ko laake deta hain.-- > O(1).