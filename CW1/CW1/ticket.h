#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

class ticket
{
public:
	ticket();
	~ticket();
	void getTicketinfo(string &FName, string &LName, string &address, string & showName, string &showDate, string &showTime,double price,int numSeats, double discount);
	double getDiscount(double price,double discount);
	char ch;
private:
	double discount = 0;
	char code;
};
////////////////////////////////////////////////////////////////////////////////////////////////////
//constructor
ticket::ticket()
{


}
////////////////////////////////////////////////////////////////////////////////////////////////////
//destructor
ticket::~ticket()
{
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Gets and prints the information of the ticket
void ticket::getTicketinfo(string &FName, string &LName, string &address, string & showName, string &showDate, string &showTime, double price, int numSeats,double discount)
{
	char terminator;
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ YOUR TICKETS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" << endl;
	cout << "========================================================================================================================\n" << endl;
	cout << "========================================== The Bucks Center for the Performing Arts ====================================\n" << endl;
	cout << "===================================================== Enjoy the show ===================================================\n\n" << endl;

	cout << "Show: "<< showName<<endl;
	cout << "Date: " << showDate<<endl;
	cout << "Time: " << showTime<<endl;
	cout << "========================================================================================================================\n" << endl;

	cout << "Number of Seats: " <<numSeats<<endl;
	cout << "Total cost:  "<<(char)156 <<(discount)<< endl;
	cout << "Ticket Purchaser: " << FName << " " << LName<<endl;
	cout << "Postal address: " << address<<endl;
	cout << "========================================================================================================================\n\n" << endl;
	cout << "========================================================================================================================\n" << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Asks the User to use any discount in case of having one
double ticket::getDiscount(double price,double discount)
{
	
	char terminator;

	

	do
	{
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DISCOUNT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << endl;

		cout << "1. 10% Discount" << endl;
		cout << "2. 30% Discount" << endl;
		cout << "3. 50% Discount\n" << endl;
		cout << "4. Do not have any discount code.\n" << endl;
		cout << "Please choose a discount: ";
		cin.get(ch);

		while (ch != '1' && ch != '2' && ch != '3' && ch!='4')
		{
			cin.clear();
			cin.ignore(100, '\n');// ensures buffer is completrly clear (if, say, the user has previosly input a long string)
			cout << "Please select a valid discount choice number: ";
			cin.get(ch);
		}
		if (ch == '1')
		{
			
			discount = price* 0.9;
			cout << "Please enter your discount coupon code: " << endl;
			cin >> code;

			cout << "Processing information..." << endl;
			Sleep(3000); //Sleeps for 3000 ms or 3 sec
			cout << "Code accepted!" << endl;

		}

		if (ch == '2')
		{
			discount = price* 0.7;
			cout << "Please enter your discount coupon code: " << endl;
			cin >> code;

			cout << "Processing information..." << endl;
			Sleep(3000); //Sleeps for 3000 ms or 3 sec
			cout << "Code accepted!" << endl;
		}
		if (ch == '3')
		{
			discount = price* 0.5;
			cout << "Please enter your discount coupon code: " << endl;
			cin >> code;

			cout << "Processing information..." << endl;
			Sleep(3000); //Sleeps for 3000 ms or 3 sec
			cout << "Code accepted!" << endl;

		}
		if (ch=='4')
		{
			discount = price;
			cout << "Thank you!" << endl;
		}




	} while (ch == '1'&& ch == '2' && ch == '3');

	return discount;
	return price;
}