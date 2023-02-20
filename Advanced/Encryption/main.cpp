
#include "MyText.h"
#include "Vigenere.h"
#include <iostream>
#include <istream>
#include <string>
#include <fstream>

MyText::MyText()
{

}

MyText::MyText(std::string k)
{
	v.setKey(k);
}

/*
The encryptWord and decryptWord functions are nearly the same, just with minor changes to call on the proper Vigenere algorithm
*/

void MyText::encryptWord(char *token)
{
	std::string t = token;
	std::string eword = "";
	eword = v.encrypt(t);
	words.push_back(eword);
}

void MyText::decryptWord(char *token)
{
	std::string t = token;
	std::string dword = "";
	dword = v.decrypt(t);
	words.push_back(dword);
}

int MyText::getWordsCount()
{
	return words.size();
}


void MyText::FileCreate(std::string filename)
{
	//Outputting the list of encrypted/decrypted words to another file specified by the user in main.
	std::ofstream outFile;
	outFile.open(filename);
	//The next line will copy all elements from the vector word, beginning to end, and put the iterator of a space between each element
	std::copy(words.begin(), words.end(), std::ostream_iterator<int>(std::cout, " "));
	outFile.close();
}

void MyText::displayText()
{
	//output all words of vector words by looping through it for the length of the vectors size.
	for (size_t i = 0; i < words.size(); i++)
	{
		std::cout << words[i] << std::endl;
	}
}
