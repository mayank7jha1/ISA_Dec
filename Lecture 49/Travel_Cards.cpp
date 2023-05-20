#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int Travel_Cards() {
	int n, a, b, k, f;
	cin >> n >> a >> b >> k >> f;

	map<pair<string, string>, int>mp;//This cannot be a Unordered map.

	/*
		Map Stores the data of the path and cost of that path.

		Please remember we are talking about path not trip.

		How will i ensure ki aa-->bb and bb-->aa goes as a same key:

		i will compare the two strings i.e starting point and ending point and put the
		lexographically smaller string first as my first element in pair.
	*/

	string prev_dest = "";//Because i want to check for transshipment.

	//Jo jo trip input me digayi hain usko map ke ander as path daal do and path ka cost calculate karo.

	for (int i = 0; i < n; i++) {

		string start_point, end_point;
		cin >> start_point >> end_point;

		int price;//Mujhe ye batayega ki is trip ka cost kya hain before i add this trip as path in map.


		if (prev_dest == start_point) {
			//THis is a transshipment
			price = b;
		} else {
			price = a;
		}

		prev_dest = end_point;//Update this for the next trip;


		/*
			Main jab 44 line par khada hu: toh main har trip ka price ab ek ek karke nikal sakta hu.

			Kyuki mujhe is trip ka cost pata hain ab main is trip ko as path insert kardeta hu
			map and and path ka cost increase kardeta hu bu the price of this trip.
		*/

		//Price:

		if (start_point > end_point) {
			swap(start_point, end_point);
		}


		/*
			Agar ek key already map me hai to is trip ka cost ussi key/path me add kardo
			varna new banake add kardo.
		*/

		if (mp.find({start_point, end_point}) != mp.end()) {
			//matlab ye path pehle se map me hain.

			//Update kardo is key par is trip ka cost;

			mp[ {start_point, end_point}] = mp[ {start_point, end_point}] + price;

		} else {

			mp[ {start_point, end_point}] = price;
		}
	}

	//Ab mere pass map ke ander har ek path ka cost available hain.



	/*

			Please refer to another file named Travel_Cards2 for rest of the code.
	*/

}



int main() {
	cout << Travel_Cards();
}

// prev_dest = "";

// 1. aa-- > bb;

// prev_dest = end_point;

// 2.  bb-- > aa


/*\


	map<pair<string,string>,int>m;

	map ka key is a pair of string and string.

	JO represent karte hain path ko


	map<string,int>mp2;

	m["Akanksha"]=100;

	cout<<m["Akanksha"]<<endl;

	m["Akanksha"]=m["Akanksha"]+200;

	m["Akanksha"]+=200;

	cout<<m["Akanksha"]<<endl;

	key==Pair<string,string>

	map[{"Aa","bb"}]=100;

	map[{"Aa,bb"}]+=200;

	cout<<m[{"Aa,bb"}]<<endl;





	map[{"aa","bb"}]+=120;

	map[{"bb","aa"}]+=120;

	map[{"aa","bb"}]+=120;

	map[{"aa","bb"}]+=120;

	map[{"bb","aa"}]+=120;

	map[{"aa","bb"}]+=120;



	cout<<m[{"aa","bb"}]<<endl;   //480
	cout<<m[{"bb","aa"}]<<endl;   //240


	Path ka matlab in this question: aa-->bb and bb-->aa iska matlab mujhe dono ka cost ek sath store
	karna hain.

	path is represented by aa,bb===720

	agar aa-->bb and bb-->aa ko same kaise banau?

	swap:

	data aayega trip ka aap usko jo dono me staring point and ending point me se chota hain
	usko pehle likho matlab agar starting point bada hai to swap kardo ending point se.


	map[{"aa","bb"}]+=120;

	map[{"aa","bb"}]+=120;

	map[{"aa","bb"}]+=120;

	map[{"aa","bb"}]+=120;

	map[{"aa","bb"}]+=120;

	map[{"aa","bb"}]+=120;


	cout<<map[{"aa","bb"}]=720;

*/