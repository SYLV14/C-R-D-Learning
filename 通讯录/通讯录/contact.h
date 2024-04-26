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

//初始化
void InitContact(Contact* pc); 
//销毁
void DestoryContact(Contact* pc);
//增加
void AddContact(Contact* pc);
//删除
void DelContact(Contact* pc);
//查询
void SearchContact(const Contact* pc);
//修改
void ModifyContact(Contact* pc);
//排序
void SortContact(Contact* pc);
//打印
void ShowContact(const Contact* pc);



