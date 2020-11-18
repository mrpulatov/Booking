#include <iostream>
#include "main_menu/adding_new_booking.h"



using namespace std;

int main_menu()
{
	int number;
	main_menu_restart:
	system("CLS");
	cout << "Welcome to main menu of Hotel Booking system!" << endl << endl;
	cout << "1. Display all orders" << endl;
	cout << "2. Add new booking" << endl;
	cout << "3. Remove booking" << endl;
	cout << "4. Exit" << endl;
	enter_number:
	cin >> number;
	if (number < 1 || number > 4)
	{
		cout << "Please choose one from menu" << endl;
		goto enter_number;
	}
	switch (number){
		case 1:
			//function to display all orders
			goto main_menu_restart;
		case 2:
			//function to add new booking
			adding_new_booking();
			goto main_menu_restart;
		case 3:
			//function to delete booking
			goto main_menu_restart;
		case 4:
			return 0;
	}
	return 0;
}