#pragma once
#include <iostream>

class Vigenere
{
public:
	Vigenere();
	Vigenere(std::string _key);

	void setKey(std::string);
	std::string getKey();

	std::string toUpperCase(std::string);

	std::string encrypt(std::string);
	std::string decrypt(std::string);



private:
	std::string key;

};

