#include <iostream>
#include "login.h"
#include "main_menu.h"

using namespace std;

int main()
{
	int login_status;
	
	login_status=login();
	if (login_status==1)
	{
		main_menu();
	}
	cout << endl;
	return 0;
}