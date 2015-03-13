#include "server_args.h"

server_args::server_args() {
};

server_args::~server_args() {
};

void server_args::argumentsParsing(const int argc, char **arguments) {	// parsing argument
	
	argcCheck(argc);

	setPort(arguments);

}	

void server_args::argcCheck(const int argc) {	// method of arguments numeric check
	if (argc < MIN_SERVER_ARGC)
		throw server_errors[FEW_ARGS];

	if (argc > MAX_SERVER_ARGC)
		throw server_errors[MANY_ARGS];
}

void server_args::setPort(char **arguments) {	// sets port number
	if (std::strcmp(arguments[PORT_TAG], "-p"))
		throw server_errors[error_PORT];

	port = std::atoi(arguments[PORT_NUMBER]);

	if (port <= INVALID_PORT_NUMBERS)
		throw server_errors[error_PORT_NUMBER];
}

const char* server_args::server_errors[] {
	"too few arguments to a sucessful server call",
	"too many arguments to a sucessful server call",
	"first argument must be port",
	"invalid port number"
};