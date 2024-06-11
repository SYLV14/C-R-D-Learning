
#include"contact.h"

void check_capacity(Contact* pc) {
	if (pc->sz == pc->capacity) {
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_MAX) * sizeof(PeoInfo));
		if (ptr == NULL) {
			perror("check_capacity::realloc");
			return;
		}
		pc->data = ptr;
		pc->capacity += INC_MAX;
	}
}

void LoadContact(Contact* pc) {
	FILE* pf = fopen("contact.txt", "rb");
	if (!pf) {
		perror("LoadContact");
		return;
	}
	PeoInfo temp = { 0 };
	while (fread(&temp, sizeof(PeoInfo), 1, pf)) {
		check_capacity(pc);
		pc->data[pc->sz] = temp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}


void InitContact(Contact* pc) {
	pc->sz = 0;
	PeoInfo* ptr = (PeoInfo*)calloc(DEFAULT_MAX, sizeof(PeoInfo));
	if (ptr == NULL) {
		perror("InitContact::calloc");
		return;
	}
	pc->data = ptr;
	pc->capacity = DEFAULT_MAX;
	LoadContact(pc);
}

void DestoryContact(Contact* pc) {
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
	pc = NULL;
}


void AddContact(Contact* pc) {
	assert(pc);
	check_capacity(pc);
	printf("请输入姓名：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->sz].addr);
	printf("请输入电话：");
	scanf("%s", pc->data[pc->sz].tele);
	printf("输入完成\n");
	pc->sz++;
}

int FindbyName(Contact* pc, char* del_name) {
	int i = 0;
	for (i = 0; i < pc->sz; i++) {
		if (strcmp(pc->data[i].name, del_name) == 0)
			return i;
	}
	return -1;
}
int is_empty(Contact* pc) {
	if (pc->sz == 0) {
		printf("通讯录为空\n");
		return 1;
	}
	return 0;
}
void DelContact(Contact* pc) {
	assert(pc);
	if (is_empty(pc))
		return;
	printf("请输入要删除的姓名：");
	char find_name[NAME_MAX];
	scanf("%s", find_name);
	int pos = FindbyName(pc, find_name);
	if (pos == -1) {
		printf("查无此人\n");
		return;
	}
	int i = 0;
	for (i = pos; i < pc->sz - 1; i++)
		pc->data[i] = pc->data[i + 1];
	pc->sz--;
	printf("删除完成\n");
}

void SearchContact(const Contact* pc) {
	assert(pc);
	if (is_empty(pc))
		return;
	printf("请输入要查询的姓名：");
	char find_name[NAME_MAX];
	scanf("%s", find_name);
	int pos = FindbyName(pc, find_name);
	if (pos == -1) {
		printf("查无此人\n");
		return;
	}
	printf("%-10s\t%-4s\t%-4s\t%-20s\t%-12s\n", "姓名", "年龄", "性别", "住址", "电话");
	printf("%-10s\t%-4d\t%-4s\t%-20s\t%-12s\n", pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].addr,
		pc->data[pos].tele);
	printf("查询完毕\n");
}

void ModifyContact(Contact* pc) {
	assert(pc);
	if (is_empty(pc))
		return;
	printf("请输入要修改的姓名：");
	char find_name[NAME_MAX];
	scanf("%s", find_name);
	int pos = FindbyName(pc, find_name);
	if (pos == -1) {
		printf("查无此人\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入性别：");
	scanf("%s", pc->data[pos].sex);
	printf("请输入地址：");
	scanf("%s", pc->data[pos].addr);
	printf("请输入电话：");
	scanf("%s", pc->data[pos].tele);
	printf("修改完成\n");
}

int cmp_name(const void* e1, const void* e2) {
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
int cmp_age(const void* e1, const void* e2) {
	return ((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age;
}
void SortContact(Contact* pc) {
	assert(pc);
	if (is_empty(pc))
		return;
	printf("排序方式:0.姓名 1.年龄\n");
	printf("选择排序方式:>");
	int way = 0;
	scanf("%d", &way);
	if (way == 0)
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), cmp_name);
	else
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), cmp_age);
	ShowContact(pc);
}

void ShowContact(const Contact* pc) {
	assert(pc);
	if (is_empty(pc))
		return;
	printf("%-10s\t%-4s\t%-4s\t%-20s\t%-12s\n", "姓名", "年龄", "性别", "住址", "电话");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
		printf("%-10s\t%-4d\t%-4s\t%-20s\t%-12s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr,
			pc->data[i].tele);
}

void SaveContact(const Contact* pc) {
	FILE* pf = fopen("contact.txt", "wb");
	if (!pf) {
		perror("SaveContact");
		return;
	}
	if ((fwrite(pc->data, sizeof(PeoInfo), pc->sz, pf)) == pc->sz)
		printf("保存成功\n");
	fclose(pf);
	pf = NULL;
}

