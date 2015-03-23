/*
 * serverlistener.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: majk
 */

#include "server_listener.h"

server_listener::server_listener() : socket(0) {
}

server_listener::~server_listener() {

}

void server_listener::setSocket(unsigned int socketID) {
	socket = socketID;
}

void server_listener::listener () {

	listen(socket, 5);

	struct sockaddr_in cli_addr;

	unsigned int clilen = sizeof(cli_addr);

	int newsockfd = accept(socket, (struct sockaddr *)(&cli_addr), &clilen);

	nCheck (newsockfd, ACCEPT_ERROR);

	int n;

	//	handshake - receiving

	unsigned int bufferSize;

	n = read(newsockfd, &bufferSize, bufferSize);

	nCheck(n, READING_ERROR);

	std::cout << bufferSize << std::endl;

	// handshake - send

	int welcome(AFFIRMATIVE);

	n = write(newsockfd, &welcome, sizeof(welcome));

	nCheck(n, WRITING_ERROR);

	// actual message receiver

	std::vector<char> buffer (bufferSize);

	n = read(newsockfd, &buffer[0], buffer.size());

	nCheck (n, READING_ERROR);

	//std::cout << "kruaw neviwenm "<< std::endl;

	std::string output(buffer.begin(), buffer.end());

	//std::vector<std::string> reader = buffer;


	std::cout << output << std::endl;


	// good bye

	n = write(newsockfd, "I got your message", 18);

	nCheck (n, WRITING_ERROR);

	close(socket);
}

const char* server_listener::listener_errors[] {
	"ERROR on accept",
	"ERROR reading from socket",
	"ERROR writing to socket",
	"Unknown transmit error",
};
