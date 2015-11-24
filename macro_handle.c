#include "struct.h"
int MnTable(MNT **pHead,char *input)
{
	char *m_name, *m_num_args, *saveptr;
	MNT *newNode, *temp;
	int cnt = 2;

	m_name = strtok_r(input, " ", &saveptr);
	if(m_name == NULL)
		return 1;

	m_num_args = strtok_r(NULL, " ", &saveptr);
	m_num_args[strlen(m_num_args)] = '\0';
	if(m_num_args == NULL)
		return 1;

	newNode = (MNT *)malloc(sizeof(MNT));
	newNode->No = atoi(m_num_args);
	newNode->Macro_name = (char *)malloc(sizeof(char)*(strlen(m_name)+1));
	strcpy(newNode->Macro_name, m_name);
	newNode->pNext = NULL;

	if(*pHead == NULL)
	{
		newNode->macroNum = 1;
		*pHead = newNode;
	}
	else
	{
		temp = *pHead;
		while(temp->pNext != NULL)
		{
			cnt++;
			temp = temp->pNext;
		}
		newNode->macroNum = cnt;
		temp->pNext = newNode;
	}

	return 0;
}

int printMNT(MNT *pHead)
{
	while(pHead != NULL)
	{
		printf("%d: %s\t%d\n", pHead->macroNum, pHead->Macro_name, pHead->No);
		pHead = pHead->pNext;
	}

	return 0;
}
