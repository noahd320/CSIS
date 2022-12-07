//planetWeightCheck.cpp - This program is going to take input from the user and output what thier weight would be on different planents.
//Include statements 
#include <iostream> 
#include <string> 
using namespace std;
//Global declarations: Constants and type definitions only -- no variables
//Function prototypes 
void getUserInput();
double convertIntputToPlanetType(double userWeight, string planetChoice);
void outputWeight(double planetUserWeight);

int main()
{
    string planetChoice;
    double userWeight, planetMultiple, planetUserWeight;


getUserInput();
convertIntputToPlanetType(userWeight, planetChoice);

//Variable declarations


//Program logic
//Closing program statements 
//system("pause");
return 0;
}
//Function definitions
void getUserInput() {
    double userWeight;
    string planetChoice;

    cout << "This program will take your current weight and calculate how much you would weigh on a different planent" << '\n';
    cout << "Enter your current weight: ";
    cin >> userWeight;
    cout << "What planent do you want to convert to? Please choose Mercury, Venus, Earth, Moon, Mars, Jupiter, Saturn, Uranus, Neptune, or Pluto: ";
    cin >> planetChoice;

}
double convertIntputToPlanetType(double userWeight, string planetChoice){
    //    
}

void outputWeight(double planetUserWeight){
    double userWeight;

    enum planetType {Mercury, Venus, Earth, Moon, Mars, Jupiter, Saturn, Uranus, Neptune, Pluto};

    switch ('planetType')
    {
    case Mercury:
        
        cout << "Your weight on Mercury would be " << planetUserWeight << "." << endl;
        break;

    case Venus:
        planetUserWeight = userWeight * 0.8975;
        cout << "Your weight on Venus would be " << planetUserWeight << "." << endl;
        break;

    case Earth:
        planetUserWeight = userWeight * 1;
        cout << "Your weight on Earth would be " << planetUserWeight << "." << endl;
        break;

    case Moon:
        planetUserWeight = userWeight * 0.166;
        cout << "Your weight on the Moon would be " << planetUserWeight << "." << endl;
        break;

    case Mars:
        planetUserWeight = userWeight * 0.3507;
        cout << "Your weight on Mars would be " << planetUserWeight << "." << endl;
        break;

    case Jupiter:
        planetUserWeight = userWeight * 2.5374;
        cout << "Your weight on Jupiter would be " << planetUserWeight << "." << endl;
        break;

    case Saturn:
        planetUserWeight = userWeight * 1.0677;
        cout << "Your weight on Saturn would be " << planetUserWeight << "." << endl;
        break;

    case Uranus:
        planetUserWeight = userWeight * 0.8947;
        cout << "Your weight on Uranus would be " << planetUserWeight << "." << endl;
        break;

    case Neptune:
        planetUserWeight = userWeight * 1.1794;
        cout << "Your weight on Neptune would be " << planetUserWeight << "." << endl;
        break;

    case Pluto:
        planetUserWeight = userWeight * 0.0899;
        cout << "Your weight on Pluto would be " << planetUserWeight << "." << endl;
        break;

    default:
        cout << "Invalid planet selection. Please input the planet desired starting with a capitalized letter.";
        break;
}
} 
