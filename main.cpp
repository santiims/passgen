#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef PASSWORD_GENERATOR_H
#include "password_generator.h"
#endif

#ifndef MATH_H
#define MATH_H
#include <math.h>
#endif

using namespace std;

//Feature request - store passwords in encrypted format
//Feature request - have passwords use non-alphanumeric characters

int main(int argc, char **argv)
{
	string whatIsThisPasswordFor;
	//Feature request - variable passwords filename
	string filename = "passwords";
	//Feature request in future - variable password length
	int passwordLength = 16;

	if (argc < 2 || argc > 2) {
		cout << "Please provide an identifier for the password";
		return 1;
	}

	whatIsThisPasswordFor = argv[1];

	PasswordGenerator* passwordGenerator = new PasswordGenerator(whatIsThisPasswordFor, passwordLength);

	if (passwordGenerator->findPassword()) {
		passwordGenerator->printToConsole();
		return 0;
	}

	passwordGenerator->generatePassword();

	passwordGenerator->printToFile();

	passwordGenerator->printToConsole();

	delete passwordGenerator;

	return 0;
}