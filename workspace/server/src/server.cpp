#include "server.h"

#include "server_users_parser.h"
#include <vector>
#include <string>

int main (int argc, char *argv[]) {

	server_args args;

	try {
		args.argumentsParsing(argc, argv);
	} catch (const char* e) {
		std::cout << "el problema: " << e << std::endl;
		return 1;
	}

	std::vector <std::string> vet;

	string tmp = "-l";

	vet.push_back(tmp);

	tmp = "lala52";

	vet.push_back(tmp);

	tmp = "xhodan08";

	vet.push_back(tmp);

	tmp = "xhodan02";

	vet.push_back(tmp);

	tmp = "xhodan03";

	vet.push_back(tmp);

	tmp = "xhodan";

	vet.push_back(tmp);

	std::vector <char> filter;

	filter.push_back(1);

	server_users_parser parser(vet, filter);


	cout << endl << "yayay IM Lorde" << endl;
	return 0;

	// TODO check if passwd file sexists
	server_initializer server;

	try {
		server.inicializeServer(args.getPortNumber());
	} catch (const char * e) {
		std::cout << "el problema socketa: " << e << std::endl;
		return 1;
	}

	server.startsListening();	// starts server

	host_handle host;

	try {
		host.handleHost(server.getSocket());
	} catch (const char * e) {
		server.closeSocket();
		std::cout << "el problema listenera: " << e << std::endl;
		return 1;
	}

	server.closeSocket();		// stops server

	return 0;
}
