#include <stdio.h>
#include "struct.h"

int replaceWithOpcodes(char *input,sysTab *D_head,sysTab *B_head,TsysTab *T_head,litTab *L_head,opcd *O_head,MnemonicNode *M_head,regNode *R_head)
{
	char *saveptr,*tempStr,*inputLine,*mneMonic;
	tempStr = (char *)malloc(sizeof(char)*100);
	inputLine = (char *)malloc(sizeof(char)*100);

	// getting till section .text

	//starting from next line of section .text

	inputLine = strtok_r(input," \t",&saveptr);
	if(inputLine != NULL)
	{

		if(strcmp(inputLine,"extern") == 0 || strcmp(inputLine,"global") == 0)
			return 1;

		if(inputLine[strlen(inputLine)-1]==':')
		{
			inputLine = strtok_r(saveptr," \t",&saveptr);
			if(inputLine == NULL)
				return 1;
		}

		mneMonic = (char*)malloc(sizeof(char)*(strlen(inputLine)));
		strcpy(mneMonic,inputLine);

		//saveptr[strlen(saveptr)-1]='\0';
		//printf("\n%s\t%s\t%s\n", mneMonic, inputLine, saveptr);
		rePlacement(mneMonic,inputLine,saveptr,D_head,B_head,T_head,L_head,O_head,M_head,R_head);
	}

	return 0;
}


int rePlacement(char *mneMonic,char *inStr,char *op2,sysTab *D_head,sysTab *B_head,TsysTab *T_head,litTab *L_head,opcd *O_head,MnemonicNode *M_head,regNode *R_head)
{
	int i=0;
	char *tmp;
	char *op1,*saveptr;//*pTemp;
	//  pTemp = NULL;
	op1 = strtok_r(op2,",",&saveptr);
	if(op1 == NULL)
		return 1;
	//  prnt_opcd(&O_head);

	op2 = strtok_r(saveptr,", \t",&saveptr);
	if(op2 == NULL)
		return 0;
	// printf("%s :%s : %s \n", mneMonic, op1, op2);
	if(check_Mn(mneMonic, M_head) != 0)
		return 1;
	if(check_Rg(op1, R_head)!= 0)
		return 1;
	if(final_op_default(mneMonic, op1, op2, O_head) != 0)  
	{
		if(final_op_sec(mneMonic, op1, op2, D_head) != 0)
			if(final_op_sec(mneMonic, op1, op2, B_head) != 0)
				if(final_op_Lsec(mneMonic, op1, op2, L_head) != 0)
				//{
				//	if (op2!=NULL)
				//	{
				//		tmp = strtok_r(op2," [", &saveptr);
				//		if (tmp!=NULL)
				//		{
				//			if (strcmp(tmp,"dword"))
				//				i = 1;
				//			else if (strcmp(tmp,"byte"))
				//				i = 2;
				//			else if (strcmp(tmp,"word"))
				//				i = 3;
				//			switch(i)
				//			{
				//				case 1:
				//					printf("%s\t%s",tmp,saveptr);
				//					break;
				//				case 2:
				//					printf("%s\t%s",tmp,saveptr);
				//					break;
				//				case 3:
				//					printf("%s\t%s",tmp,saveptr);
				//					break;
				//				default:
				//					printf("default case %s\t%s",tmp,saveptr);
				//					break;
				//			}
				//		}
				//	}

				//}

		//printf("\n");
		return 1;
	}

	return 0;
}
