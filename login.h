#include <iostream>
#include <string>

using namespace std;


int login(){
	string username, password;
	int exit;
	system("CLS");
	if_error:
	cout << "Please login to system:" << endl;
	cout << "Username: ";
	cin >> username;
    cout << "Password: ";
    cin >> password;
    if(password == "admin" && username == "admin"){
       return 1;
    }else{
    	cout << "Password or username is incorrect." << endl;
        cout << "If you want exit press 1 else enter 0 : ";
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