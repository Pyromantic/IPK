#include "socket_binder_unix.h"


socket_binder::socket_binder() {

}

socket_binder::~socket_binder() {

}

int socket_binder::binder(const unsigned short int port) {

		struct sockaddr_in serv_addr;

		int sockfd = socket(AF_INET, SOCK_STREAM, 0);

		if (sockfd < 0)
			throw socket_errors[ERROR_OPENING];

		bzero((char *)&serv_addr, sizeof(serv_addr));

		serv_addr.sin_family = AF_INET;

		serv_addr.sin_addr.s_addr = INADDR_ANY;

		serv_addr.sin_port = htons(port);

		if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
			throw socket_errors[ERROR_BINDING];
		
		return sockfd;
}

const char* socket_binder::socket_errors[] {
	"ERROR opening socket",
	"ERROR on binding",
};


