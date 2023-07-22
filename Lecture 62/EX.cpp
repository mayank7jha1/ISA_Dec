#include<iostream>
#include<algorithm>
using  namespace std;
#define int __int128


// Custom input function for int
istream& operator>>(istream& in, int& n) {
    string s;
    in >> s;
    n = 0;
    for (int i = 0; i < s.length(); i++) {
        n = n * 10 + (s[i] - '0');
    }
    return in;
}

// Custom output function for int
ostream& operator<<(ostream& out, const int& n) {
    if (n == 0) {
        out << 0;
        return out;
    }
    string s = "";
    int num = n;
    if (num < 0) {
        out << '-';
        num = -num;
    }
    while (num > 0) {
        s += (num % 10) + '0';
        num /= 10;
    }
    reverse(s.begin(), s.end());
    out << s;
    return out;
}


int32_t main() {
    int x;
    cin >> x;
    cout << x << endl;
}

