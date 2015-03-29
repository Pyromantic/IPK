/*
 * server_users_parser.h
 *
 *  Created on: Mar 27, 2015
 *      Author: majk
 */

#pragma once

#include <vector>
#include <string>
#include <fstream>

#include <iostream>

using namespace std;

class server_users_parser {
public:
	server_users_parser(vector <string>);

	virtual ~server_users_parser();

private :	// variables

	ifstream file;				// passwd file

	vector <string> inquiry;	// client's inquiry

	vector <string> output;		// output

private :	//  methods | constants | enumerations


	void applyInquiry();

	void parseLine (string);

	/* file operations methods */

	void parseFile();			// parse through lines of file

	void openPasswd();			// opens passwd file

	inline void closePasswd();	// closes passwd file

	/* initialization method */

	void initialize();			// initialize output vector

	/* enumerations */

	enum string_consts {
		FIRST_CHAR = 0,
		SWITCHER = 1,
	};

	/* constants */

	static const char* defaultLoginOutput;	// default output value

	static const char* path2passwd;		// path to passwd file

public : // getters functions

	vector <string> getOutput () const {	// returns output
		return output;
	};
};
