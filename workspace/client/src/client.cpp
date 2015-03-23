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
/*	cout << "hostname: " << args.getHostname() << endl;
	cout << "port: " << args.getPortNumber() << endl;
	cout << "assortment: " << args.getAssortmentType() << " value : " <<
			args.getAssortmentValue() << endl;
*/

	client_sender sender(args);

	try {
		sender.beginCommunication();
		sender.sendStuff();
	} catch (const char* e) {
		cout << "el problema sendera: " << e << endl;
		return 1;
	}

	return 0;
}
