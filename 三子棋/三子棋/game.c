#include"game.h"
//��ʼ������
void init_board(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
}
//��ӡ����
void print_board(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
//�������
void player_move(char board[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("�������:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�����ѱ�ռ�ã���������\n");
		}
		else
			printf("�Ƿ�����\n");
	}
}
//��������
void computer_move(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("��������\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % row;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//�ж���Ӯ
int is_empty(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			if (board[i][j] == ' ')
				return 1;
	return 0;
}
char is_win(char board[ROW][COL], int row, int col)
{
	int i, j;
	char c;
	//���ж�
	for (i = 0; i < row; i++)
	{
		if ((c = board[i][0]) == ' ')
			continue;
		for (j = 1; j < col && c == board[i][j]; j++);
		if (j == col)
			return c;
	}
	//���ж�
	for (j = 0; j < col; j++)
	{
		if ((c = board[0][j]) == ' ')
			continue;
		for (i = 1; i < row && c == board[i][j]; i++);
		if (i == row)
			return c;
	}
	//�Խ��ж�
	c = board[0][0];
	for (i = 1; c != ' ' && i < row && c == board[i][i]; i++);
	if (i == row)
		return c;
	c = board[row - 1][0];
	for (j = 1; c != ' ' && j < col && c == board[row - 1 - j][j]; j++);
	if (j == col)
		return c;
	//ƽ�ֻ��Ǽ���
	if (is_empty(board, row, col))
		return 'C';
	else
		return 'Q';
}
