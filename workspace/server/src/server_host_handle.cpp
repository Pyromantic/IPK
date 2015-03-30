#include "server_host_handle.h"

host_handle::host_handle() : hostSocket(0) {
}

host_handle::~host_handle() {

}

void host_handle::handleHost (int listener) {	// Initial host

	acceptHost(listener);	// accept host and sets host socket

	vector <string> inquiry (getInquiry());	// get inquiry

	vector <char> filter (getFilter());		// get filter

	server_users_parser parser (inquiry, filter);

	// TODO	sending parsed user data back to client

	close (hostSocket);		// close host socket
}

void host_handle::acceptHost (int listener) {

	struct sockaddr_in cli_addr;

	unsigned int clilen = sizeof(cli_addr);

	hostSocket = accept(listener, (struct sockaddr *) (&cli_addr), &clilen);

	nCheck (hostSocket, ACCEPT_ERROR);
};

vector <string> host_handle::getInquiry () {			// gets arguments

	unsigned int argc (getArgc());	// handshake - receiving argc

	vector <string> inquiry (argc);

	for (; argc > 0; --argc) {				// iterate until all arguments are loaded

		unsigned int bufferSize (getBufferSize());	// handshake - receiving bufferSize

		string message (getArgument(bufferSize));		// actual message receiver

		inquiry.push_back(message);
	};

	return inquiry;
}

unsigned int host_handle::getBufferSize () {	// handshake - receiving bufferSize
	unsigned int bufferSize;

	int n = read(hostSocket, &bufferSize, sizeof(bufferSize));

	nCheck(n, READING_ERROR);

	return bufferSize;
}

string host_handle::getArgument (unsigned int bufferSize) {				// actual message receiver

	vector <char> buffer (bufferSize);

	int n = read(hostSocket, &buffer[0], buffer.size());

	nCheck (n, READING_ERROR);

	string str (buffer.begin(), buffer.end());

	return str;
};

vector <char> host_handle::getFilter () {

	unsigned int bufferSize (getArgc());

	vector <char> buffer;

	if (bufferSize)
		buffer.resize(bufferSize);
	else
		return buffer;

	int n = read (hostSocket, &buffer[0], bufferSize);

	nCheck(n, READING_ERROR);

	return buffer;
};

unsigned int host_handle::getArgc () {			// handshake - receiving argc
	unsigned int argc(0);

	int n = read(hostSocket, &argc, sizeof(argc));

	nCheck(n, READING_ERROR);

	return argc;
};

const char* host_handle::listener_errors[] {
	"ERROR on accept",
	"ERROR reading from socket",
	"ERROR writing to socket",
	"Unknown transmit error",
};


