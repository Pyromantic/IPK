#pragma once

#include <string>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <iostream>
#include <vector>

class host_handle {
public :
	host_handle();

	virtual ~host_handle();

	void inicializeHost(int);

private :

	int hostSocket;

	void acceptHost(int);

	void getArguments();

	unsigned int getArgc();

	unsigned int getBufferSize();

	std::string getArgument (unsigned int);

	inline void nCheck (int n, int ERROR_TYPE) {
		if (n < 0) {
			close(hostSocket);
			throw listener_errors[ERROR_TYPE];
		}
	}

	static const char* listener_errors[];

	enum listener_errors {	// enums of listener errors
		ACCEPT_ERROR = 0,
		READING_ERROR = 1,
		WRITING_ERROR = 2,
		TRANSMIT_ERROR = 3,
	};

};
