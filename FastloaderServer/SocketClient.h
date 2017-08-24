#pragma once
#include "Socket.h"

class SocketClient : public Socket
{
public:
	sockaddr addr;

	SocketClient(int, sockaddr);
	char* GetAddrStr();
};
