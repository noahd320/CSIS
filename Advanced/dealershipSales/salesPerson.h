#pragma once
#include <vector>
#include <string>
#include <algorithm>

class SalesPerson
{
public:
	SalesPerson();
	SalesPerson(std::string _SalesName, std::string _DealershipName, int _salesGoal, int _commissionPercentage);
	//~SalesPerson();


	//Setters and getters
	void setSalesPersonName(std::string);
	std::string getSalesPersonName() const;

	void setDealershipName(std::string);
	std::string getDealershipName() const;

	void setSalesGoal(int _salesGoal);
	int getSalesGoal() const;

	void setCommissionPercentage(int _commissionPercentage);
	int getCommissionPercentage() const;


	//Functions to calculate all information about sales
	void addSalesAmount(double amount);
	double calcSalesAverage();
	double calcTotalSales();
	double calcCommissionEarned();

	//Functions for data post calculations
	void sortSalesAmount();
	double getSmallestSale();
	double getLargestSale();

	//Display all of the information
	void displaySalesInfo();

private:
	//Setting up the vector of 'sales' that will be ammended through the program
	std::vector<double> sales;

	std::string salesPersonName;
	std::string dealershipName;
	int numberOfSales;
	int salesGoal;
	int commissionPercentage;

};
