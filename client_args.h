#pragma once
#include "arguments.h"
#include <map>
#include <string>
#include <iostream>
class client_args : protected arguments {
private:
	std::string hostname;	// Hostname
	int port;				// Port number
	std::string login;		// login
	int assortment;			// assortment types
	std::string value;		// assortment value

public:
	void argumentsParsing(const int, char**);

private:
	inline void argcCheck(const int argc) final;	// overridden inline method, final state

	inline void setHostname(char**);

	inline void setPortNumber(char**);

	inline void setLogin(char**);

	inline void setAssortmentType(char**);

	static const char *client_errors[];
		
	enum client_errors {
		error_HOST = 0,
		error_PORT = 1,
		error_PORT_NUMBER = 2,
		error_LOGIN = 3,
	};

	enum client_argc {
		MIN_CLIENT_ARGC = 4,
		MAX_CLIENT_ARGC = 9,

		HOST_TAG = 1,
		HOST_NAME = 2,
		PORT_TAG = 3,
		PORT_NUMBER = 4,
		LOGIN_TAG = 5,
		LOGIN_NAME = 6,
	};

	enum assortment_types {

	};

public: // getters

	inline std::string getHostname() const {	// returns hostname
		return hostname;
	}

	inline int getPortNumber() const {			// returns port number
		return port;
	}

	inline std::string getLogin() const {		// returns login
		return login;
	}

};

