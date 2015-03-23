#include "client_args.h"


client_args::client_args() : port(0), assortment(0) {

};

client_args::~client_args(){
};

void client_args::argumentsParsing(const unsigned int argc, char** arguments) {

	argcCheck(argc);

	setHostname(arguments);

	setPortNumber(arguments);

	setAssortmentType(argc,arguments);
}

void client_args::argcCheck(const unsigned int argc) {		// method of arguments numeric check
	if (argc < MIN_CLIENT_ARGC)
		throw client_errors[FEW_ARGS];

	if (argc > MAX_CLIENT_ARGC)
		throw client_errors[MANY_ARGS];
}

void client_args::setHostname(char **arguments) {	// sets host name
	hostname = arguments[HOST_NAME];
}

void client_args::setPortNumber(char **arguments) {	// sets port number
	int check = atoi(arguments[PORT_NUMBER]);

	if (check <= INVALID_PORT_NUMBERS)
		throw client_errors[ERROR_PORT_NUMBER];

	port = static_cast<unsigned short int>(check);
}

void client_args::setAssortmentType(const unsigned int argc, char **arguments) {	// sets assortment type and value

	unsigned int assortTag (ASSORT_TAG);
	unsigned int assortValue (ASSORT_VALUE);

	while (argc > assortTag) {				// iterates over arguments

		string tmp = arguments[assortTag];

		if (tmp.size() != 2)
			throw client_errors[ERROR_ASSORT_TYPE];

		if (tmp.at(FIRST_CHAR) != '-' )		// check prefix
			throw client_errors[ERROR_ASSORT_TYPE];

		switch (tmp.at(IDENTIFIER)) {		// dispatch assortment type
			case 'L' :
				tmp =  USER_NAME;
				break;

			case 'U' :
				tmp = UID;
				break;

			case 'G' :
				tmp = GID;
				break;

			case 'N' :
				tmp = WHOLE_NAME;
				break;

			case 'H' :
				tmp = HOME_DIR;
				break;

			case 'S' :
				tmp = LOG_SHELL;
				break;

			default:
				throw client_errors[ERROR_ASSORT_TYPE];
				break;
		}

		if (argc < assortValue)
			throw client_errors[ERROR_ASSORT_VALUE];

		tmp.append(arguments[assortValue]);	// sets assort value

		assortment.push_back(tmp);			// push to vector

		assortTag += NEXT_ARG;
		assortValue += NEXT_ARG;
	}
};

const char* client_args::client_errors[] {	// list of client errors
	"too few arguments to a successful client call",
	"too many arguments to a successful client call",
	"invalid port number",
	"third argument must be login",
	"argument must be an valid assortment type",
	"assortment value is not set properly",
};
