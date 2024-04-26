#pragma once

#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define SZ_MAX 100
#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12
#define DEFAULT_MAX 3
#define INC_MAX 2

typedef struct PeoInfo {
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];

}PeoInfo;
typedef struct Contact {
	PeoInfo* data;
	int sz;
	int capacity;
}Contact;

//��ʼ��
void InitContact(Contact* pc); 
//����
void DestoryContact(Contact* pc);
//����
void AddContact(Contact* pc);
//ɾ��
void DelContact(Contact* pc);
//��ѯ
void SearchContact(const Contact* pc);
//�޸�
void ModifyContact(Contact* pc);
//����
void SortContact(Contact* pc);
//��ӡ
void ShowContact(const Contact* pc);



