#include "struct.h"

int checkRepeat(sysTab **pHead, char *name)
{
	sysTab *temp;
	temp = *pHead;

	//printf("name is %s",name);
	//printf("Node name is %s", temp->name);

	while(temp != NULL)
	{
		if(strcmp(temp->name,name)==0) 
			return 1;
		else 
			temp = temp->pNext;
	}
	return 0;
}
