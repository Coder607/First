#ifndef MY_SOCKET_H
#define MY_SOCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MY_TCP 1
#define MY_UDP 2

typedef struct sockaddr* pSA;
typedef struct sockaddr_in SA_IN;

#define ASSERT(flag, msg) ((flag)? NULL : (fprintf(stdout, msg), exit(EXIT_FAILURE)))

void my_socketCli(int* fd_socket, int type, char* ip, int port, SA_IN* my_addr);
void my_connect(int fd_socket, pSA server_addr, int len);
void my_socketSer(int* fd_socket, int type, char* ip, int port);
void my_listen(int fd_socket, int listen_num);
void my_accept(int* fd_client, int fd_socket, pSA client_addr);
void my_send(int* sendlen, int fd_socket, int* msg, int len);
void my_recv(int* recvlen, int fd_socket, int* msg, int len);
void my_close(int fd_socket);

#endif
