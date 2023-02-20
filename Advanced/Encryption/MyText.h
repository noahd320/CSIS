#pragma once
#include <iostream>
#include <vector>
#include "Vigenere.h"

class MyText
{
public:
	MyText();
	MyText(std::string k);

	void encryptWord(char* token);
	void decryptWord(char* token);

	int getWordsCount();

	void FileCreate(std::string fileName);

	void displayText();



private:
	std::vector<std::string> words;
	Vigenere v;

};
