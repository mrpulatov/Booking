#include <iostream>

using namespace std;

int date_s[3], days;

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

void ask_date(){
	int day, month, year, a;
	system("CLS");
	cout << "Adding new booking window" << endl;
	cout << "Please enter the date of ariving: " << endl;
	ask_date_details(&day, &month, &year);
	date_s[0]=day;
	date_s[1]=month;
	date_s[2]=year;
	cout << "Please enter the days you want to live: " << endl;
	cin >> days;
}


int adding_new_booking(){
	ask_date();

	return 0;
}



