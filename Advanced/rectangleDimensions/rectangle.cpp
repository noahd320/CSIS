#include "Rectangle.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

Rectangle::Rectangle()
{
	//Initally the values will be zero
	Rectangle::setLength(0);
	Rectangle::setWidth(0);
}

Rectangle::Rectangle(double Width, double Length)
{
	Rectangle::setWidth(Width);
	Rectangle::setLength(Length);
}

void Rectangle::setWidth(double width)
{
	Width = width;
}
double Rectangle::getWidth() const
{
	return Width;
}

void Rectangle::setLength(double length)
{
	Length = length;
}
double Rectangle::getLength() const
{
	return Length;
}


// Based on the input from the user these functions will get the Area, Perimeter, and the Diagonal measurements of the rectangle.
double Rectangle::calcArea() 
{
	areaOfRectangle = getWidth() * getLength();
	return areaOfRectangle;
}

double Rectangle::calcPerimeter() 
{
	perimeterOfRectangle = (2 * getWidth()) + (2 * getLength());
	return perimeterOfRectangle;
}

double Rectangle::calcDiagonal() 
{
	diagonalOfRectangle = sqrt(pow(getWidth(), 2) + pow(getLength(), 2));
	return diagonalOfRectangle;
}


//Here we have the function that will display the date to the user.
void Rectangle::showData() 
{
	cout << "Based on the data entered" << "\n";
	cout << "The area of the rectangle is: " << Rectangle::calcArea() << endl;
	cout << "The perimeter is: " << Rectangle::calcPerimeter() << endl;
	cout << "The diagonal measurement is: " << Rectangle::calcDiagonal() << endl;
}
