#include <iostream>
#include <string>

using namespace std;


int login(){
	string username, password;
	int exit;
	system("CLS");
	if_error:
	cout << "\t\t\t\t\tPlease login to system:" << endl;
	cout << "\t\t\t\tUsername: ";
	cin >> username;
    cout << "\t\t\t\tPassword: ";
    cin >> password;
    if(password == "admin" && username == "admin"){
       return 1;
    }else{
    	cout << "\n \t\t\t\t\tPassword or username is incorrect." << endl;
        cout << "\t\t\t\tIf you want exit press 1 else enter 0 : ";
        cin >> exit;
        if (exit==1)
        {
        	return 0;
        }
        system("CLS");
        goto if_error;
    }
    return 0;
}