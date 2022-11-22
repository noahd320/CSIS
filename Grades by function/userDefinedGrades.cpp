// userDefinedGrades.cpp -- This file will output a students grade for an assignment.
//CSIS 111-<D02> 
//Include statements 
#include <iostream> 
#include <string> 
#include <cmath>
#include <fstream>
using namespace std;
//Global declarations: Constants and type definitions only -- no variables
//Function prototypes 


double gradeCheck(double grade, double total);
void nameCheck(string studentName);


int main()
{
    ifstream studentGrades;
    ofstream calculatedGrades;

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
    
    while (!studentGrades.eof())
    {
        string names;
        double grade, total, gradePercentage;
        studentGrades >> names >> grade >> total;

        gradeCheck(grade, total);
    }



//In cout statement below SUBSTITUTE  your name and lab number
    cout << "Noah Duran -- Lab 4" << endl << endl;


//Variable declarations
//Program logic
//Closing program statements 
//--Making comment for pause does not run on MacOS-- system("pause");
return 0;
}
//Function definitions
double gradeCheck(double grade, double total) {
    ifstream studentGrades;
    studentGrades.open("studentGrades.txt");
    ofstream calculatedGrades;
    calculatedGrades.open("calculatedGrades.txt");

    string names;
    double gradePercentage;
    double gradeDecimal;

    while (studentGrades >> names >> grade >> total)
    {
        gradePercentage = ceil((grade / total) * 100);
        gradeDecimal = grade / total;
        cout << names << '\n';
        cout << gradePercentage << '\n';
        cout << setprecision(5) << gradeDecimal << '\n';
    }

    return gradePercentage;
    return gradeDecimal;


    /*
     if (gradePercentage >= 90)
        {
            calculatedGrades << names << " " << "Excellent" << '\n';
        }
    else if (gradePercentage >= 80)
        {
            calculatedGrades << names << " " << "Well Done" << '\n';
        }
    else if (gradePercentage >= 70)
        {
            calculatedGrades << names << " " << "Good" << '\n';
        }
    else if (gradePercentage >= 60)
        {
            calculatedGrades << names << " " << "Need Improvement" << '\n';
        }
    else {
            calculatedGrades << names << " " << "Fail" << '\n';
        }
        */
    

    }

void nameCheck(ifstream& studentName) {
    
}
