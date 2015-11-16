#include"struct.h"
int final_op_default(char *mneMonic,char *op1,char *op2,opcd *O_head, FILE *fp)
{
	//  printf(" %d \t %d \t %d \n",strlen(mneMonic),strlen(op1),strlen(op2));
	while(O_head != NULL)
	{
		//  printf("%s|%s",op2,O_head->op2);
		if(strcmp(mneMonic,O_head->mn)==0)
			if((strcmp(op1,O_head->op1)==0) && (strcmp(op2,O_head->op2)==0)) 
			{	
				fprintf(fp, " %s ",O_head->opcode);
				return 0;
			}

		O_head = O_head->pNext;
	}

	return 1;
}

int final_op_sec(char *mneMonic,char *op1,char *op2,sysTab *pHead, FILE *fp)
{
	while(pHead != NULL)
	{
		if(strcmp(op2,pHead->name)==0)
		{
			fprintf(fp, "[%.8X]",pHead->lineNo);
			return 0;
		}
		else
			pHead = pHead->pNext;
	}
	return 1;
}


int final_op_Lsec(char *mneMonic,char *op1,char *op2,litTab *pHead, FILE *fp)
{
	while(pHead != NULL)
	{
		if(strcmp(op2,pHead->op2)==0)
		{
			fprintf(fp, "[%.8X]",pHead->hexVal);
			return 0;
		}
		else
			pHead = pHead->next;
	}
	return 1;
}

