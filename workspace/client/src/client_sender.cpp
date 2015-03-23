/*
 * client_sender.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: majk
 */

#include "client_sender.h"

client_sender::client_sender (client_args arguments) : communicati(0) {
	args = arguments;		// args init
}

client_sender::~client_sender() {

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

void client_sender::sendStuff() {

		string tmp = args.getAssortmentValue();

		std::vector<char> data (tmp.begin(),tmp.end());

		std::string output(data.begin(), data.end());

		std::cout << "buffered info: " << output << std::endl;
		//	data.push_back(tmp);

		int n;

		// hand shake - send

		unsigned int bufferSize = data.size();

		std::cout << "buffer size: " << bufferSize << std::endl;

		n = write(communicati, &bufferSize , sizeof(bufferSize));

		nCheck (n, WRITE_ERROR);

		// hand shake - receive

		int welcome(NEGATIVE);

		n = read(communicati, &welcome, sizeof(welcome));

		nCheck (n, READING_ERROR);

		switch (welcome) {
		case AFFIRMATIVE:
			// -- successful
			break;

		case NEGATIVE :
			throw sender_errors[TRANSMIT_ERROR];
			break;

		default:
			throw sender_errors[TRANSMIT_ERROR];
			break;
		}


		// sending of actual parameters

	    n = write(communicati, &data[0], bufferSize);

		nCheck (n, WRITE_ERROR);


		// lalla got yo message

	    char readBuffer[255]{};

		n = read(communicati, readBuffer, sizeof(readBuffer));

		nCheck (n, READING_ERROR);

		std::cout << readBuffer << std::endl;

		close(communicati);
};

const char* client_sender::sender_errors[] {	// list of client errors
		"ERROR opening socket",
		"ERROR, no such host",
		"ERROR connecting",
		"ERROR writing to socket",
		"ERROR reading from socket",
		"ERROR transmitting stuff"
};
