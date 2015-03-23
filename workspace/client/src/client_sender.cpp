/*
 * client_sender.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: majk
 */

#include "client_sender.h"

using namespace std;

client_sender::client_sender () : communicati(0) {
}

client_sender::~client_sender() {

}

void client_sender::sendArguments (client_args arguments) {	// sends server arguments
	args = move(arguments);		// arguments initialization

	beginCommunication();								// establish communicating socket

	vector <string> argsVector (args.getAssortment());	// vector of arguments

	unsigned int argc (argsVector.size());				// number of arguments

	sendArgc (argc);									// sends number of arguments

	for (vector <string>::iterator it (argsVector.begin()); it < argsVector.end() ; ++it) 			// iterates over arguments
		sendArgument(*it);								// sends single argument to server

	close(communicati);
}

void client_sender::beginCommunication () {

	struct sockaddr_in serv_addr;

	struct hostent *server;

	communicati = socket(AF_INET, SOCK_STREAM, 0);

	if (communicati < 0)
		throw sender_errors[OPENING_ERROR];

	server = gethostbyname(args.getHostname().c_str());

	if (server == NULL)
		throw sender_errors[NOHOST_ERROR];

	bzero((char *) &serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;

	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(args.getPortNumber());

    if (connect(communicati, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        throw sender_errors[CONNECT_ERROR];

}

void client_sender::sendArgc (const unsigned int argc) { // number of arguments

	int n;

	n = write(communicati, &argc, sizeof(argc));

	nCheck (n, WRITE_ERROR);
}

void client_sender::sendArgument (string argument) {

		vector <char> data (argument.begin(), argument.end());

		string output(data.begin(), data.end());

		cout << "buffered info: " << output << endl;

		int n;

		// hand shake - send bufferSize

		unsigned int bufferSize = data.size();

		cout << "buffer size: " << bufferSize << endl;

		n = write(communicati, &bufferSize , sizeof(bufferSize));

		nCheck (n, WRITE_ERROR);

		// sending of actual parameters

	    n = write(communicati, &data[0], bufferSize);

		nCheck (n, WRITE_ERROR);
};

const char* client_sender::sender_errors[] {	// list of client errors
		"ERROR opening socket",
		"ERROR, no such host",
		"ERROR connecting",
		"ERROR writing to socket",
		"ERROR reading from socket",
		"ERROR transmitting stuff"
};
