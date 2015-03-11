#include "client_args.h"

void client_args::stringy(int) {
}

void client_args::argumentsParsing(const int argc, char** arguments) {

	argcCheck(argc);

	setHostname(arguments);

	setPortNumber(arguments);

	setLogin(arguments);
	


	setAssortmentType(arguments);

}



inline void client_args::argcCheck(const int argc) {	// overridden method of arguments numeric check
	if (argc < MIN_CLIENT_ARGC)
		throw errors[FEW];
		
	if (argc > MAX_CLIENT_ARGC)
		throw errors[MANY];
}

inline void client_args::setHostname(char **arguments) {	// sets hostname
	if (std::strcmp(arguments[HOST_TAG], "-h"))
		throw client_errors[error_HOST];

	hostname = arguments[HOST_NAME];
}

inline void client_args::setPortNumber(char **arguments) {	// sets port number
	if (std::strcmp(arguments[PORT_TAG], "-p"))
		throw client_errors[error_PORT];

	port = std::atoi(arguments[PORT_NUMBER]);

	if (port <= 0)
		throw client_errors[error_PORT_NUMBER];
}

inline void client_args::setLogin(char **arguments) {
	if (std::strcmp(arguments[LOGIN_TAG], "-l"))
		throw client_errors[error_LOGIN];

	login = arguments[LOGIN_NAME];
}

void client_args::setAssortmentType(char **arguments) {
	
	

}

const char* client_args::client_errors[] {
	"first argument must be hostname",
	"second argument must be port",
	"invalid port number",
	"third argument must be login",
};

