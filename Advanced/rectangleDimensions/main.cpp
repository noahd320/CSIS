#include <iostream>
#include <iomanip>
#include "Rectangle.h"
using namespace std;

//These two booleans will validate the length and width of the users input to ensure they are not negative.
bool validateWidth(double Width);
bool validateLength(double Length);

int main()
{
	double Width = 0;
	double Length = 0;
	double areaOfRectangle = 0;
	double perimeterOfRectangle = 0;
	double diagonalOfRectangle = 0;
	int choice = 0;
	
	//Object name total is used to call class functions.
	Rectangle total;
  cout << "This program will calculate the area, perimeter, and diagaonal measurement of rectangle." << endl;

	system("pause");

	//While loop to ensure program will run repeatedly until the user inputs -1 to quit.
	while (Width != -1 || Length != -1)
	{
		cout << "Please enter in the width of the rectangle, or enter -1 to quit: ";
		cin >> Width;
		//Checking the users input.
		bool validWidth = validateWidth(Width);
		while (validWidth != true)
		{
			cout << "Please enter in the width of the rectangel: "; cin >> Width; cout << endl;
			validWidth = validateWidth(Width);
		}

		cout << "Please enter in the length of the rectangle, or enter -1 to enter: ";
		cin >> Length;
		//If statement to break the while loop is -1 is entered.
		if (Length == -1)
		{
			return 0;
		}
		//Checking the users input.
		bool validLength = validateLength(Length);
		while (validLength != true)
		{
			cout << "Please enter in the length of the rectangle: "; cin >> Length; cout << endl;
			validLength = validateLength(Length);
		}

		//Setters called on in order to take the users inputs and apply them to the functions in the class
		total.setWidth(Width);
		total.setLength(Length);
		total.calcArea();
		total.calcDiagonal();
		total.calcPerimeter();
		total.showData();

		//Once the data is shown to the user they can either break the loop with -1 or perform calcualtions on another triangle.
		cout << "Do you want to continue?" << endl;
		cout << "If so enter any number, otherwise enter -1: "; cin >> choice;
		if (choice == -1)
		{
			return 0;
		}

	}
	
}
//Boolean function to check if the number that was entered is greater than zero and reprompt the user if it is
bool validateWidth(double Width)
{
	bool bolWidth(true);

	if (cin.fail() || Width <= 0)
	{
		cout << "You must enter a positive number." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		bolWidth = false;
	}
	return bolWidth;
}

//Boolean function to check if the number that was entered is greater than zero and reprompt the user if it is
bool validateLength(double Length)
{
	bool bolLength(true);

	if (cin.fail() || Length <= 0)
	{
		cout << "You must enter a positive number." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		bolLength = false;
	}
	return bolLength;
}
