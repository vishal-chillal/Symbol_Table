#include <stdio.h>
#include "struct.h"

int insert(litTab **ppHead,char *literal)
{
	litTab *pTemp,*pNwNode;
	pNwNode = (litTab*)malloc(sizeof(litTab));

	pNwNode->op2 = (char*)malloc(sizeof(char)*strlen(literal)+1);

	strcpy(pNwNode->op2,literal);
	pNwNode->next = NULL;
	pNwNode->hexVal = atoi(literal);
	printf("\t %d : %.8x\n",pNwNode->hexVal,pNwNode->hexVal);
	if(*ppHead == NULL)
	  {
	    *ppHead = pNwNode;
		return 0;
	  }
	pTemp = *ppHead;
	while(pTemp -> next != NULL)
	  pTemp = pTemp->next;
	pTemp -> next = pNwNode;

	return 0;
}
