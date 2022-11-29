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

//Variable declarations
double boardWidth, boardHeight, boardLength, woodQuantity, totalPrice, boardPrice;
char woodType;
  
  totalPrice = 0;

//Prompting customer for wood type, wood demensions, and number of boards
cout << "What type of wood would you like?" << '\n' << "Enter P for Pine, F for Fir, C for Cedar, M for Maple, or O for Oak: ";
cin >> woodType;
cout << "Enter the board size as width height length: " << '\n';
cin >> boardWidth >> boardHeight >> boardLength;
cout << "How many boards do you need? " << '\n';
cin >> woodQuantity;

    if (woodType == 'P' || woodType == 'p')
    {
        pinePrice(boardWidth, boardHeight, boardLength, woodQuantity); 
        totalPrice += boardPrice;
        cout << totalPrice << '\n';
    }
    else if (woodType == 'F' || woodType == 'f')
    {
        firPrice(boardWidth, boardHeight, boardLength, woodQuantity);
    }
    else if (woodType == 'C' || woodType == 'c')
    {
        cedarPrice(boardWidth, boardHeight, boardLength, woodQuantity);
    }
    else if (woodType == 'M' || woodType == 'm')
    {
        maplePrice(boardWidth, boardHeight, boardLength, woodQuantity);
    }
    else if (woodType == 'O' || woodType == 'o')
    {
        oakPrice(boardWidth, boardHeight, boardLength, woodQuantity);
    }
    else
    cout << "Invalid wood type." << endl;

    
//See if more wood is needed or total is needed    
/* Trying to figure this out, on hold. Needs to ask customer if they want more wood or if they want the total.
cout << "Do you want to add to your order?" << '\n' << "If so enter P for Pine, F for Fir, C for Cedar, M for Maple, or O for Oak" << 
'\n' << "Otherwise press T for the total: ";
cin >> woodType;
*/

//Program logic
//Closing program statements 
//system("pause");
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
