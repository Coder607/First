#include "gomoku.h"

int checkWin(int x, int y, char gomoku[N][N], char flag) {
	int i = 0;
	int j = 0;
	int cnt = 0;

	//判断水平方向
	for (j = y + 1; j < N; j++) {
		if (gomoku[x][j] == flag) {
			cnt++;
		} else {
			break;
		}
	}

	for (j = y - 1; j > 0; j--) {
		if (gomoku[x][j] == flag) {
			cnt++;
		} else {
			break;
		}
	}

	if (cnt >= 4) return 1;
	cnt = 0;


	//判断垂直方向
	for (int i = x + 1; i < N; i++) {
		if (gomoku[i][y] == flag) {
			cnt++;
		} else {
			break;
		}
	}

	for (int i = x - 1; i > 0; i--) {
		if (gomoku[i][y] == flag) {
			cnt++;
		} else {
			break;
		}
	}

	if (cnt >= 4) return 1;
	cnt = 0;


	//判断45度方向
	for (i = x - 1, j = y + 1; i > 0 && j < N; i--, j++) {
		if (gomoku[i][j] == flag) {
			cnt++;
		} else {
			break;
		}
	}

	for (i = x + 1, j = y - 1; i < N && j > 0; i++, j--) {
		if (gomoku[i][j] == flag) {
			cnt++;
		} else {
			break;
		}
	}

	if (cnt >= 4) return 1;
	cnt = 0;


	//判断135度方向
	for (i = x - 1, j = y - 1; i > 0 && j > 0; i--, j--) {
		if (gomoku[i][j] == flag) {
			cnt++;
		} else {
			break;
		}
	}

	for (i = x + 1, j = y + 1; i < N && j < N; i++, j++) {
		if (gomoku[i][j] == flag) {
			cnt++;
		} else {
			break;
		}
	}

	if (cnt >= 4) return 1;

	return 0;

}


void gomoku_init(char gomoku[N][N]) {
	int i = 0;
	int j = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			gomoku[i][j] = '_';
		}
	}

	for (i = 0; i < N; i++) gomoku[i][0] = gomoku[0][i] = ('0' + i);
}


void gomoku_show(char gomoku[N][N]) {
	int i = 0;
	int j = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%c ", gomoku[i][j]);
		}

		printf("\n");
	}
}

