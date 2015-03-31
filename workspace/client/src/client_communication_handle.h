/*
 * client_sender.h
 *
 *  Created on: Mar 21, 2015
 *      Author: majk
 */

#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "basic_communication.h"

using namespace std;

class client_communication_handle: protected basic_communication {
public :
	client_communication_handle(unsigned int port, string hostname);

	virtual ~client_communication_handle();

	void sendArguments(vector <string>, vector <char>);

private :
	/* variables */

	vector <string> output;

	/*  methods | constants | enumerations */

	void beginCommunication (unsigned int, string);	// establish communicating socket

	/* sending methods */

	void sendFilter (vector <char>);

	/* constants */

	static const char* sender_errors[];

	/* enumerations */

	enum sender_errors {	// enumerations of server errors
		OPENING_ERROR = 0,
		NOHOST_ERROR = 1,
		CONNECT_ERROR = 2,
	};

public :
	/* getter method */
	inline vector <string> getOutput () const {
		return output;
	};
};
