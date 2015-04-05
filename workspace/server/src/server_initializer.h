/*
 * server_initializer.h
 *
 *  Created on: Mar 23, 2015
 *      Author: majk
 */

#pragma once

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <csignal>

#include "server_host_handle.h"

class server_initializer {
public:
	server_initializer();

	virtual ~server_initializer();

	void inicializeServer(const int);

	void startsListening();

private :
	/* server listener socket */

	static int listener;

	/*signal handler */

	static void signalHandler(int);

	/* constants */

	static const char* socket_errors[];

	/* enumerations */

	enum socket_errors {	// enumerations of socket errors
			ERROR_OPENING = 0,
			ERROR_LISTEN = 1,
			ERROR_BINDING = 2,
			ERROR_ACCEPT = 3,
			ERROR_FORK = 4,
		};
public :
	/* getters method */

	inline int getSocket () const {
		return listener;
	}
};
