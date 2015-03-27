#include "server_host_handle.h"

using namespace std;

host_handle::host_handle() : hostSocket(0) {
}

host_handle::~host_handle() {

}

void host_handle::handleHost (int listener) {	// Initial host

	acceptHost(listener);	// accept host and sets host socket

	vector <string> arguments (move(getArguments()));	// get arguments

	// TODO	arguments parsing notifying selection listeners notifying selection listeners

	close (hostSocket);		// close host socket
}

void host_handle::acceptHost (int listener) {

	struct sockaddr_in cli_addr;

	unsigned int clilen = sizeof(cli_addr);

	hostSocket = accept(listener, (struct sockaddr *) (&cli_addr), &clilen);

	nCheck (hostSocket, ACCEPT_ERROR);
};

vector <string> host_handle::getArguments () {			// gets arguments

	unsigned int argc (move(getArgc()));	// handshake - receiving argc

	vector <string> arguments (argc);

	cout << argc << endl;

	for (; argc > 0; --argc) {						// iterate until all arguments are loaded

		unsigned int bufferSize (move(getBufferSize()));	// handshake - receiving bufferSize

		cout << bufferSize << endl;

		string message (move(getArgument(bufferSize)));	// actual message receiver

		cout << message << endl;

		arguments.push_back(message);
	}

	return arguments;
}

unsigned int host_handle::getArgc () {			// handshake - receiving argc
	unsigned int argc;

	int n = read(hostSocket, &argc, sizeof(argc));

	nCheck(n, READING_ERROR);

	return argc;
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
}

const char* host_handle::listener_errors[] {
	"ERROR on accept",
	"ERROR reading from socket",
	"ERROR writing to socket",
	"Unknown transmit error",
};
