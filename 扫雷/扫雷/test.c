#include"game.h"

void menu()
{
	printf("***************\n");
	printf("****1. play****\n");
	printf("****0. exit****\n");
	printf("***************\n");
}
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');

	//display_board(mine, ROW, COL);
	//display_board(show, ROW, COL);

	srand((unsigned int)time(NULL));
	mine_set(mine, ROW, COL);
	display_board(mine, ROW, COL);

	mine_search(mine, show, ROW, COL);
}
void test()
{
	int input = 0;
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
			printf("请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}