//============================================================================
// Name        : client.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "client.h"

#include <vector>

using namespace std;

int main(int argc, char** argv) {


	// client -p 12705 -h majk -l olda -N -U -S
	// client -p 12705 -h majk -u 1994 -N -U -S

	client_args args;

	try {
		args.argumentsParsing(argc, argv);
	} catch (const char* e) {
		cout << "el problema: " << e << endl;
		return 1;
	}

	vector <string> output;

	try {
		client_communication_handle communicati(args.getPortNumber(), args.getHostname());

		communicati.sendArguments(args.getInquiry(), args.getFilter());

		output = communicati.getOutput();

	} catch (const char* e) {
		cout << "el problema sendera: " << e << endl;
		return 1;
	}

	for (auto it(output.begin()); it < output.end(); ++it)
		cout << *it << endl;

	return 0;
}
