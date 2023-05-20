
#include<iostream>
#include<utility>
#include<vector>
using namespace std;
const int N = 0;


//Data in the form 2 elements: and those two elements are related to each other
//How to store this data: STL: Utility Class/Cntainer: Pair

int main() {
	//Declare a Pair
	pair<string, int>p1;

	p1.first = "Mayank";
	p1.second = 100;

	cout << p1.first << " " << p1.second << endl;

	//Initialise:
	vector<int>v{1, 2, 3, 4, 5};

	pair<string, int>p2("Mayank", 200);
	cout << p2.first << " " << p2.second << endl;

	vector<int>ans;

	ans.push_back(100);

	//Declaration
	pair<string, int>p3;

	//Initialisation
	p3 = make_pair("Mayank", 300);

	//{}--->Multiple Elements

	//Container that can be reinitialised and {}.
	p3 = {"Samyak", 500};

	cout << p3.first << " " << p3.second << endl;


	vector<int>ans2(v);//ans2 vector ke ander v ki values aajati hain

	pair<string, int>p4(p3);//p4 ke ander p3 ki values aajati hain.


	vector<int>ans3 = v;

	pair<string, int>p5 = p3;

}