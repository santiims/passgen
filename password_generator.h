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

#ifndef STRING
#define STRING
#include <string>
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

	bool findPassword(std::string fileName = "passwords")
	{
		std::string identifier = "";
		std::string line;
		std::ifstream fin;
		fin.open(fileName);
		if (!fin) {
			return false;
		}
		getline(fin, line);

		while (fin.eof() == false) {
			int i;
			for (i = 0; line[i] != ' '; i++) {
				identifier += line[i];
			}
			if (identifier == this->whatIsThisPasswordFor) {
				for (++i; line[i] != '\0'; i++){
					this->password += line[i];
				}
				return true;
			}
			identifier = "";
			getline(fin, line);
		}

		fin.close();

		return false;
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
			case 2: return (char)(rand() % 97 + 122);	//[a-z]
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