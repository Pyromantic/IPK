#include "server.h"

int main (int argc, char *argv[]) {


	server_args args;

	try {
		args.argumentsParsing(argc, argv);
	} catch (const char* e) {
		std::cout << "el problema: " << e << std::endl;
		return 1;
	}

	std::cout << "port NUm: " << args.getPortNumber() << std::endl;

	socket_binder socket;

	int socketNumber(0);

	try {
		socketNumber = socket.binder(args.getPortNumber());
	} catch (const char * e) {
		std::cout << "el problema socketa: " << e << std::endl;
		return 1;
	}

	server_listener listener;

	listener.setSocket(socketNumber);

	try {
		listener.listener();
	} catch (const char * e) {
		std::cout << "el problema listenera: " << e << std::endl;
		return 1;
	}

	return 0;
}
