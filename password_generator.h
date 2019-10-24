#ifndef TIME_H
#define TIME_H
#include <time.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

class PasswordGenerator
{

private:
	std::string whatIsThisPasswordFor;
	std::string password;
	int passwordLength;

public:
	PasswordGenerator(std::string whatIsThisPasswordFor, int passwordLength)
	{
		this->whatIsThisPasswordFor = whatIsThisPasswordFor;
		this->password = "";
		this->passwordLength = passwordLength;
	}

	void generatePassword()
	{
		srand(time(0));

		for (int i = 0; i < this->passwordLength; i++) {
			this->password += generateSymbol(rand() % 3);
		}
	}

	char generateSymbol(int symbolType)
	{
		switch (symbolType) {
			case 0: return (char)(rand() % 10 + 48); 	//[0-9]
			case 1: return (char)(rand() % 26 + 65);	//[A-Z]
			case 2: return (char)(rand() % 26 + 97);	//[a-z]
		}
	}

	void printToFile(std::string fileName = "passwords")
	{
		std::ofstream fout;
		fout.open(fileName, std::ios::app);
		fout << this->whatIsThisPasswordFor;
		fout << " ";
		fout << this->password;
		fout << "\n";
		fout.close();
	}

	void printToConsole()
	{
		std::cout << this->password;
	}
};

#endif