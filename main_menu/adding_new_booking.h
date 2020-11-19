#include <iostream>
#include <fstream>

using namespace std;


void ask_date_details(int *day, int *month, int *year){
	//function of asking date and checking is it correct
	re_day:
	cout << "Day: ";
	*day = 0;
	cin >> *day;
	if (*day < 1 || *day > 31)
	{
		cout << "Please enter day normaly!" << endl;
		goto re_day;
	}

	re_month:
	cout << "Month: ";
	*month = 0;
	cin >> *month;
	if (*month < 1 || *month > 12)
	{
		cout << "Please enter month normaly!" << endl;
		goto re_month;
	}

	re_year:
	cout << "Year: ";
	*year = 0;
	cin >> *year;
	if (*year < 2020)
	{
		cout << "Please enter year normaly!" << endl;
		goto re_year; 
	}
}

int calculate_day(int y, int m, int d){
	//function wich calculates daysfrom start of year till the date which he take
	m = (m + 9) % 12;
	y = y - m/10;
	return 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + ( d - 1 );
}

void ask_date(){
	int day, month, year, days;
	ofstream myhotel; 
	myhotel.open("hotel.txt", ios::app); // opening file where we will save all our bookings
	system("CLS");
	cout << "Adding new booking window" << endl;
	cout << "Please enter the date of ariving: " << endl;
	ask_date_details(&day, &month, &year); // function which takes data from client and checking it  1<=day<=31, 1<=month<=12, year => 2020
	myhotel << "\n {" << day << "," << month << "," << year << ","; // saving data to file
	days = calculate_day(year, month, day); // calculating days from start of year
	cout << "Please enter the date of lieving:" << endl;
	ask_date_details(&day, &month, &year); // function which takes data from client and checking it  1<=day<=31, 1<=month<=12, year => 2020
	days = calculate_day(year, month, day) - days; // days untill days for finishing date - day untill start will give amount of days for living
	myhotel << day << "," << month << "," << year << "," << days << "} \n"; // saving data to file
	myhotel.close(); //closing document
}


int adding_new_booking(){
	//main function of adding new booking
	ask_date(); // first step of booking : Asking date

	return 0;
}



