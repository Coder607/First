#include "my_socket.h"

void my_socketCli(int* fd_socket, int type, char* ip, int port, SA_IN* my_addr) {
	ASSERT(type == MY_TCP || type == MY_UDP, "invalid arg\n");
	
	if (type == MY_TCP) {
		ASSERT((*fd_socket = socket(AF_INET, SOCK_STREAM, 0)) != -1, "TCP SOCKET INIT FAIL!\n");
	} else if (type == MY_UDP) {
		ASSERT((*fd_socket = socket(AF_INET, SOCK_DGRAM, 0)) != -1, "UDP SOCKET INIT FAIL!\n");
	}

	memset(my_addr, 0, sizeof(SA_IN));
	(*my_addr).sin_family = AF_INET;
	(*my_addr).sin_port = htons(port);
	(*my_addr).sin_addr.s_addr = inet_addr(ip);
	
	return;
}


void my_socketSer(int* fd_socket, int type, char* ip, int port) {
	ASSERT(type == MY_TCP || type == MY_UDP, "invalid arg\n");

	if (type == MY_TCP) {
		ASSERT((*fd_socket = socket(AF_INET, SOCK_STREAM, 0)) != -1, "TCP SOCKET INIT FAIL\n");
	} else if (type == MY_UDP) {
		ASSERT((*fd_socket = socket(AF_INET, SOCK_DGRAM, 0)) != -1, "UDP SOCKET INIT FAIL\n");
	}

	SA_IN my_addr;
	memset(&my_addr, 0, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	printf("PORT: %d, IP: %s\n", port, ip);
	my_addr.sin_port = htons(port);
	my_addr.sin_addr.s_addr = inet_addr(ip);

	int len = sizeof(my_addr);
	ASSERT(bind(*fd_socket, (struct sockaddr*)&my_addr, len) != -1, "BIND FAIL\n");

	return;
}


void my_listen(int fd_socket, int listenNum) {
	ASSERT(listen(fd_socket, listenNum) != -1,"LISTEN FAIL\n" );
}


void my_accept(int* fd_client, int fd_socket, pSA client_addr) {
	int size = sizeof(SA_IN);
	ASSERT((*fd_client = accept(fd_socket, client_addr, &size)) != -1, "ACCEPT FAIL\n");
}


void my_send(int* sendlen, int fd_socket, int* msg, int len) {
	ASSERT((*sendlen = send(fd_socket, msg, len, 0)) != -1, "SEND FAIL\n");
}


void my_recv(int* recvlen, int fd_socket, int* msg, int len) {
	ASSERT((*recvlen = recv(fd_socket, msg, len, 0)) != -1, "RECV FAIL\n");
}


void my_close(int fd_socket) {
	close(fd_socket);
}


void my_connect(int fd_socket, pSA server_addr, int len) {
	connect(fd_socket, server_addr, len);
}

