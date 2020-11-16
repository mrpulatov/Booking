#include <iostream>
#include "login.h"

using namespace std;

int main()
{
	int login_status;
	login_status=login();
	if (login_status==1)
	{
		cout << "Good";
	}
	cout << endl;
	system("pause");
	return 0;
}