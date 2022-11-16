// studentGradeCalculator.cpp -- This file will output a students grade for an assignment.

/*Siting code -- Code is modified from but inspired by the following:
*    Title: C++ Tutorial 29 - Reading and Writing to Files - fstream
*    Author: programminghelporg
*    Code version: Version 1
*    Availability: From YouTube channel programminghelporg at https://www.youtube.com/watch?v=Iho2EdJgusQ
*/

#include <iostream> 
#include <string> 
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
    double grade, total, finalGrade;
    ifstream gradeFile;
    gradeFile.open("grades.txt");
    gradeFile >> grade >> total;
    //Check file for corruption
    if (gradeFile.fail()) {
        cerr << "File could not open." << endl;
        exit(1);
    }

    cout << grade;
    cout << total;
    //Calculating the grade based on score over total points
    finalGrade = (grade / total) * 100;
    cout << "The final grade is, " << setprecision(5) << fixed << finalGrade << endl;

    //Checking the final grade
    if (finalGrade >= 90){
        cout << "Excellant!" << '\n';
    }
    else if (finalGrade >= 80){
        cout << "Well done!" << '\n';
    }
    else if (finalGrade >= 70){
        cout << "Your grade is good." << '\n';
    }
    else if (finalGrade >= 60){
        cout << "Your grade needs improvement." << '\n';
    }
    else{
        cout << "Fail." << '\n';
    }
}
