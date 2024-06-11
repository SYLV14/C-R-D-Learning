
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
		printf("���Ӯ\n");
	else if (ret == '#')
		printf("����Ӯ\n");
	else if (ret == 'Q')
		printf("ƽ��\n");
}

void test()
{
	int input=0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("��������\n");
				break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}

