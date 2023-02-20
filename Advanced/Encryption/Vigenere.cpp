#include "Vigenere.h"
#include "MyText.h"
#include <iostream>
#include <string>
#include <vector>
#include <cwctype>
using namespace std;


Vigenere::Vigenere()
{
	Vigenere::setKey("");
	Vigenere::toUpperCase("");
	Vigenere::encrypt("");
	Vigenere::decrypt("");
}

Vigenere::Vigenere(string _key)
{
	Vigenere::setKey(_key);
}

void Vigenere::setKey(string _key)
{
	key = _key;
}

string Vigenere::getKey()
{
	return key;
}

string Vigenere::toUpperCase(string upper)
{
	for (int i = 0; i < upper.length(); i++)
	{
		upper[i] = toupper(upper[i]);
	}
	key = upper;
	return key;
}
string Vigenere::encrypt(string word)
{
	string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c + key[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
		j = (j + 1) % key.length();
	}
	return output;

}
string Vigenere::decrypt(string word)
{
	string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c - key[j] + 26) % 26 + 'A';//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
		j = (j + 1) % key.length();
	}
	return output;
}
