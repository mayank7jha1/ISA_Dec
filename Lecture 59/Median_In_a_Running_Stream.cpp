
#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class MedianFinder {
public:
    priority_queue<int>Maxi;
    priority_queue<int, vector<int>, greater<int>>Mini;

    MedianFinder() {

    }
    void addNum(int num) {
        Maxi.push(num);
        Mini.push(Maxi.top());
        Maxi.pop();

        if (Mini.size() > Maxi.size()) {
            Maxi.push(Mini.top());
            Mini.pop();
        }
    }

    double findMedian() {
        if ((Maxi.size() + Mini.size()) % 2 == 0) {
            double ans = (double)(Maxi.top() + Mini.top()) / 2;
            return ans;
        }

        return Maxi.top();
    }
};


int main() {

}
