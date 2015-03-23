//============================================================================
// Name        : client.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "client.h"

using namespace std;

int main(int argc, char** argv) {

	client_args args;

	try {
		args.argumentsParsing(argc, argv);
	} catch (const char* e) {
		cout << "el problema: " << e << endl;
		return 1;
	}
	client_sender sender;

	try {
		sender.sendArguments(args);
	} catch (const char* e) {
		cout << "el problema sendera: " << e << endl;
		return 1;
	}

	return 0;
}
