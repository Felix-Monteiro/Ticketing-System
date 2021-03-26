#include <iostream>
#include <iomanip>
#include <string>
#include<conio.h>

using namespace std;

class showSeat
{
public:
	showSeat();
	~showSeat();
	void initialiseFloorPlan();
	int getNumSeats();
	double getSeatSelection();


protected:
	char floorPlan[7][6];
	int numSeats;
	int rNum;
	double price;

private:
	void displayFloorPlan(int r, int c);
	void calculatePrice(double price);
};
////////////////////////////////////////////////////////////////////////////////////////////////////
//constructor
showSeat::showSeat()
{
	for (int  r = 0; r < 7; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			floorPlan[r][c] = 0;
		}
	}

    numSeats =0 ;
	rNum = 0;
	price=0 ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//destructor
showSeat::~showSeat()
{

}
////////////////////////////////////////////////////////
//Starts the Floor plan 
void showSeat::initialiseFloorPlan()
{
	for (int r = 0; r < 7; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			floorPlan[r][c] = 'A'; //character
		}

	}

}
////////////////////////////////////////////////////////////////
//Asks the user to choose number of seats
int showSeat::getNumSeats()
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT SEATS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << endl;
	do
	{
		cout << "Please enter the number of seats desired (max:8): "<<endl;
		cin >> numSeats;

	} while (numSeats<1 || numSeats>8);

	return numSeats;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//Get the user to select the seats they want
double showSeat::getSeatSelection()
{
	char ch;
	int r = -1;
	int c = -1;
	displayFloorPlan(r,c);
	do
	{
		for (int i = 0; i < numSeats; i++)
		{
			char terminator;
			do
			{
				cout << "Please enter a row number between 1 and 7: ";
				cin >> r;
				r = (r - 1);
			} while (r<0 || r>7);
			rNum = r;
			do
			{
				cout << "Please enter a column number between 1 and 6: ";
				cin >> c;
				c = (c - 1);
			} while (c<0 || c>6);




			while (floorPlan[r][c] == 'H')
			{
				cout << "Seat is unavailable.\n ";
				do
				{
					cout << "Please re-enter a row number between 1 and 7: ";
					cin >> r;

				} while (r < 1 || r > 7);
				do
				{
					cout << "Please re-enter a column number between 1 and 6: ";
					cin >> c;

				} while (c < 1 || c > 6);

			}
			
			floorPlan[r][c] = 'H';
			calculatePrice(price); 

			
			
		}

		system("CLS");
		displayFloorPlan(r, c);
		

		do
		{
			cout << "Please check your seat.\n";
			cout << "Are you happy with your selection? (Y/N) ";
			cin >> ch;

		} while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');

		if ( ch!='Y' && ch!='y')
		{
			initialiseFloorPlan();
			cout << "Please reselect your seats. ";
			price = 0;
		}
		
	} while (ch=='n' || ch=='N');


	return price;
	
	
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Displays the Floor Plan

void showSeat::displayFloorPlan(int r, int c)
{
	char terminator;

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT SEATS INTERACTIVELY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << endl;




	cout<< "                                            |  1  |  2  |  3  |  4  |  5  |  6  |";
	for (int r = 0; r < 7; r++)
	{
		
		cout <<"\n\n"<<setw(42)<< (r+1)<<"|";
		for (int c = 0; c < 6; c++)
		{
			
			cout <<"    "<< floorPlan[r][c]<<" ";
		}
	}
	cout << "\n                                               ~~~~~~~~~~~ Key ~~~~~~~~~~~\n ";
	cout << "                                                    A= Availeble seat\n";
	cout << "                                                      H= Held seat\n";
	


}
////////////////////////////////////////////////////////////////////////////////////////////////////
//Calculates the price of the tickets 
void  showSeat::calculatePrice(double price)
{

	if (rNum >= 0 && rNum <= 4)
	{
		price = price + 20;
	}

	if (rNum >= 5 && rNum <= 7)
	{
		price = price + 30;

	}
	this->price = price;
}

