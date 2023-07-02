#include<bits/stdc++.h>
using namespace std;

//You have to Implement this stack Using Queues Only.
template<typename T>

class MyStack {
public:

    queue<int>input, output;

    //Constructor
    MyStack() {

    }

    void push(T x) {
        input.push(x);
    }

    T pop() {

        while (input.size() > 1) {
            int x = input.front();
            output.push(x);
            input.pop();
        }

        int Top_Element = input.front();
        input.pop();

        while (!output.empty()) {
            int x = output.front();
            input.push(x);
            output.pop();
        }

        return Top_Element;
    }

    T top() {
        while (input.size() > 1) {
            int x = input.front();
            output.push(x);
            input.pop();
        }

        int Top_Element = input.front();
        output.push(Top_Element);
        input.pop();

        while (!output.empty()) {
            int x = output.front();
            input.push(x);
            output.pop();
        }

        return Top_Element;
    }

    bool empty() {
        if (input.empty() == 1) {
            return true;
        } else {
            return false;
        }
    }

};


int main() {
    MyStack<int>st;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    while (!st.empty()) {
        cout << st.top() << endl;
        int x = st.pop();
    }

}


//6 5 4 3 2 1