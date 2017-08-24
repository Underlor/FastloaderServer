#pragma once

class SocketServer
{
public:
	SocketServer(char*);
private:
	/**
	 * \brief Socket Descriptor
	 */
	int sd;
	/**
	 * \brief Socket Server port
	 */
	char *port;
};
