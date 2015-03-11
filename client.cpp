#include "client.h"

/*
void error(const char *msg)
{
	perror(msg);
	exit(0);
}*/

#include <map>




int main (int argc, char **argv)
{

	


	client_args args;

	try {
		args.argumentsParsing(argc, argv);

	} catch (const char* e) {
		std::cout << "an error has occured: " << e << "\n";
		system("pause");
		exit(42);
	}

	std::cout << "hostaname: " << args.getHostname() << std::endl;
	std::cout << "potnumber: " << args.getPortNumber() << std::endl;
	std::cout << "loginname: " << args.getLogin() << std::endl;

	/*int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];
	if (argc < 3) {
		fprintf(stderr, "usage %s hostname port\n", argv[0]);
		exit(0);
	}
	portno = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");
	server = gethostbyname(argv[1]);
	if (server == NULL) {
		fprintf(stderr, "ERROR, no such host\n");
		exit(0);
	}
	bzero((char *)&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr,
		(char *)&serv_addr.sin_addr.s_addr,
		server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR connecting");
	printf("Please enter the message: ");
	bzero(buffer, 256);
	fgets(buffer, 255, stdin);
	n = write(sockfd, buffer, strlen(buffer));
	if (n < 0)
		error("ERROR writing to socket");
	bzero(buffer, 256);
	n = read(sockfd, buffer, 255);
	if (n < 0)
		error("ERROR reading from socket");
	printf("%s\n", buffer);
	close(sockfd);*/

	system("pause");
	return 0;
}