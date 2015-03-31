/*
 * client_sender.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: majk
 */

#include "client_communication_handle.h"

client_communication_handle::client_communication_handle(unsigned int port, string hostname) {
	beginCommunication(port, hostname);
};

client_communication_handle::~client_communication_handle() {

}

void client_communication_handle::beginCommunication (unsigned int port, string hostname) {

	struct sockaddr_in serv_addr{};

	struct hostent *server{};

	hostSocket = socket(AF_INET, SOCK_STREAM, 0);

	if (hostSocket < 0)
		throw sender_errors[OPENING_ERROR];

	server = gethostbyname(hostname.c_str());

	if (server == NULL)
		throw sender_errors[NOHOST_ERROR];

	serv_addr.sin_family = AF_INET;

    serv_addr.sin_port = htons(port);

    if (connect(hostSocket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        throw sender_errors[CONNECT_ERROR];
}

void client_communication_handle::sendArguments (vector <string> inquiry, vector <char> filter) {	// sends server arguments

	sendVector (inquiry);

	sendArgc (filter.size());	// sends number of filter arguments to server

	if (filter.size())
		sendFilter (filter);	// send whole filter vector

	output = receiveVector();
};

void client_communication_handle::sendFilter (vector <char> filter) {

	int n = write(hostSocket, &filter[0], filter.size());

	nCheck (n, WRITE_ERROR);
};

const char* client_communication_handle::sender_errors[] {	// list of client errors
		"ERROR opening socket",
		"ERROR, no such host",
		"ERROR connecting",
};
