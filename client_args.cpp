#include "client_args.h"

client_args::client_args(){
};

client_args::~client_args(){
};

void client_args::argumentsParsing(const int argc, char** arguments) {

	argcCheck(argc);

	setHostname(arguments);

	setPortNumber(arguments);

	setLogin(arguments);
	
	setAssortmentType(arguments);
}

void client_args::argcCheck(const int argc) {	// method of arguments numeric check
	if (argc < MIN_CLIENT_ARGC)
		throw client_errors[FEW_ARGS];
		
	if (argc > MAX_CLIENT_ARGC)
		throw client_errors[MANY_ARGS];
}

void client_args::setHostname(char **arguments) {	// sets hostname
	if (std::strcmp(arguments[HOST_TAG], "-h"))
		throw client_errors[error_HOST];

	hostname = arguments[HOST_NAME];
}

void client_args::setPortNumber(char **arguments) {	// sets port number
	if (std::strcmp(arguments[PORT_TAG], "-p"))
		throw client_errors[error_PORT];

	port = std::atoi(arguments[PORT_NUMBER]);

	if (port <= INVALID_PORT_NUMBERS)
		throw client_errors[error_PORT_NUMBER];
}

void client_args::setLogin(char **arguments) {	// sets login argument
	if (std::strcmp(arguments[LOGIN_TAG], "-l"))
		throw client_errors[error_LOGIN];

	login = arguments[LOGIN_NAME];
}

void client_args::setAssortmentType(char **arguments) {	// sets assortment type and value
	
	if (arguments[ASSORT_TAG][0] != '-' )	// check prefix
		throw client_errors[error_ASSORT_TYPE];


	switch (arguments[ASSORT_TAG][1]) {		// dispatch assortment type
		case 'L' :
			assortment = static_cast<int>(USER_NAME);
			break; 

		case 'U' :
			assortment = static_cast<int>(UID);
			break;

		case 'G' :
			assortment = static_cast<int>(GID);
			break;

		case 'N' :
			assortment = static_cast<int>(WHOLE_NAME);
			break;

		case 'H' :
			assortment = static_cast<int>(HOME_DIR);
			break;

		case 'S' :
			assortment = static_cast<int>(LOG_SHELL);
			break;

		default: 
			throw client_errors[error_ASSORT_TYPE];
			break;
	}

	assortValue = arguments[ASSORT_VALUE];	// sets assort value

}

const char* client_args::client_errors[] {	// list of client erors
	"too few arguments to a sucessful client call",
	"too many arguments to a sucessful client call",
	"first argument must be hostname",
	"second argument must be port",
	"invalid port number",
	"third argument must be login",
	"fourth argument must be an valid assortment type"
};

