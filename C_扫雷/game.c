#include"game.h"
//初始化棋盘
void init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			board[i][j] = set;
}
//打印棋盘
void display_board(char board[ROWS][COLS], int row, int col)
{
	printf("-------------------\n");
	int i, j;
	for (i = 0; i <= row; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
			printf("%c ", board[i][j]);
		printf("\n");
	}
	printf("-------------------\n");
}
//布置雷
void mine_set(char mine[ROWS][COLS], int row, int col)
{
	int x, y;
	int count = 0;
	while (count < EASY_COUNT)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count++;
		}
	}
}
//自动展开
int Expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y) {
	if (x >= 1 && y >= 1 && x <= row && y <= col) {
		int num = get_mine_count(mine, x, y);
		if (num == 0) {
			show[x][y] = ' ';
			if (show[x - 1][y - 1] == '*')
				Expand(mine, show, row, col, x - 1, y - 1);
			if (show[x][y - 1] == '*')
				Expand(mine, show, row, col, x, y - 1);
			if (show[x + 1][y - 1] == '*')
				Expand(mine, show, row, col, x + 1, y - 1);
			if (show[x + 1][y] == '*')
				Expand(mine, show, row, col, x + 1, y);
			if (show[x + 1][y + 1] == '*')
				Expand(mine, show, row, col, x + 1, y + 1);
			if (show[x][y + 1] == '*')
				Expand(mine, show, row, col, x, y + 1);
			if (show[x-1][y + 1] == '*')
				Expand(mine, show, row, col, x - 1, y + 1);
			if (show[x - 1][y] == '*')
				Expand(mine, show, row, col, x - 1, y);
		}
		else
			show[x][y] = num + '0';
	}
}


//排查雷
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y - 1] + mine[x][y + 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}
void mine_search(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int count = 0;
	while (count < (ROW * COL - EASY_COUNT))
	{
		printf("输入坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '0')
			{
				Expand(mine, show, row, col, x, y);
				display_board(show, ROW, COL);
				count++;
			}
			else
			{
				printf("你被炸死了\n");
				display_board(mine, ROW, COL);
				break;
			}
		}
		else
			printf("坐标非法\n");
	}
	if (count == (ROW * COL - EASY_COUNT))
	{
		printf("通关\n");
		display_board(mine, ROW, COL);
	}
}


