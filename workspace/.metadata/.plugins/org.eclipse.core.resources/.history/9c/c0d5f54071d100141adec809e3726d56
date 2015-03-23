/*
 * client_args.h
 *
 *  Created on: Mar 21, 2015
 *      Author: majk
 */

#pragma once

#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>

using std::string;

class client_args {
public:
	client_args();

	virtual ~client_args();

	void argumentsParsing(const int, char**);

private:
	string hostname;					// Host name
	unsigned short int port;			// Port number
	std::vector<std::string> assortment;// assortment value

	void argcCheck(const int);

	void setHostname(char**);

	void setPortNumber(char**);

	void setLogin(char**);

	void setAssortmentType(const int, char**);

	static const char* client_errors[];

	enum client_errors {	// enums of client errors
		INVALID_PORT_NUMBERS = 0,

		FEW_ARGS = 0,
		MANY_ARGS = 1,
		error_PORT_NUMBER = 2,
		error_LOGIN = 3,
		error_ASSORT_TYPE = 4,
	};

	enum client_argc {		// enums of client arguments
		MIN_CLIENT_ARGC = 4,
		MAX_CLIENT_ARGC = 8,

		FIRST_CHAR = 0,

		HOST_NAME = 1,
		PORT_NUMBER = 2,
		ASSORT_TAG = 3,
		ASSORT_VALUE = 4,
	};

	enum assortment_types {	// enum of valid assort types for client
		USER_NAME = 0,
		UID = 1,
		GID = 2,
		WHOLE_NAME = 4,
		HOME_DIR = 5,
		LOG_SHELL = 6
	};

public: // getters

	inline string getHostname() const {			// returns hostname
		return hostname;
	}

	inline int getPortNumber() const {			// returns port number
		return port;
	}

	inline int getAssortmentType() const {		// returns assortment type
		return assortment;
	}

	inline string getAssortmentValue() const {	// return assortment value
		return assortValue;
	}

};


