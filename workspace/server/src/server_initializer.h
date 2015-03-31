/*
 * server_initializer.h
 *
 *  Created on: Mar 23, 2015
 *      Author: majk
 */

#pragma once

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class server_initializer {
public:
	server_initializer();

	virtual ~server_initializer();

	void inicializeServer(const int);

	void startsListening();

	inline void closeSocket() {
		close(listener);
	};

private :

	int listener;

	static const char* socket_errors[];

	enum socket_errors {	// enumerations of socket errors
			ERROR_OPENING = 0,
			ERROR_BINDING = 1,
		};
public :
	/* getters method */

	inline int getSocket () const {
		return listener;
	}
};
