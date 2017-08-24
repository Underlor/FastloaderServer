#pragma once

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>

class Socket
{
public:
	/**
	* \brief Socket Descriptor
	*/
	int descriptor;
};
