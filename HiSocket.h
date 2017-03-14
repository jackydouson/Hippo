/********************************************************************************
Name: hiSocket.h
Desc: Network socket base
Auth: Jacky Dawson
Mail: 497436362@qq.com
Date: 20170303
Last: 20170303
Copyright (c) 2017 Hippo Inc.
********************************************************************************/

#ifndef __HI_SOCKET_H__
#define __HI_SOCKET_H__

#define WIN32
#ifdef WIN32
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")
#else
typedef unsigned int          SOCKET;
#define INVALID_SOCKET  (SOCKET)(~0)
#define SOCKET_ERROR            (-1)
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#include "hiMacros.h"

namespace hippo
{

class Socket
{
public:
	Socket();
	Socket(const std::string& ip, int pt);
	~Socket();

public:
	void close();
	bool init();
	bool connect();
	bool isConnected();
	bool isReadable();
	bool isWritable();
	int	 read(char* _buff, int _len);
	int  write(char* _buff, int _len);

protected:
	SOCKET m_uSocket;
};

}

#endif