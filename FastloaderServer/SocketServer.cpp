#include "SocketServer.h"

SocketServer::SocketServer(int port): port(port)
{
	addrinfo hints, *result;
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	char c[5];
	sprintf(c, "%d", port);

	if(getaddrinfo(nullptr, c, &hints, &result) != 0)
	{
		perror("getaddrinfo error");
		return;
	}

	addrinfo *ai;
	for(ai = result; ai != nullptr; ai = ai->ai_next)
	{
		if((descriptor = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol)) == -1)
		{
			perror("server socket: creation error");
			continue;
		}

		int yes = 1;
		if(setsockopt(descriptor, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
		{
			perror("server socket: setsockopt error");
			exit(1);
		}

		if(bind(descriptor, ai->ai_addr, ai->ai_addrlen) == -1)
		{
			close(descriptor);
			perror("server socket: bind error");
			continue;
		}

		break;
	}

	freeaddrinfo(result);

	if(ai == nullptr)
	{
		perror("server socket: failed to find addr");
		exit(1);
	}
}

void SocketServer::Listen() const
{
	if(listen(descriptor, 10) == -1)
	{
		perror("server socket: listen error");
		exit(1);
	}
}

SocketClient* SocketServer::Accept() const
{
	sockaddr addr;
	socklen_t sin_len = sizeof addr;
	return new SocketClient(accept(descriptor, (sockaddr*)&addr, &sin_len), addr);
}
