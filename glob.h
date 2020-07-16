/*
* glob.h
* Programmer: 1615022 ������, 1515069 ������, 1515033 �ۿ���
* Date: 6/ 04/ 2019
* Description:
* �ڵ� ���࿡ �ʿ��� �پ��� global �������� �����Ѵ�. 
* �ɹ� ���̺�� ��� ���̺� �ʿ��� ����
* ����üũ�� ���� ���� Ÿ�� 
* �������� , �� �ѹ� ����
* �ؽ����̺� ����Ǵ� ����ü ����, ���������� �ٸ��� ����� ��ġ�� ���� �ѹ���, �Ӽ��� ����ȴ�.
* �ļ����� ������ �����ϱ� ���� ������̺� ����ü ������ ���� 
*�ļ����� ���� Ÿ�� ������ ���� ����
*
*/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#define STsize 1000 //size of string table
#define HTsize 1000	//size of hash table

// ���� Ÿ��
enum ERRORS { noErr, STOverflow, longID, falseID, 
			wrong_st, wrong_funcdef, nobrace, nosemi, nobracket, nocomma, notDefinedError
			}; 
typedef enum errors ERRORS;

int cErrors; // �߻��� ���� ����
int cLine;	 // �ؽ�Ʈ �� ��ȣ

typedef struct HTentry* HTpointer;

typedef struct HTentry {
	int index; // HT�� ������ identifier�� ST������ ù �ε���
	int linenum; // ����� �� ��ȣ
	HTpointer next; // ���� ��ġ�� ����Ŵ
	int type; // ���� Ÿ��
} HTentry;

HTpointer HT[HTsize];
char ST[STsize];

HTpointer look_id; // ���� ID
HTpointer look_tmp;  // ������ ���� ������

// �ɺ����̺�, �ؽ����̺� ���� ����
int nextid;
int nextfree;
int hashcode;
int found;

// �ļ����� ���� Ÿ�� ������ ���� ����
int type_int;
int type_void;
int type_float;
int type_char;