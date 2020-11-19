#include <iostream>
#include "main_menu/adding_new_booking.h"



using namespace std;

int main_menu()
{
	int number;
	main_menu_restart: // point of start menu
	system("CLS"); // clearing screan
	cout << "\t\t\t\t\tWelcome to main menu of Hotel Booking system!" << endl;
	cout << "\t\t\t\t1. Display all orders" << endl;
	cout << "\t\t\t\t2. Add new booking" << endl;
	cout << "\t\t\t\t3. Remove booking" << endl;
	cout << "\t\t\t\t4. Exit" << endl; // printting menu for client
	enter_number: // point for come back if client will enter not correct number
	cout << "\t\t\t\t\t\tSelect one option: ";
	cin >> number; // asking what client whant
	if (number < 1 || number > 4) // checking is client enter correct numbers
	{
		cout << "\t\t\t\t\t\tPlease choose one from menu" << endl;
		goto enter_number; // if no bo back to point entering number
	}
	switch (number){ // using switch condition for indentify what whant client
		case 1:
			//function to display all orders
			goto main_menu_restart; // after finishing process of displaying bookings will go to menu again
		case 2:
			//function to add new booking
			adding_new_booking();
			goto main_menu_restart; // after finishing process of adding new booking will go to menu again
		case 3:
			//function to delete booking
			goto main_menu_restart; // after finishing process of deleting booking will go to menu again
		case 4:
			return 0; // exit from menu and finish app
	}
	return 0;
}