#include <iomanip>
#include <string>
#include <vector>
#include "SalesPerson.h"
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	string userFilePath, _SalesName, _DealershipName;
	int _salesGoal = 0;
	int _commissionRate = 0;
	double completedSale = 0;
	ifstream inFile;

	SalesPerson allInfo;

	cout << "This program will take in a users file and then calculate various tasks for a car dealership company." << endl;

	system("pause");

	cout << "Please enter in the file path. ";
	getline(cin, userFilePath);

	inFile.open(userFilePath);
	cout << endl;

	getline(inFile, _SalesName);
	allInfo.setSalesPersonName(_SalesName);

	getline(inFile, _DealershipName);
	allInfo.setDealershipName(_DealershipName);

	inFile >> _salesGoal;
	allInfo.setSalesGoal(_salesGoal);

	inFile >> _commissionRate;
	allInfo.setCommissionPercentage(_commissionRate);


	//while loop in order to get all the sales data line by line until the end
	while (!inFile.fail() && completedSale >= 0)
	{
		inFile >> completedSale;
		if (inFile.fail() && !inFile.eof())
		{
			cout << "Non-numeric value found in the file. Closing the program, check the file and try again." << endl;
		}
		else if (completedSale < 0)
		{
			cout << "A negative value was found in the file. Closing the program, check the file and try again." << endl;
		}
		else
		{
			allInfo.addSalesAmount(completedSale);
		}
	}

	allInfo.displaySalesInfo();
	cout << "End of program" << system("pause");
	return 0;
}
