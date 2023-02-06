#pragma once
#include <iostream>

class Rectangle
{
public:
	Rectangle();
	Rectangle(double, double);

	//Setters and getters to take the users input and pass it to the private data members
	void setWidth(double);
	double getWidth() const;
	void setLength(double);
	double getLength() const;

	//Functions that will do the math based on the users input for Length and Width
	double calcPerimeter() ;
	double calcArea() ;
	double calcDiagonal() ;

	//This function will out put the data from the fucntions above
	void showData() ;
	


private:
	//These are private to ensure that the these data members cannot be manipulated while calculations are being done
	double Length;
	double Width;
	double areaOfRectangle;
	double perimeterOfRectangle;
	double diagonalOfRectangle;
};
