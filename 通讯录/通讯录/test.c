#include"contact.h"
enum Operation {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW,
};

void menu() {
	printf("*************************\n");
	printf("****1. add   2. del  ****\n");
	printf("****3.search 4.modify****\n");
	printf("****5.sort   6.show  ****\n");
	printf("****0.exit           ****\n");
	printf("*************************\n");
}

void test() {
	int input = 0;
	Contact con;
	InitContact(&con);
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input) {
			case ADD:
				AddContact(&con);
				break;
			case DEL:
				DelContact(&con);
				break;
			case SEARCH:
				SearchContact(&con);
				break;
			case MODIFY:
				ModifyContact(&con);
				break;
			case SORT:
				SortContact(&con);
				break;
			case SHOW:
				ShowContact(&con);
				break;
			case EXIT:
				DestoryContact(&con);
				printf("退出\n");
				break;
			default:
				printf("请重新选择\n");
				break;
		}
	} while (input);

}
int main() {
	test();
	return 0;
}