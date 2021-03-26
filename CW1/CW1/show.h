#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Show
{
public:
	Show();
	~Show();
	void selectShow(string & showName, string &showDate);
	string selectTime(string &showTime);

protected:
	string showName;
	string showDate;
	string showTime;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//constructor
Show::Show()
{
	showName = "";
	showDate = "";
	showTime = "";
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//destructor
Show::~Show()
{
}

/////////////////////////////////////////////////////////////////////////////
//customer selects upcoming show
void Show::selectShow(string & showName, string &showDate)
{
	char ch;
	char terminator;

	system("CLS");

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT AN UPCOMING SHOW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << endl;

	cout << "1. Star Wars: The Musical (20/05/2013)" << endl;
	cout << "2. Les Miserables (21/05/2013)" << endl;
	cout << "3. The Phantom of the Opera (22/05/2013)" << endl;

	cin.clear();
	cin.ignore(100, '\n');// ensures buffer is completrly clear (if, say, the user has previosly input a long string)
	cout << "Please select a show number: ";
	cin.get(ch);

	while (ch != '1'&& ch != '2'&& ch != '3')
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please select a valid show number: ";
		cin.get(ch);
	}

	switch (ch)
	{
	case '1':showName = "Star Wars: The Musical", showDate = "20/05/2013";
		break;
	case '2':showName = "Les Miserables", showDate = "21/05/2013";
		break;
	case '3':showName = "The Phantom of the Opera", showDate = "22/05/2013";
		break;

	}

	this->showName = showName;
	this->showDate = showDate;//enters reference variable into class variable

	cin.get(terminator);//clears buffer
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//customer selects 1pm/7pm showing
string Show::selectTime(string &showTime)
{
	char ch;
	char terminator;

	system("CLS");

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT SHOW TIME ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << endl;

	cout << "1. 1pm show" << endl;
	cout << "2. 7pm show" << endl;



	cout << "Please select a show time number (1/2): \n";
	cin.get(ch);

	while (ch != '1'&& ch != '2')
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please select a valid show number: ";
		cin.get(ch);
	}

	switch (ch)
	{
	case '1':showTime = "1pm show";
		break;
	case '2':showTime = "7pm show";
		break;


	}

	this->showTime = showTime;


	cin.get(terminator);//clears buffer
	return showTime;

}