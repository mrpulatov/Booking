#include <iostream>
#include <fstream>

using namespace std;


void ask_date_details(int *day, int *month, int *year){
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
	m = (m + 9) % 12;
	y = y - m/10;
	return 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + ( d - 1 );
}

void ask_date(){
	int day, month, year, days;
	ofstream myhotel; 
	myhotel.open("hotel.txt", ios::app); 
	system("CLS");
	cout << "Adding new booking window" << endl;
	cout << "Please enter the date of ariving: " << endl;
	ask_date_details(&day, &month, &year);
	myhotel << "{" << day << "," << month << "," << year << ",";
	days = calculate_day(year, month, day);
	cout << "Please enter the date of lieving:" << endl;
	ask_date_details(&day, &month, &year);
	days = calculate_day(year, month, day) - days;
	myhotel << day << "," << month << "," << year << "," << days << "} \n";
	myhotel.close();
}


int adding_new_booking(){
	//main function of adding new booking
	ask_date(); // first step of booking : Asking date

	return 0;
}



