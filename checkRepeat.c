#include "struct.h"

int checkRepeat(sysTab **pHead, char *name)
{
	sysTab *temp;
	temp = *pHead;

	while(temp != NULL)
	{
		if(strcmp(temp->name,name)==0) 
			return 1;
		else 
			temp = temp->pNext;
	}
	return 0;
}


int checkRepeat_text(TsysTab **pHead, char *name)
{
	TsysTab *temp;
	temp = *pHead;

	while(temp != NULL)
	{
		if(strcmp(temp->name,name)==0) 
			return 1;
		else 
			temp = temp->pNext;
	}
	return 0;
}
