//loanCalculation.cpp -- This program will is a mortgage calculator to determine monthly payments for loans
//and create an amortization schedule for the loan.

#include <iostream> 
#include <string> 
#include <limits>
#include <cmath>
#include <iomanip>
using namespace std;

//Function Prototypes
double PaymentCalculator(double loanPrinciple, double monthlyInterestRate, int numberOfPayments);
void LoanAmortizaeSchedule(int currentPeriod, int totalPeriods, double paymentAmount, double monthlyInterestRate, double currentBalance);

//Checking if the loan is an acceptable amount
bool validLoanAmount(double loanPrinciple)
{
    bool bolLoanAmount(true);
    if (cin.fail() || (loanPrinciple < 50000 || loanPrinciple > 100000))
    {
        cout << "Loans need to be between 50,000 and 100,000. Please enter another amount." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bolLoanAmount = false;
    }
    return bolLoanAmount;
}

//Checking if the loan years are 10 15 25 or 40
bool validLoanYears(double loanYears)
{
    bool bolLoanYears(true);
    if (cin.fail() || loanYears != 10 && loanYears != 15 && loanYears != 25 && loanYears != 40)
    {
        cout << "Loans can only be 10, 15, 25, or 40 years. Please select again!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bolLoanYears = false;
    }
    return bolLoanYears;
}

//Checking that annual interest is a positive number
bool validAnnualInterest(double annualInterest)
{
    bool bolAnnualInterest(true);
    if (cin.fail() || annualInterest <= 0)
    {
        cout << "The amount of interest must be a positive number. Please enter again!" << endl;
        cin.clear();
        cin.ignore('%');
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bolAnnualInterest = false;
    }
    return bolAnnualInterest;
}

//Checking that monthly payment is a positive number
bool validMonthlyPayment(double paymentAmount)
{
    bool bolMonthlyPayment(true);
    if (cin.fail() || paymentAmount <= 0)
    {
        cout << "The monthly payment must be a positive number. Please enter again!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bolMonthlyPayment = false;
    }
    return bolMonthlyPayment;
}

int main()
{
    int loanYears, currentPeriod = 0, totalPeriods, numberOfPayments;
    double annualInterest, monthlyInterestRate, loanPrinciple, paymentAmount, currentBalance;

    //Checking principle of loan
    cout << "The loan principle should be between 50,000 and 100,000" << endl;
    cout << "Please enter the principle of the loan: "; cin >> loanPrinciple; cout << endl;
    bool validPrinciple = validLoanAmount(loanPrinciple);
    while (validPrinciple != true)
    {
        cout << "Please enter the principle of the loan: "; cin >> loanPrinciple; cout << endl;
        validPrinciple = validLoanAmount(loanPrinciple);
    }
    currentBalance = loanPrinciple;

    //Checking life of loan
    cout << "Acceptable life of loans are 10, 15, 25, or 40 years." << endl;
    cout << "Please enter the life of the loan: "; cin >> loanYears; cout << endl;
    bool validYears = validLoanYears(loanYears);
    while (validYears != true)
    {
        cout << "Please enter the life of the loan: "; cin >> loanYears; cout << endl;
        validYears = validLoanYears(loanYears);
    }

    numberOfPayments = loanYears * 12;
    totalPeriods = numberOfPayments;

    //Checking interest rate is positive
    cout << "Please enter the annual interest rate: "; cin >> annualInterest; cout << endl;
    bool validLoan = validAnnualInterest(annualInterest);
    while (validLoan != true)
    {
        cout << "Please enter the annual interest rate as a decimal: "; cin >> annualInterest; cout << endl;
        validLoan = validAnnualInterest(annualInterest);
    }

    monthlyInterestRate = ((annualInterest / 12) / 100);

    cout << "Your loan principle is " << loanPrinciple << "$ with a loan life of " << loanYears << " years, with an annual interest rate of " << annualInterest << "%." << endl;
    paymentAmount = PaymentCalculator(loanPrinciple, monthlyInterestRate, numberOfPayments);
    cout << "Monthly payment due " << fixed << setprecision(2) << paymentAmount << endl << endl;
    system("pause");
    system("cls");
    LoanAmortizaeSchedule(currentPeriod, totalPeriods, paymentAmount, monthlyInterestRate, currentBalance);


}
//Function definitions

double PaymentCalculator(double loanPrinciple, double monthlyInterestRate, int numberOfPayments)
{
    double paymentAmount;
    paymentAmount = loanPrinciple * (monthlyInterestRate * (pow(1 + monthlyInterestRate, numberOfPayments)) / ((pow(1 + monthlyInterestRate, numberOfPayments)) - 1));
    return paymentAmount;
}


void LoanAmortizaeSchedule(int currentPeriod, int totalPeriods, double paymentAmount, double monthlyInterestRate, double currentBalance)
{        
    double principle, monthlyInterest;

    if (currentPeriod == totalPeriods)
    {
        return;
    }

    monthlyInterest = monthlyInterestRate * currentBalance;
    principle = paymentAmount - monthlyInterest;

    cout << "Payment" << setw(10) << "Amount" << setw(10) << "Interest" << setw(10) << "Principle" << setw(10) << "Balance" << endl;
    cout << setw(7) << currentPeriod << setw(10) << paymentAmount << setw(10) << monthlyInterest << setw(10) << principle << setw(10) << currentBalance << endl;
    LoanAmortizaeSchedule(++currentPeriod, totalPeriods, paymentAmount, monthlyInterestRate, currentBalance -= principle);

}
