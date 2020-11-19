#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string data_of_client[13];

/*
	data_of_client[0]=day start
	data_of_client[1]=month start
	data_of_client[2]=year start
	data_of_client[3]=day end
	data_of_client[4]=month end
	data_of_client[5]=year end
	data_of_client[6]=days
	data_of_client[7]=name
	data_of_client[8]=lastname
	data_of_client[9]=passport
	data_of_client[10]=beds
	data_of_client[11]=extra optinon
	data_of_client[12]=price
*/


void ask_date_details(int *day, int *month, int *year){
	//function of asking date and checking is it correct
	re_day:
	cout << "\t\t\t\tDay: ";
	*day = 0;
	cin >> *day;
	if (*day < 1 || *day > 31)
	{
		cout << "\t\t\t\tPlease enter day normaly!" << endl;
		goto re_day;
	}

	re_month:
	cout << "\t\t\t\tMonth: ";
	*month = 0;
	cin >> *month;
	if (*month < 1 || *month > 12)
	{
		cout << "\t\t\t\tPlease enter month normaly!" << endl;
		goto re_month;
	}

	re_year:
	cout << "\t\t\t\tYear: ";
	*year = 0;
	cin >> *year;
	if (*year < 2020)
	{
		cout << "\t\t\t\tPlease enter year normaly!" << endl;
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
	cout << "\t\t\t\t\tAdding new booking window" << endl;
	cout << "\t\t\t\t\tPlease enter the date of ariving: " << endl;
	ask_date_details(&day, &month, &year); // function which takes data from client and checking it  1<=day<=31, 1<=month<=12, year => 2020
	data_of_client[0]=to_string(day);
	data_of_client[1]=to_string(month);
	data_of_client[2]=to_string(year); // saving data to variable
	days = calculate_day(year, month, day); // calculating days from start of year
	cout << "\t\t\t\t\tPlease enter the date of lieving:" << endl;
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
	cout << "\t\t\t\t\tAdding new booking window" << endl;
	cout << "\t\t\t\tPlease fill information about yourself." << endl;
	cout << "\n \t\t\t\tPlease enter your First name: ";
	cin >> user_name;
	cout << "\t\t\t\tPlease enter your Last name: ";
	cin >> user_last_name;
	cout << "\t\t\t\tPlease enter your passport number: ";
	cin >> user_passport;
	data_of_client[7]= user_name;
	data_of_client[8]= user_last_name;
	data_of_client[9]= user_passport; // saving data to variable
}

void asking_datailes_of_booking(){
	int numbers_of_bed, meal_option;
	//function of asking options of booking
	system("CLS");
	cout << "\t\t\t\t\tAdding new booking window" << endl;
	cout << "\n \t\t\t\t\t How many bad do you want? \n \t\t\t For now we have only 2 options 1 bed (40$ per day) and 2 bed (80$ per day) rooms." << endl;
	enter_num:
	cout << "\n \t\t\t\tNumbers of beds: ";
	cin >> numbers_of_bed;
	if (numbers_of_bed<1 || numbers_of_bed >2)
	{
		goto enter_num;
	}
	cout << "\n \t\t\t\t Now choose one of the options option" << endl;
	cout << "\t\t\t\t\t 1 Room with kitchen + 30$ for total price" << endl;
	cout << "\t\t\t\t\t 2 With breakfast + 4$ per day" << endl;
	cout << "\t\t\t\t\t 3 None of this" << endl;
	enter_meal_option:
	cout << "\t\t\t\tOption: ";
	cin >> meal_option;
	if ( meal_option<1 || meal_option>3)
	{
		goto enter_meal_option;
	}
	data_of_client[10]= to_string(numbers_of_bed);
	switch(meal_option){
		case 1:
		data_of_client[11]="Room with kitchen";
		break;
		case 2:
		data_of_client[11]="With breakfast";
		break;
		case 3:
		data_of_client[11]="With out option";
		break;// saving data to variable
	}
}

void finishing_booking(){
	system("CLS");
	int price;
	char verify;
	cout << "\t\t\t\t\t Thanks for choosing our hotel." << endl;
	cout << "\t\t\t\t\t Please verify your information:" << endl;
	cout << "\t\t\t\tFirst name: " << data_of_client[7] << endl;
	cout << "\t\t\t\tLast name: " << data_of_client[8] << endl;
	cout << "\t\t\t\tPassport number: " << data_of_client[9] << endl;
	cout << "\t\t\t\tRoom with " << data_of_client[10] << " bed." << endl;
	cout << "\t\t\t\tFor option: " << data_of_client[11] << endl;
	cout << "\t\t\t\tDates " << data_of_client[0] << "/" << data_of_client[1] << "/" << data_of_client[2] << " - ";
	cout << data_of_client[3] << "/" << data_of_client[4] << "/" << data_of_client[5] << "  (" << data_of_client[6] << " days)\n";
	cout << "\n \t\t\t\t\t\tPrice: ";
	price = stoi(data_of_client[6]) * stoi(data_of_client[10]) * 40;
	cout << "\t" << data_of_client[6] << " day * " << data_of_client[10] << " bed * 40$ = " << price << "$\n";

	cout << "\t\t\t\t\t\tFor option : '" << data_of_client[11];
	if (data_of_client[11] == "Room with kitchen")
	{
		cout << "' 30$\n";
		price = price + 30;
	}
	if (data_of_client[11] == "With breakfast")
	{
		cout << "' " << data_of_client[6] << " day * 4$ = " << stoi(data_of_client[6])*4 << "$\n";
		price = price + stoi(data_of_client[6])*4;
	}
	if (data_of_client[11] == "With out option")
	{
		cout << "' 0$\n";
	}
	cout << "\t\t\t\t\t\t\t\t Total: " << price << "$\n";
	data_of_client[12]=to_string(price);
	cout << "\n \t\t\t\t\tVerify booking? (y/n) : ";
	cin >> verify;
	if (verify == 121)
	{
		saving_booking();
	}
}

void saving_booking(){
	ofstream myhotel; 
	//function of saving
	myhotel.open("hotel.txt", ios::app); // opening file where we will save all our bookings
	myhotel << "{" ;
	for (int i = 0; i < 13; ++i)
	{
		myhotel << data_of_client[i]; // saving each data one buy ine it to text file
		if (i != 12) // this structure will add coma after all elements exept of 11th
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
	asking_datailes_of_booking(); //third step is to know what client want
	finishing_booking(); // the last step of booking 

	return 0;
}



