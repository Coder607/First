#ifndef _GOMOKU_
#define _GOMOKU_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int checkWin(int x, int y, char gomoku[N][N], char flag);
void gomoku_init(char gomoku[N][N]);
void gomoku_show(char gomoku[N][N]);

#endif
