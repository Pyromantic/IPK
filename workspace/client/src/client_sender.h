/*
 * client_sender.h
 *
 *  Created on: Mar 21, 2015
 *      Author: majk
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <string>
#include <utility>

#include <iostream>

#include <vector>
							// bunch of libraries
#include "client_args.h"

class client_sender {
public :
	client_sender();

	virtual ~client_sender();

	void sendArguments(client_args);

private :

	void beginCommunication();

	void sendArgc(const unsigned int);

	void sendArgument(string);

	int communicati;

	inline void nCheck (int n, int ERROR_TYPE) {
		if (n < 0) {
			close(communicati);
			throw sender_errors[ERROR_TYPE];
		}
	}

	client_args args;

	static const char* sender_errors[];

	enum sender_errors {	// enums of sebder errors
		OPENING_ERROR = 0,
		NOHOST_ERROR = 1,
		CONNECT_ERROR = 2,
		WRITE_ERROR = 3,
		READ_ERROR = 4,
		TRANSMIT_ERROR = 5,
	};

};
