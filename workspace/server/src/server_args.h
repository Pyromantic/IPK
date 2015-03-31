#pragma once

#include <cstring>
#include <stdlib.h>

class server_args {
public :
	server_args (const int, char**);

	virtual ~server_args();

private :
	int port;

	void argcCheck(const int);

	void setPort(char**);

	static const char* server_errors[];

	enum server_errors {	// enumerations of server errors
		INVALID_PORT_NUMBERS = 1024,

		FEW_ARGS = 0,
		MANY_ARGS = 1,
		error_PORT = 2,
		error_PORT_NUMBER = 3,
	};

	enum server_argc {		// enumerations of server arguments
		MIN_SERVER_ARGC = 2,
		MAX_SERVER_ARGC = 3,

		PORT_TAG = 1,
		PORT_NUMBER = 2,
	};

public :	// getters
	inline int getPortNumber() const {	// returns port number
		return port;
	};

};
