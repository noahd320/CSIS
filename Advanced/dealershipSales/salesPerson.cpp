#include "SalesPerson.h"
#include<iomanip>
#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>

//Setting the values to zero initially
SalesPerson::SalesPerson()
{
	SalesPerson::setSalesPersonName("");
	SalesPerson::setDealershipName("");
	SalesPerson::setSalesGoal(0);
	SalesPerson::setCommissionPercentage(0);
}

SalesPerson::SalesPerson(std::string _SalesName, std::string _DealershipName, int _salesGoal, int _commissionPercentage)
{
	SalesPerson::setSalesPersonName(_SalesName);
	SalesPerson::setDealershipName(_DealershipName);
	SalesPerson::setSalesGoal(_salesGoal);
	SalesPerson::setCommissionPercentage(_commissionPercentage);
}

void SalesPerson::setSalesPersonName(std::string _SalesName)
{
	salesPersonName = _SalesName;
}
std::string SalesPerson::getSalesPersonName() const
{
	return salesPersonName;
}

void SalesPerson::setDealershipName(std::string _DealershipName)
{
	dealershipName = _DealershipName;
}
std::string SalesPerson::getDealershipName() const
{
	return dealershipName;
}

void SalesPerson::setSalesGoal(int _salesGoal)
{
	salesGoal = _salesGoal;
}
int SalesPerson::getSalesGoal() const
{
	return salesGoal;
}
void SalesPerson::setCommissionPercentage(int _commissionPercentage)
{
	commissionPercentage = _commissionPercentage / 100;
}
int SalesPerson::getCommissionPercentage() const
{
	return commissionPercentage;
}

void SalesPerson::addSalesAmount(double _completedSale)
{
	//add the sales amount to the vector

	sales.push_back(_completedSale);
}

double SalesPerson::calcSalesAverage()
{
	//take the sumOfSales and divide by how many sales
	double salesAvg = calcTotalSales() / sales.size();
	return salesAvg;
}

double SalesPerson::calcCommissionEarned()
{
	//multiply the commission goal by the sumOfSales
	double commissionEarned = calcTotalSales() * commissionPercentage;
	return commissionEarned;
}

double SalesPerson::calcTotalSales()
{
	//find the sumOfSales based on all the values passed into the vector
	double sumOfSales = std::accumulate(sales.begin(), sales.end(), 0);
	return sumOfSales;
}

void SalesPerson::sortSalesAmount()
{
	//Use std::sort to display each element of the vector from smallest to largest
	sort(std::begin(sales), std::end(sales));
}

double SalesPerson::getSmallestSale()
{
	int smallestSale = sales[0];
	for (int i = 1; i <= sales.size(); i++)
	{
		if (sales[i] < smallestSale)
		{
			smallestSale = sales[i];
		}
	}
	return smallestSale;
}

double SalesPerson::getLargestSale()
{
	int largestSale = sales[0];
		for (int i = 1; i <= sales.size(); i++)
		{
			if (sales[i] > largestSale)
			{
				largestSale = sales[i];
			}
		}
		return largestSale;
}

void SalesPerson::displaySalesInfo()
{
	/*
	* Display line by line
	* Sales name
	* Dealership name
	* Sale goal
	* Total sale
	* number of sales
	* average sale
	* commission goal
	* commission earned
	* smalles sale
	* largest sale
	* sorted list of sale one per line
	*/

	std::cout << "Dealership: " << getDealershipName() << std::endl;
	std::cout << "Salesperson: " << getSalesPersonName() << std::endl;
	std::cout << "Sales Goal: " << getSalesGoal() << std::endl;
	std::cout << "Total Sales: " << calcTotalSales() << std::endl;
	std::cout << "Number of sales: " << sales.size() << std::endl;
	std::cout << "Average Sale Amount: " << calcSalesAverage() << std::endl;
	std::cout << "Commission Percentage Rate: " << getCommissionPercentage() << std::endl;
	std::cout << "Commission Earned: " << calcCommissionEarned() << std::endl;
	std::cout << "Smallest Sale: " << getSmallestSale() << std::endl;
	std::cout << "Largest Sale: " << getLargestSale() << std::endl;
	sortSalesAmount();
	std::cout << "List of sales sorted: ";
	for (int i = 1; i <= sales.size(); i++)
	{
		std::cout << sales[i] << '\n';
	}
	std::cout << std::endl;
}
