
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
	printf("������������");
	scanf("%s", pc->data[pc->sz].name);
	printf("���������䣺");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�");
	scanf("%s", pc->data[pc->sz].sex);
	printf("�������ַ��");
	scanf("%s", pc->data[pc->sz].addr);
	printf("������绰��");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������\n");
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
		printf("ͨѶ¼Ϊ��\n");
		return 1;
	}
	return 0;
}
void DelContact(Contact* pc) {
	assert(pc);
	if (is_empty(pc))
		return;
	printf("������Ҫɾ����������");
	char find_name[NAME_MAX];
	scanf("%s", find_name);
	int pos = FindbyName(pc, find_name);
	if (pos == -1) {
		printf("���޴���\n");
		return;
	}
	int i = 0;
	for (i = pos; i < pc->sz - 1; i++)
		pc->data[i] = pc->data[i + 1];
	pc->sz--;
	printf("ɾ�����\n");
}

void SearchContact(const Contact* pc) {
	assert(pc);
	if (is_empty(pc))
		return;
	printf("������Ҫ��ѯ��������");
	char find_name[NAME_MAX];
	scanf("%s", find_name);
	int pos = FindbyName(pc, find_name);
	if (pos == -1) {
		printf("���޴���\n");
		return;
	}
	printf("%-10s\t%-4s\t%-4s\t%-20s\t%-12s\n", "����", "����", "�Ա�", "סַ", "�绰");
	printf("%-10s\t%-4d\t%-4s\t%-20s\t%-12s\n", pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].addr,
		pc->data[pos].tele);
	printf("��ѯ���\n");
}

void ModifyContact(Contact* pc) {
	assert(pc);
	if (is_empty(pc))
		return;
	printf("������Ҫ�޸ĵ�������");
	char find_name[NAME_MAX];
	scanf("%s", find_name);
	int pos = FindbyName(pc, find_name);
	if (pos == -1) {
		printf("���޴���\n");
		return;
	}
	printf("������������");
	scanf("%s", pc->data[pos].name);
	printf("���������䣺");
	scanf("%d", &(pc->data[pos].age));
	printf("�������Ա�");
	scanf("%s", pc->data[pos].sex);
	printf("�������ַ��");
	scanf("%s", pc->data[pos].addr);
	printf("������绰��");
	scanf("%s", pc->data[pos].tele);
	printf("�޸����\n");
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
	printf("����ʽ:0.���� 1.����\n");
	printf("ѡ������ʽ:>");
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
	printf("%-10s\t%-4s\t%-4s\t%-20s\t%-12s\n", "����", "����", "�Ա�", "סַ", "�绰");
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
		printf("����ɹ�\n");
	fclose(pf);
	pf = NULL;
}

