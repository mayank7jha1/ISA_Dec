#include<iostream>
#include<stack>
using namespace std;







int main() {

	stack<int>st;//Container Adapter:
	//Isme Specified hain ki element agar push karoge to last me hi jaayega.
	//push


	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		st.push(x);
	}


	cout << st.empty() << endl;
	//cout << st.top() << endl;

	// while(!st.empty()){

	// }

	while (st.empty() == 0) {
		int top = st.top();
		cout << top << endl;
		st.pop();
	}

	//Aplication: 1. When you want to compare multiple items simultaneously.
	//2. When you have a task of reversal of any kind.

}


// 10
// 19
// 1
// 9
// 7