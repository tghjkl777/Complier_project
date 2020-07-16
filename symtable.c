/*
* symtable.c
* Programmer: 1615022 ������, 1515069 ������, 1515033 �ۿ���
* Date: 6/ 04/ 2019
* Description:
main �Լ����� scanner�� ���� �ùٸ� identifier��� �ǴܵǾ���
token���� symbol table�� hash table�� �����ϴ� �۾�, �ؽ��ڵ� ��� ���� �����ϴ� �����Լ����� ����Ǿ� �ִ�. 

���� ������ �� symtable �� �ٸ� c ���α׷����� ident������ �о����� �̹� symtable������ �̹�
scanner.l ���� identifier������ �а� �̿� ���� �ؽ��ڵ� ���, �ؽ����̺� ����,�ؽ����̺� ������ �̷������  

.
void computeHashValue(int nextID, int nextFree)
symbol���� ASCII���� �������� �ؽð��� ����ϴ� �Լ�.
� symbol�� �ؽð��� symbol�� �����ϴ� ��� character�� ASCII�� �ջ��� hash
table ũ��� ���� ���� ��.

void lookupHT(int nextID, int hsValue):
� symbol�� �ؽð� ������ �ؽ� ���̺� �����Ϸ��� �� ��,
�̹� ������ symbol�� �ؽ����̺� �����ϰ� �ִ��� Ȯ���ϴ� �Լ�.
void addHT(int hsValue):
�ؽð��� �ؽ����̺� �����ϴ� �Լ�.
���� ���� �ٸ� symbol�� ���� �ؽð��� ���´ٸ� ���Ḯ��Ʈ�� �̿��ؼ� ����.

void PrintHStable() : �ؽ����̺� ����Լ� 
�ؽ����̺� ����� identifier�� �ؽ��ڵ尪��, �׵��� �Ӽ� �׸��� �� identifier�� �ִ� �ٹ�ȣ�� ����Ѵ�. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glob.h"
#include "tn.h"

#define STsize 1000
#define HTsize 1000

extern char *yytext;
extern int yyleng;

extern HTpointer HT[HTsize];
extern char ST[STsize];
extern int cLine;
extern int cErrors;
extern void printError(ERRORS);

// �ɺ����̺�, �ؽ����̺� ������ �ʿ��� ����
int nextid;
int nextfree;
int hashcode;
int found;

int foundIdx; // �ؽ����̺� Ž�� �ÿ� ã�� identifier�� �ɺ����̺����� ���� �ε���
ERRORS err; // ���� ���� ����

// �ؽð� ���
void ComputeHS(int nextID, int nextFree) {
	int i;
	int sum = 0;

	for (i = nextID; i < nextFree - 1; i++) {
		sum += (int)ST[i];
	}
	hashcode = sum % HTsize; // �������� hashCode�� �ؽð� ����
}

// �ؽ����̺� ���� �� ���ϰ� ���� ���θ� �ľ��ϰ� �׿� �°� ó��
void LookupHS(int nextID, int hsValue)
{
	int i, j;
	HTpointer target;
	found = 0;

	// �����Ǵ� �ؽð��� �̹� HT�� �ִ� ���
	if (HT[hsValue] != NULL) {
		target = HT[hsValue]; // ���� ������ ����

		while (target != NULL && found == 0) {
			found = 1;
			i = target->index;
			j = nextID;
			foundIdx = i; // �������� foundIdx�� ST �ε��� �� ����

			while (ST[i] != '\0' && ST[j] != '\0' && found == 1) { // identifier�� ���� character�� ��� ��ġ�ϴ��� �˻�
				if (ST[i] != ST[j]) // ���� ĳ���� �ٸ� ��� -> ã�� identifier �ƴ� ���
					found = 0;
				else { // ���� ĳ���� ���� ��� -> ����ؼ� ��� �ε����� ĳ���Ͱ� ��ġ�ϴ��� Ȯ��
					i++;
					j++;
				}
			}
			target = target->next; // ���Ḯ��Ʈ Ÿ�� �Ѿ�鼭 �ε��� Ž�� 
		}
	}
}

// �ؽ����̺� ��� �Լ�
void PrintHStable() 
{
	printf("\n\n[[  HASH TABLE  ]]\n");
	HTpointer here;
	int i, j;
	for(i=0; i<HTsize; i++){
		if (HT[i] != NULL) {
			here = HT[i];
			do {
				printf("Hash Code %d: (", i);
				for (j = here->index; ST[j] != '\0'; j++) {
					printf("%c", ST[j]);
				}
				printf(" : ");
				switch (here->type) {
				case 1:
					printf("integer scalar variable, line = %d)\n", here->linenum);
					break;
				case 2:
					printf("void scalar variable, line = %d)\n", here->linenum);
					break;
				case 3:
					printf("float scalar variable, line = %d)\n", here->linenum);
					break;
				case 4:
					printf("char scalar variable, line = %d)\n", here->linenum);
					break;
				case 5:
					printf("function name, line = %d)\n", here->linenum);
					break;
				case 6:
					printf("integer array variable, line = %d)\n", here->linenum);
					break;
				case 7:
					printf("float array variable, line = %d)\n", here->linenum);
					break;
				case 8:
					printf("char array variable, line = %d)\n", here->linenum);
					break;
				case 9:
					printf("function parameter, line = %d)\n", here->linenum);
					break;
				case 10:
					printf("not defined function name or parameter, line = %d)\n", here->linenum);
					break;
				
				}
				here = here->next;
			} while (here != NULL);
		}
	}
}

// �ؽ����̺� ����
void AddHT(int hsValue) {
	HTpointer newPtr = (HTpointer)malloc(sizeof(HT));
	
	// ���� �����ϴ� ���
	if (HT[hsValue] == NULL) {
		newPtr->type = 0;
		newPtr->index = nextid;
		newPtr->linenum = cLine; // �ٹ�ȣ �߰�
		newPtr->next = NULL;
	}
	// ��ġ�� �ؽð��� ���� �� �����ϴ� ��� -> ���Ḯ��Ʈ�� �� �տ� ����
	else {
		newPtr->type = 0;
		newPtr->index = nextid;
		newPtr->linenum = cLine; // �ٹ�ȣ �߰�
		newPtr->next = HT[hsValue];
	}
	HT[hsValue] = newPtr;
	look_id = newPtr;
}