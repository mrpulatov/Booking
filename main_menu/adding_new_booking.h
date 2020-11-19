#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string data_of_client[12];


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
	system("CLS");
	cout << "Adding new booking window" << endl;
	cout << "Please enter the date of ariving: " << endl;
	ask_date_details(&day, &month, &year); // function which takes data from client and checking it  1<=day<=31, 1<=month<=12, year => 2020
	data_of_client[0]=to_string(day);
	data_of_client[1]=to_string(month);
	data_of_client[2]=to_string(year); // saving data to variable
	days = calculate_day(year, month, day); // calculating days from start of year
	cout << "Please enter the date of lieving:" << endl;
	ask_date_details(&day, &month, &year); // function which takes data from client and checking it  1<=day<=31, 1<=month<=12, year => 2020
	days = calculate_day(year, month, day) - days; // days untill days for finishing date - day untill start will give amount of days for living
	data_of_client[3]=to_string(day);
	data_of_client[4]=to_string(month); 
	data_of_client[5]=to_string(year); 
	data_of_client[6]=to_string(days); // saving data to variable
}

void ask_user_info(){
	string user_name,user_last_name,user_passport;
	//function of asking details of client
	system("CLS");
	cout << "Adding new booking window" << endl;
	cout << "The first step complited sucsessfully!" << endl;
	cout << "Second step: adding user info" << endl;
	cout << "Please enter your First name: ";
	cin >> user_name;
	cout << "Please enter your Last name: ";
	cin >> user_last_name;
	cout << "Please enter your passport info: ";
	cin >> user_passport;
	data_of_client[7]= user_name;
	data_of_client[8]= user_last_name;
	data_of_client[9]= user_passport; // saving data to variable
}

void asking_datailes_of_booking(){
	int numbers_of_bed, meal_option;
	//function of asking options of booking
	system("CLS");
	cout << "Adding new booking window" << endl;
	cout << "Great! Now you will go through small survey to identify details of booking." << endl;
	cout << "How many bad do you want? For now we have only 2 options 1 bed and 2 bed rooms" << endl;
	enter_num:
	cout << "Numbers of beds: ";
	cin >> numbers_of_bed;
	if (numbers_of_bed<1 || numbers_of_bed >2)
	{
		goto enter_num;
	}
	cout << "Now choose one of the options option" << endl;
	cout << "1 Kitchen in my room" << endl;
	cout << "2 With breakfast" << endl;
	cout << "3 None of this" << endl;
	enter_meal_option:
	cout << "Option: ";
	cin >> meal_option;
	if ( meal_option<1 || meal_option>3)
	{
		goto enter_meal_option;
	}
	data_of_client[10]= to_string(numbers_of_bed);
	data_of_client[11]= to_string(meal_option); // saving data to variable
}

void finishing_booking(){
	ofstream myhotel; 
	//function of saving
	myhotel.open("hotel.txt", ios::app); // opening file where we will save all our bookings
	myhotel << "{" ;
	for (int i = 0; i < 12; ++i)
	{
		myhotel << data_of_client[i]; // saving each data one buy ine it to text file
		if (i != 11) // this structure will add coma after all elements exept of 11th
		{
			myhotel << ",";
		}
	}
	myhotel << "}\n";
	myhotel.close(); //closing document
}

int adding_new_booking(){
	//main function of adding new booking
	ask_date(); // first step of booking : Asking date
	ask_user_info(); // second step asking information of client
	asking_datailes_of_booking(); //third step is to know what they want
	finishing_booking(); // the last step of booking 

	return 0;
}



