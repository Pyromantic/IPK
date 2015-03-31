#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "server_users_parser.h"
#include "basic_communication.h"

using namespace std;

class host_handle: protected basic_communication {
public :
	host_handle(int);

	virtual ~host_handle();

private :
	/*  methods | constants | enumerations */

	void handleHost(int);	// starts whole process

	void acceptHost(int);		// accepts host communication request

	/* receiving methods */

	vector <char> getFilter();	// receive filter

	/* constants */

	static const char* receiver_errors[];

	/* enumerations */

	enum receiver_errors {	// enumerations of receiver errors
		ACCEPT_ERROR = 0,
	};

};
