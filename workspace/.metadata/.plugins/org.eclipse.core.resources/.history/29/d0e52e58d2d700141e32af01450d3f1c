#pragma once

#include <unistd.h>
#include <vector>
#include <string>

using namespace std;

class basic_communication {
public :
	basic_communication();

	virtual ~basic_communication();

protected :

	/* variables */

	int hostSocket;		// host socket

	/*  methods | constants | enumerations */

	/* receiving methods */

	vector <string> receiveVector ();

	string receiveString (unsigned int);	// receive single argument

	unsigned int receiveArgc();				// receive buffer size for argument from client

	/* sender methods */

	void sendVector (vector<string>);

	void sendString (string);

	void sendArgc(const unsigned int);

	/* check method */

	inline void nCheck (int n, int ERROR_TYPE) {
		if (n < 0) {
			close(hostSocket);
			throw communication_errors[ERROR_TYPE];
		}
	};

	/* constants */

	static const char* communication_errors[];

	/* enumerations */

	enum communication_errors {	// enumerations of listener errors
		READ_ERROR = 0,
		WRITE_ERROR = 1,
	};

};
