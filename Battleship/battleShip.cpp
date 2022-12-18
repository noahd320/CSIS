// battleShip.cpp -- This program will allow the user to play battleship until they sink all the ships!"

//Include statements 
#include <iostream> 
#include <string> 
#include <fstream>
using namespace std;

//Function prototypes 
void fire(int row, int col);
void fleetSunk();

char gameBoard[25][25];

int hitCounter = 0;
int missCounter = 0;
int row, col;

int main() 
{
  ifstream inFile;
  string line;
  int row, col, i, j;    

//Program logic
    inFile.open("battleShipBoard.txt");

    //Check file for corruption
        if (inFile.fail()) {
            cerr << "File could not open." << endl;
            exit(1);
        }
    //Gets the text file in to build out the array
    for (int i = 0; i < 25; i++)
    {
        inFile >> line;
        for (int j = 0; j < 25; j++)
        {
            gameBoard[i][j] = line[j];
        }
        
    }
    //Prompts the user to start the game
    cout << "Welcome to Battleship! There are 14 ships heading our way and we need your help!" << '\n'
    << "Join us in the fight, input the row and collumn you wish to fire upon:"; 
    
    //Since there are 41 hits possible this counter will ensure that the program will run
    while (hitCounter < 41)
    {
        cin >> row >> col;
        fire(row, col);
    }
    //Once all 41 spots have been hit, the game is over and the fleet is gone
    if (hitCounter >= 41)
    {
        fleetSunk();
    }
    //Loops through the array again and outputs all the new characters based on hits and misses
    for (int i = 0; i < 25; i++)
    {
         for (int j = 0; j < 25; j++)
        {
            cout << gameBoard[i][j];
        }
        cout << endl;
    }
   
return 0;
}
//Function definitions
void fire(int row, int col) {  
    //Coordinates are a ship, chaning the spot to a H
    if (gameBoard[row][col] == '#')
    {
        cout << "HIT" << endl;
        gameBoard[row][col] = 'H';
        hitCounter++;
        cout << "Fire again: ";
    }
    //Coordinates are at an open spot, changing the spot to a M
    else if (gameBoard[row][col == '~'])
    {
        cout << "MISS" << endl;
        gameBoard[row][col] = 'M';
        missCounter++;
        cout << "Fire again: ";
    }
    //Coordinates have been used before
    else if (gameBoard[row][col] == 'H')
    {
        cout << "HIT AGAIN" << endl;
    }    

};
//Output to the user that the game is over!
void fleetSunk() {
    cout << "The fleet was destroyed!" << endl;
    cout << "You landed " << hitCounter << " hits on the enemy!" << endl;
    cout << "You missed the enemy " << missCounter << " times." << endl;
};
