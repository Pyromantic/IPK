/*
 * client_sender.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: majk
 */

#include "client_communication_handle.h"

using namespace std;

client_communication_handle::client_communication_handle() : communicati(0) {
}

client_communication_handle::~client_communication_handle() {

}

void client_communication_handle::beginCommunication (unsigned int port, string hostname) {

	struct sockaddr_in serv_addr{};

	struct hostent *server{};

	communicati = socket(AF_INET, SOCK_STREAM, 0);

	if (communicati < 0)
		throw sender_errors[OPENING_ERROR];

	server = gethostbyname(hostname.c_str());

	if (server == NULL)
		throw sender_errors[NOHOST_ERROR];

	serv_addr.sin_family = AF_INET;

    serv_addr.sin_port = htons(port);

    if (connect(communicati, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        throw sender_errors[CONNECT_ERROR];
}

void client_communication_handle::sendArguments (vector <string> inquiry, vector <char> filter) {	// sends server arguments

	sendArgc (inquiry.size());	// sends number of inquiry arguments to server

	for (auto it (inquiry.begin()); it < inquiry.end(); ++it) 	// iterates over arguments
		sendArgument (*it);		// sends single argument to server

	unsigned int argc = filter.size();

	sendArgc (argc);			// sends number of filter arguments to server

	if (argc)
		sendFilter (filter);	// send whole filter vector

	// TODO receive message containing proceeded query

	close(communicati);
}

void client_communication_handle::sendArgc (const unsigned int argc) { // number of arguments

	int n;

	n = write(communicati, &argc, sizeof(argc));

	nCheck (n, WRITE_ERROR);
}

void client_communication_handle::sendArgument (string argument) {

		vector <char> data (argument.begin(), argument.end());

		string output(data.begin(), data.end());

		int n(0);

		// hand shake - send bufferSize

		unsigned int bufferSize = data.size();

		n = write(communicati, &bufferSize , sizeof(bufferSize));

		nCheck (n, WRITE_ERROR);

		// sending of actual parameters

	    n = write(communicati, &data[0], bufferSize);

		nCheck (n, WRITE_ERROR);
};

void client_communication_handle::sendFilter (vector <char> filter) {

	int n = write(communicati, &filter[0], filter.size());

	nCheck (n, WRITE_ERROR);
};

const char* client_communication_handle::sender_errors[] {	// list of client errors
		"ERROR opening socket",
		"ERROR, no such host",
		"ERROR connecting",
		"ERROR writing to socket",
		"ERROR reading from socket",
		"ERROR transmitting stuff"
};
