#include "struct.h"

int text_entry(TsysTab **head,char *name,char *sec,int val,char *sysType,int lineNo)
{
	TsysTab *pNwnode,*pTemp;

	pNwnode=(TsysTab*)malloc(sizeof(sysTab));
	if(pNwnode == NULL)
		return 1;

	pNwnode->section = (char*)malloc(sizeof(char)*((strlen(sec)+1)));
	if(pNwnode->section == NULL)
		return 1;
	strcpy(pNwnode->section,sec);

	pNwnode->type = (char*)malloc(sizeof(char)*((strlen(sysType))+1));
	if(pNwnode->type == NULL)
		return 1;
	strcpy(pNwnode->type,sysType);

	pNwnode->name = (char*)malloc(sizeof(char)*((strlen(name))+1));
	if(pNwnode->name == NULL)
		return 1;
	strcpy(pNwnode->name,name);


	pNwnode -> val = val;
	  
	pNwnode->lineNo = lineNo;

	pNwnode ->pNext = NULL;
	if(*head == NULL)
	{
		pNwnode->index = 1;
		*head = pNwnode;
		return 0;
	}

	pTemp = *head;

	while(pTemp -> pNext != NULL)
		pTemp = pTemp->pNext;

	pTemp -> pNext = pNwnode;

	pNwnode -> index = pTemp -> index + 1;

	return 0;
}

