#include <iostream> 
#include <string> 
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    int initialTime, songSeconds, songMinutes, remainingTime, remainingMinutes, remainingSeconds, cdTotal, songNumber;

    //Setting the input file and output file
    ifstream inFile;
    ofstream outFile;

    //Check file for corruption
     if (inFile.fail()) {
        cerr << "File could not open." << endl;
        exit(1);
    }

    //Opening the input file and output file
    inFile.open("songs.txt");
    outFile.open("timeRemaining.txt");

    //Song number counter
    songNumber = 1;
    while (!inFile.eof())
    {
        inFile >> initialTime;
        cdTotal = 4800;
        remainingTime = cdTotal - initialTime;
        remainingMinutes = remainingTime / 60;
        remainingSeconds = remainingTime % 60;
        songMinutes = initialTime / 60;
        initialTime = initialTime % 60;
        songSeconds = initialTime;
        outFile <<  "Song Number" << setw(12) << "Song Time" << setw(15) << "Total Time" << endl;
        outFile << songNumber << setw(14) << songMinutes << ":" << songSeconds << setw(14) << remainingMinutes << ":" << remainingSeconds << endl;
        songNumber ++;
    }
    outFile << "There is " << songMinutes << " minutes and " << songSeconds << " seconds on the disk." << endl;
    outFile << "There is " << remainingMinutes << " minutes and " << remainingSeconds << " seconds left on the disk." << endl;

    
//Tells user to check the output file
cout << "See the output file for time left on the CD." << endl;


return 0;
}
//Function definitions
