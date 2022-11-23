#include <iostream> 
#include <string> 
#include <cmath>
#include <fstream>
using namespace std;
//Global declarations: Constants and type definitions only -- no variables
//Function prototypes 

double gradeCheck(double grade, double total, ifstream&, ofstream&);
void nameCheck(string name, ifstream& studentGrades, ofstream& calculatedGrades);


int main()
{
    double grade, total, gradePercentage;
    string names;
    ifstream studentGrades;
    ofstream calculatedGrades;

    //Opening the input and output files
    studentGrades.open("studentGrades.txt");
    calculatedGrades.open("calculatedGrades.txt");

    
    //Check file for corruption
    if (studentGrades.fail()) {
        cerr << "File could not open." << endl;
        exit(1);
    }
    if (calculatedGrades.fail()) {
        cerr << "File could not open." << endl;
        exit(1);
    }
    
    //This ensures that the code will go line by line until there are no more
    while (!studentGrades.eof())
    {
        string names;
        double grade, total, gradePercentage;
        //Take in from studentGrades.txt and setting the variables that will be called by the functions
        studentGrades >> names >> grade >> total;

        nameCheck(names, studentGrades, calculatedGrades);
        gradeCheck(grade, total, studentGrades, calculatedGrades);

    }

//In cout statement below SUBSTITUTE  your name and lab number
    cout << "Noah Duran -- Lab 4" << endl << endl;
    cout << "See the output file for table" << endl;

//Variable declarations
//Program logic
//Closing program statements 
//--Making comment for pause does not run on MacOS-- system("pause");
return 0;
}
//Function definitions
double gradeCheck(double grade, double total, ifstream& studentGrades, ofstream& calculatedGrades) {

    double gradePercentage;
    double gradeDecimal;

    //The percentage will round up and set it to a percentage value, decimal keeps it as decimal
    gradePercentage = ceil((grade / total) * 100);
    gradeDecimal = grade / total;

    //Finding if the grade passes or not
    //Setprecision ensures that you will only get two digits for percentage and 5 decimal value for the decimal portion
    if (gradePercentage >= 90)
        {
            calculatedGrades << fixed << setprecision(0) << gradePercentage << "% " << fixed << setprecision(5) << gradeDecimal << " " << "Excellent" << '\n';
        }
    else if (gradePercentage >= 80)
        {
            calculatedGrades << fixed << setprecision(0) << gradePercentage << "% " << fixed << setprecision(5) << gradeDecimal << " " << "Well Done" << '\n';
        }
    else if (gradePercentage >= 70)
        {
            calculatedGrades << fixed << setprecision(0) << gradePercentage << "% " << fixed << setprecision(5) << gradeDecimal << " " << "Good" << '\n';
        }
    else if (gradePercentage >= 60)
        {
            calculatedGrades << fixed << setprecision(0) << gradePercentage << "% " << fixed << setprecision(5) << gradeDecimal << " " << "Need Improvement" << '\n';
        }
    else {
            calculatedGrades << fixed << setprecision(0) << gradePercentage << "% " << fixed << setprecision(5) << gradeDecimal << " " << "Fail" << '\n';
        }

    return gradePercentage;
    return gradeDecimal;

    }

void nameCheck(string name, ifstream& studentGrades, ofstream& calculatedGrades) {

    //Takes in the name and sets it to studentName, then out puts it to the file with a space
    string studentName;
    studentName = name;

    calculatedGrades << studentName << " ";
}
