﻿#pragma once
#include "SocketClient.h"
#include "Socket.h"

class SocketServer : public Socket
{
public:
	/**
	* \brief Socket Server port
	*/
	int port;

	explicit SocketServer(int);

	void Listen() const;
	SocketClient* Accept() const;
};
