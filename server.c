#include "gomoku.h"
#include "my_socket.h"

#define IP "127.0.0.1"
#define PORT 7777

int main() {
	int msg[2] = {0};
	char gomoku[N][N] = {0};
	SA_IN client_addr = {0};
	int fd_listen = 0;
	int fd_client = 0;
	
	my_socketSer(&fd_listen, MY_TCP, IP, PORT);
	my_listen(fd_listen, 5);

	int sendlen = 0;
	int recvlen = 0;
	int len = 0;

	int x = 0;
	int y = 0;
	
	gomoku_init(gomoku);
	gomoku_show(gomoku);

	printf("五子棋游戏开始\n");

	my_accept(&fd_client, fd_listen, (pSA)&client_addr);

	while (1) {
		printf("请等待client下棋\n");
		my_recv(&recvlen, fd_client, msg, 128);

		if (msg[0] == -1 && msg[1] == -1) {
			printf("client win!\n");
			break;
		}

		gomoku[msg[0]][msg[1]] = '#';
		gomoku_show(gomoku);
	
	loop:
		printf("server 请下棋\n");
		scanf("%d %d", &x, &y);

		if (gomoku[x][y] != '_') {
			printf("该位置已经有棋子了！\n");
			goto loop;
		}

		if (x > N - 1 || y > N -1 || x < 1 || y < 1) {
			printf("参数错误！\n");
		}

		gomoku[x][y] = '*';
		gomoku_show(gomoku);

		if (checkWin(x, y, gomoku, '*')) {
			printf("server win!\n");
			msg[0] = -1;
			msg[1] = -1;
			my_send(&sendlen, fd_client, msg, 8);
			break;
		}

		msg[0] = x;
		msg[1] = y;
		my_send(&sendlen, fd_client, msg, recvlen);
	}

	my_close(fd_client);
	my_close(fd_listen);
}
