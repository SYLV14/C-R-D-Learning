
#include"game.h"

void menu()
{
	printf("****************\n");
	printf("*****1. play****\n");
	printf("*****0. exit****\n");
	printf("****************\n");
}
void game()
{
	char board[ROW][COL];
	srand((unsigned int)time(NULL));
	init_board(board, ROW, COL);
	print_board(board, ROW, COL);
	char ret;
	while (1)
	{
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
			break;
		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else if (ret == 'Q')
		printf("平局\n");
}

void test()
{
	int input=0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("重新输入\n");
				break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}

