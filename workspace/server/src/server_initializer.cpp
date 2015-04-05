/*
 * server_initializer.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: majk
 */

#include "server_initializer.h"

server_initializer::server_initializer() {

};

server_initializer::~server_initializer() {

};


void server_initializer::signalHandler (int signum) {
	shutdown(server_initializer::listener, 2);
	exit(signum);
};


void server_initializer::inicializeServer(const int port) {

	listener = socket(AF_INET, SOCK_STREAM, 0);

	if (listener < 0)
		throw socket_errors[ERROR_OPENING];

	struct sockaddr_in serv_addr{};

	serv_addr.sin_family = AF_INET;

	serv_addr.sin_addr.s_addr = INADDR_ANY;

	serv_addr.sin_port = htons(port);

	if (bind(listener, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		throw socket_errors[ERROR_BINDING];
};

void server_initializer::startsListening() {

	if (listen(listener, 128) < 0) 		// starts listening
		throw socket_errors[ERROR_LISTEN];

	signal(SIGINT, server_initializer::signalHandler);

	while (1) {
		struct sockaddr_in cli_addr;

		unsigned int clilen = sizeof(cli_addr);

		int hostSocket = accept(listener, (struct sockaddr *) (&cli_addr), &clilen);

		if (hostSocket < 0) {
			close (listener);
			throw socket_errors[ERROR_ACCEPT];
		};

		pid_t pid = fork();

		if (pid < 0) {
			close (listener);
			close (hostSocket);
			cout << socket_errors[ERROR_FORK];
		}

		if (pid == 0) {
			host_handle host(hostSocket);
			return;
		}

	}
};

int server_initializer::listener{0};

const char* server_initializer::socket_errors[] {
	"ERROR opening socket",
	"ERROR listening",
	"ERROR on binding",
	"ERROR on accept",
	"ERROR on forking process",
};
