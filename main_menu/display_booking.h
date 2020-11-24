#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>


using namespace std;


int display_booking(){
	int i=0;

	string one_booking;
	ifstream all_data("hotel.txt");
	system("CLS");
	stringstream ss(one_booking);
	while (getline(all_data, one_booking)){
		cout << "***************************************************************************\n";
		
		vector <string> v;

		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			v.push_back(substr);
		}
		cout << "\t\t\t\tFirst name: " << v[7] << endl;
		cout << "\t\t\t\tLast name: " << v[8] << endl;
		cout << "\t\t\t\tPassport number: " << v[9] << endl;
		cout << "\t\t\t\tRoom with " << v[10] << " bed." << endl;
		cout << "\t\t\t\tFor option: " << v[11] << endl;
		cout << "\t\t\t\tDates " << v[0] << "/" << v[1] << "/" << v[2] << " - ";
		cout << v[3] << "/" << v[4] << "/" << v[5] << "  (" << v[6] << " days)\n";
		cout << "\n \t\t\t\t\t\tPrice: " << v[12] << endl;
		cout << "***************************************************************************\n";
	}



	system("pause");
	return 0;
}