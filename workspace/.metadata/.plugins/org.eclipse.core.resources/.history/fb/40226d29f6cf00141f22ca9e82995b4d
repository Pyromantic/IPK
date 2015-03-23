#pragma once

#include <string>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>


class socket_binder {
public :
	socket_binder();

	virtual ~socket_binder();

	int binder(const unsigned short int);

private :
	static const char* socket_errors[];

	enum socket_errors {	// enums of socket errors
			ERROR_OPENING = 0,
			ERROR_BINDING = 1,
		};

};
