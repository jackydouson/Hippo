#include "hiSocket.h"

namespace hippo
{
	Socket::Socket()
		:m_uSocket(INVALID_SOCKET)
	{
		WSADATA wsaData;
		if (0 != WSAStartup(MAKEWORD(2, 0), &wsaData)) return;
		if (2 != LOBYTE(wsaData.wVersion) || 0 != HIBYTE(wsaData.wVersion))
		{
			WSACleanup();
			return;
		}
	}

	Socket::~Socket()
	{
		Close();
	}

	void Socket::Close()
	{
		if (INVALID_SOCKET == m_uSocket) return;
#ifdef WIN32
		closesocket(m_uSocket);
#else
		close(m_uSocket);
#endif
		m_uSocket = INVALID_SOCKET;
	}

	bool Socket::Init()
	{
		Close();

		m_uSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (INVALID_SOCKET == m_uSocket) return false;

		bool bNon = true;
#ifdef WIN32
		unsigned long ul = bNon;
		int nRet = ioctlsocket(m_uSocket, FIONBIO, (unsigned long*)&ul);
#else
		int flags = fcntl(m_Socket, F_GETFL, 0);
		bNon ? flags |= O_NONBLOCK : flags -= O_NONBLOCK;
		int nRet = fcntl(m_uSocket, F_SETFL, flags);
#endif
		if (SOCKET_ERROR == nRet)
		{
			Close();
			return false;
		}

		const char opt = 1;
		if (setsockopt(m_uSocket, IPPROTO_TCP, TCP_NODELAY, &opt, sizeof(char)))
		{
			Close();
			return false;
		}

		return true;
	}

	bool Socket::Connect()
	{

	}
}