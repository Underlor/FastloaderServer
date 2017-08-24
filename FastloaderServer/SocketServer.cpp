#include "SocketServer.h"

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>

SocketServer::SocketServer(char *port): port(port)
{
	addrinfo hints, *result;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if(getaddrinfo(nullptr, port, &hints, &result) != 0)
	{
		perror("getaddrinfo error!");
		return;
	}

	for(addrinfo *ai = result; ai != nullptr; ai = ai->ai_next)
	{
		if((sd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol)) == -1)
		{
			perror("server socket creation error!");
			continue;
		}

		if(setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (int*)1, sizeof(int)) == -1)
		{
			perror("server socket setsockopt error!");
			exit(1);
		}

		if(bind(sd, ai->ai_addr, ai->ai_addrlen) == -1)
		{
			close(sd);
			perror("server socket bind error!");
			continue;
		}
	}
}
