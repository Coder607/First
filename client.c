#include "gomoku.h"
#include "my_socket.h"

#define IP "127.0.0.1"
#define PORT 7777

int main() {
	char gomoku[N][N] = {0};
	SA_IN server_addr = {0};
	int msg[2] = {0};
	int fd_socket = 0;
	int sendlen = 0;
	int recvlen = 0;

	my_socketCli(&fd_socket, MY_TCP, IP, PORT, &server_addr);
	my_connect(fd_socket, (pSA)&server_addr, sizeof(SA_IN));

	printf("client start\n");
	gomoku_init(gomoku);

	int x = 0;
	int y = 0;

	while(1) {
loop:
		printf("client 请下棋\n");
		scanf("%d %d", &x, &y);

		if (gomoku[x][y] != '_') {
			printf("这个位置已经有棋子了\n");
			goto loop;
		}

		if (x < 1 || y < 1 || x > N - 1 || y > N - 1) {
			printf("参数错误\n");
		}

		gomoku[x][y] = '#';
		gomoku_show(gomoku);

		if (checkWin(x, y, gomoku, '#')) {
			printf("client win!\n");
			msg[0] = -1;
			msg[1] = -1;
			my_send(&sendlen, fd_socket, msg, 8);
			break;
		}

		printf("请等待server下棋\n");

		msg[0] = x;
		msg[1] = y;

		my_send(&sendlen, fd_socket, msg, 8);

		my_recv(&recvlen, fd_socket, msg, 128);
		
		if (msg[0] == -1 && msg[1] == -1) {
			printf("server win!\n");
			break;
		}

		gomoku[msg[0]][msg[1]] = '*';
		gomoku_show(gomoku);
	}

	my_close(fd_socket);
	
	return 0;
}
