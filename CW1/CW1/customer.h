#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <time.h>

using namespace std;

class Customer
{
public:
	Customer();
	~Customer();
	void getLogin();
	void getProfileInfo(string &FName, string &LName, string &address);
	void getPaymentInfo();

protected:
	string FName;
	string LName;
	string address;

};
////////////////////////////////////////////////////////////////////////////////////////////////////
//constructor
Customer::Customer()
{

	FName = "";
	LName = "";
	address = ""; //initialise variables

}
////////////////////////////////////////////////////////////////////////////////////////////////////
//destructor
Customer::~Customer()
{
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//Deals with the Customer's Login
void Customer::getLogin()
{
	string username;
	string password;

	

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOG IN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << endl;
	cout << "                     Welcome to the Bucks Center for the Performing Arts ticket purchasing system!\n";
	cout << "                                                     Please log in.\n\n\n";

	cout << "Enter username: ";
	getline(cin, username);
	
	while (username.length()>10)
	{
		cout << "Your username should be no more than 10 characters long." << endl;
		cout << "Please re-enter yout username";
		getline(cin, username);
	}

	cout << "Enter password: ";
	getline(cin, password);

	while (password.length() > 10)
	{
		cout << "Your password should be no more than 10 characters long." << endl;
		cout << "Please re-enter yout username";
		getline(cin, password);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//Gets the Customers Personal Information
void Customer::getProfileInfo(string &FName, string &LName, string &address)
{
	
	

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENTER PROFILE INFORMATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << endl;
	cout << "As you are a new customer, you must provide your profile information.\n";
	cout << "_____________________________________________________________________\n";
	cout << "Enter your first name: \n";
	getline(cin, FName);
	

	cout << "Enter your last name: \n";
	getline(cin, LName);
	

	cout << "Enter your address: \n";
	getline(cin, address);
	


}
////////////////////////////////////////////////////////////////////////////////////////////////////
//Deals with the transaction
void Customer::getPaymentInfo()
{
	string Busername;
	string Bpassword;

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENTER PAYMENT INFORMATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" << endl;
	
	cout << "\nEnter Bank username: "<<endl;
	cin >> Busername ;

	while (Busername.length() > 10)
	{
		cout << "Your username should be no more than 10 characters long." << endl;
		cout << "Please re-enter yout username";
		cin >> Busername;
	}

	cout << "\nEnter Bank password: " << endl;
	cin >> Bpassword;

	while (Bpassword.length() > 10)
	{
		cout << "Your password should be no more than 10 characters long." << endl;
		cout << "Please re-enter yout username";
		cin >> Bpassword;
	}

	cout << "Processing information..." << endl;
	Sleep(3000); //Sleeps for 3000 ms or 3 sec
	cout << "Transaction accepted!" << endl;
	Sleep(3000); //Sleeps for 3000 ms or 3 sec
}