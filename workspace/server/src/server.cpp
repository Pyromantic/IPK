#include "server.h"

using namespace std;

int main (int argc, char *argv[]) {

	int port(0);

	try {
		server_args args (argc, argv);
		port = args.getPortNumber();
	} catch (const char* e) {
		cerr << e << endl;
		return 1;
	}

	server_initializer server;

	try {
		server.inicializeServer(port);

		server.startsListening();	// starts server

	} catch (const char * e) {
		cerr << e << endl;
		return 2;
	}

	return 0;
}
