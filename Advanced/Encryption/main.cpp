
#include <iostream>
#include "Vigenere.h"
#include "MyText.h"
#include <fstream>
#include <istream>
#include <string>
#include <cstring>
using namespace std;


int main()
{
    string userKey, encryptionFile, decryptionFile;
    int selection = 0;
    char message[1000];
    char seperators[] = " ,.-";
    char *token = NULL;
    char *next_token = NULL;

    ifstream inFile;
    MyText userCrypt;

	cout << endl << "Noah Duran -- Lab 5 - Pointers" << endl << endl;
	cout << "This program is going to encrypt and decrypt a file based on the key that you provide." << endl;
	system("pause");

    //Since the Vigenere cypher is uses an assymetric key then the word here must be the some on both encryption and decryption.
	cout << "Please enter the word you want to be the encryption key: ";
	cin >> userKey;
	
    //Main menu will display prompting the user to enter in what they would like to do.
    //This while loop ensures that the prompt will show up as long as the user does not select the number 3
    while (selection != 3)
    {
        cout << "Main Menu" << endl << endl;
        cout << "1 - Encrypt File" << endl;
        cout << "2 - Decrypt File" << endl;
        cout << "3 - Quit" << endl << endl;
        cout << "Selection: ";
        cin >> selection;

        switch (selection)
        {
            case 1:
            {
                MyText userCrypt(userKey);
                cout << "Enter the file path for the file to be encrypted: ";
                getline(cin, encryptionFile);
                inFile.open(encryptionFile);
                inFile.getline(message, 1000);
                //strtok_s function used here to go through the array message and find all values of the words so that they can be encrypted.
                token = strtok_s(message, seperators, &next_token);
                while (token != NULL)
                {
                    //send the token to encryptWord function for alterations.
                    userCrypt.encryptWord(token);
                    token = strtok_s(NULL, seperators, &next_token);
                }
                cout << "A new file will be created that contains the encrypted message." << endl;
                cout << "Enter the name of the new file: ";
                getline(cin, encryptionFile);
                userCrypt.FileCreate(encryptionFile);
                cout << endl; //One line of seperation between prompts for readability
                cout << "The new file contains the following encrypted message." << endl;
                userCrypt.displayText();
                cout << endl;
                cout << "The message contatins " << userCrypt.getWordsCount() << " words." << endl << endl;
                inFile.close();
                break;
            }
            case 2:
            {
                MyText userCrypt(userKey);
                cout << "Enter the file path for the file to be decrypted: ";
                getline(cin, decryptionFile);
                inFile.open(decryptionFile);
                cout << decryptionFile << endl;
                inFile.getline(message, 1000);
                token = strtok_s(message, seperators, &next_token);
                while (token != NULL)
                {
                    //send the token to decryptWord function so the message can be read again.
                    userCrypt.decryptWord(token);
                    token = strtok_s(NULL, seperators, &next_token);
                }
                cout << "A new file will be created that contains the decrypted message." << endl;
                cout << "Enter the name of the new file: ";
                getline(cin, decryptionFile);
                userCrypt.FileCreate(decryptionFile);
                cout << endl; //One line of seperation between prompts for readability
                cout << "The new file contains the following decrypted message." << endl;
                userCrypt.displayText();
                cout << endl;
                cout << "The message contatins " << userCrypt.getWordsCount() << " words." << endl << endl;
                inFile.close();
                break;
            }
            case 3:
                //Needs to end the program
                return 0;
                break;

            default:
                break;
            }
    }
    return 0;
}
