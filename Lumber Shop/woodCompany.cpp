//woodCompany -- This will intake the demensions of the wood that a customer wants and output thier price

#include <iostream> 
#include <string> 
using namespace std;
//Global declarations: Constants and type definitions only -- no variables
//Function prototypes 

double pinePrice(double boardWidth, double boardHeight, double boardLength, double woodQuantity);
double firPrice(double boardWidth, double boardHeight, double boardLength, double woodQuantity);
double cedarPrice(double boardWidth, double boardHeight, double boardLength, double woodQuantity);
double maplePrice(double boardWidth, double boardHeight, double boardLength, double woodQuantity);
double oakPrice(double boardWidth, double boardHeight, double boardLength, double woodQuantity);


int main()
{
//In cout statement below SUBSTITUTE  your name and lab number
cout << "Noah Duran  -- Lab Number 5" << endl << endl;
//Variable declarations
double boardWidth, boardHeight, boardLength, woodQuantity, totalPrice;
char woodType;

totalPrice = 0;


//Prompting customer for wood type, wood demensions, and number of boards  
cout << "What kind of wood would you like?" << '\n' << "Please enter P for Pine, F for Fir, C for Cedar, M for Maple, or O for Oak" << 
'\n' << "Otherwise press T for the total: ";
cin >> woodType;
    //While loop will check if the user is inputting correct characters for the wood. If not the program will terminate.
    while (woodType != 'T' && woodType != 't')
    {
        if (woodType == 'P' || woodType == 'p')
        {
            cout << "Enter the board size as width height length: " << '\n';
            cin >> boardWidth >> boardHeight >> boardLength;
            cout << "How many boards do you need? " << '\n';
            cin >> woodQuantity;
            totalPrice += pinePrice(boardWidth, boardHeight, boardLength, woodQuantity);
        }
        else if (woodType == 'F' || woodType == 'f')
        {
            cout << "Enter the board size as width height length: " << '\n';
            cin >> boardWidth >> boardHeight >> boardLength;
            cout << "How many boards do you need? " << '\n';
            cin >> woodQuantity;
            totalPrice += firPrice(boardWidth, boardHeight, boardLength, woodQuantity);
        }
        else if (woodType == 'C' || woodType == 'c')
        {
            cout << "Enter the board size as width height length: " << '\n';
            cin >> boardWidth >> boardHeight >> boardLength;
            cout << "How many boards do you need? " << '\n';
            cin >> woodQuantity;
            totalPrice += cedarPrice(boardWidth, boardHeight, boardLength, woodQuantity);
        }
        else if (woodType == 'M' || woodType == 'm')
        {
            cout << "Enter the board size as width height length: " << '\n';
            cin >> boardWidth >> boardHeight >> boardLength;
            cout << "How many boards do you need? " << '\n';
            cin >> woodQuantity;
            totalPrice += maplePrice(boardWidth, boardHeight, boardLength, woodQuantity);
        }
        else if (woodType == 'O' || woodType == 'o')
        {
            cout << "Enter the board size as width height length: " << '\n';
            cin >> boardWidth >> boardHeight >> boardLength;
            cout << "How many boards do you need? " << '\n';
            cin >> woodQuantity;
            totalPrice += oakPrice(boardWidth, boardHeight, boardLength, woodQuantity);
        }
        else if (woodType != 'T' && woodType != 't')
        {
        cout << "Invalid wood type. Please try again." << endl;
        return 0;
        }
        //Starting the loop over incase the user wants to order more wood or get the total.
        cout << "Do you want to add to your order?" << '\n' << "If so enter P for Pine, F for Fir, C for Cedar, M for Maple, or O for Oak" << 
        '\n' << "Otherwise press T for the total: ";
        cin >> woodType;

        }

//This will output the total then end the program
cout << "Your total price is: " << totalPrice << endl;
    
return 0;
}
//Function definitions
double pinePrice(double boardWidth, double boardHeight, double boardLength, double woodQuantity) {
    double boardFeet, boardPrice, pinePrice;
    pinePrice = 0.89;
    boardFeet = (boardWidth * boardHeight * boardLength) / 12;
    boardPrice = (boardFeet * pinePrice) * woodQuantity;
    cout << woodQuantity << " " << boardWidth << 'x' << boardHeight << 'x' << boardLength << " Pine costs: " << boardPrice << endl;
    return boardPrice;
}
double firPrice(double boardWidth, double boardHeight, double boardLength, double woodQuantity) {
    double boardFeet, boardPrice, firPrice;
    firPrice = 1.09;
    boardFeet = (boardWidth * boardHeight * boardLength) / 12;
    boardPrice = (boardFeet * firPrice) * woodQuantity;
    cout << woodQuantity << " " << boardWidth << 'x' << boardHeight << 'x' << boardLength << " Fir costs: " << boardPrice << endl;
    return boardPrice;
}
double cedarPrice(double boardWidth, double boardHeight, double boardLength, double woodQuantity) {
    double boardFeet, boardPrice, cedarPrice;
    cedarPrice = 2.26;
    boardFeet = (boardWidth * boardHeight * boardLength) / 12;
    boardPrice = (boardFeet * cedarPrice) * woodQuantity;
    cout << woodQuantity << " " << boardWidth << 'x' << boardHeight << 'x' << boardLength << " Cedar costs: " << boardPrice << endl;
    return boardPrice;
}
double maplePrice(double boardWidth, double boardHeight, double boardLength, double woodQuantity) {
    double boardFeet, boardPrice, maplePrice;
    maplePrice = 4.50;
    boardFeet = (boardWidth * boardHeight * boardLength) / 12;
    boardPrice = (boardFeet * maplePrice) * woodQuantity;
    cout << woodQuantity << " " << boardWidth << 'x' << boardHeight << 'x' << boardLength << " Maple costs: " << boardPrice << endl;
    return boardPrice;
}
double oakPrice(double boardWidth, double boardHeight, double boardLength, double woodQuantity) {
    double boardFeet, boardPrice, oakPrice;
    oakPrice = 3.10;
    boardFeet = (boardWidth * boardHeight * boardLength) / 12;
    boardPrice = (boardFeet * oakPrice) * woodQuantity;
    cout << woodQuantity << " " << boardWidth << 'x' << boardHeight << 'x' << boardLength << " Oak costs: " << boardPrice << endl;
    return boardPrice;
}
