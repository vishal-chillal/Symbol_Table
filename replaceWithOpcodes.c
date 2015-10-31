#include <stdio.h>
#include "struct.h"

int replaceWithOpcodes(char filepath[],sysTab *D_head,sysTab *B_head,TsysTab *T_head,litTab *L_head,opcd *O_head,MnemonicNode *M_head,regNode *R_head)
{
	FILE *fp;
	char *saveptr,input[100],*tempStr,*getNums,*inputLine,*mneMonic;
	fp = fopen(filepath,"r");
	tempStr = (char *)malloc(sizeof(char)*100);
	inputLine = (char *)malloc(sizeof(char)*100);

	// getting till section .text
	while(fgets(input,100,fp) != NULL){ 
		tempStr = strtok(input," \t");
		if(tempStr!=NULL)
			if(strcmp(tempStr,"extern") == 0){
				//we have to handle main: line here (single line)
				break;
			}
	}

	//starting from next line of section .text
	getNums = NULL;
	while(fgets(input,100,fp) != NULL){
	  tempStr = strtok(input,";");
	  printf("%s",tempStr);
	  if(tempStr == NULL)
	    break;
		inputLine = strtok_r(tempStr," \t",&saveptr);
		if(inputLine == NULL)
			break;
		
		if(inputLine[strlen(inputLine)-1]==':')
		  {
		    inputLine = strtok_r(saveptr," \t",&saveptr);
		    if(inputLine == NULL)
		      break;
		  }
		mneMonic = (char*)malloc(sizeof(char)*(strlen(inputLine)));
		strcpy(mneMonic,inputLine);
		for(;;getNums=NULL)
		{		
			inputLine = strtok_r(getNums,", \t",&saveptr);
			if(inputLine == NULL )
			  break;

			if(inputLine[strlen(inputLine)-1]=='\n')
			  inputLine[strlen(inputLine)-1]='\0';

			
			if(rePlacement(mneMonic,inputLine,saveptr,D_head,B_head,T_head,L_head,O_head,M_head,R_head) != 0)
			  return 1;
			
		}
	}
	return 0;
}


int rePlacement(char *mneMonic,char *inStr,char *op2,sysTab *D_head,sysTab *B_head,TsysTab *T_head,litTab *L_head,opcd *O_head,MnemonicNode *M_head,regNode *R_head)
{
  char *op1,*saveptr;
  op1 = strtok_r(inStr,",",&saveptr);
  if(op1 == NULL)
    return 1;
  //  prnt_opcd(&O_head);
  op2 = strtok_r(op2,", \t",&saveptr);
  printf("%s :%s : %s \n", mneMonic, op1, op2);
  if(check_Mn(mneMonic, M_head) != 0)
    return 1;
  if(check_Rg(op1, R_head)!= 0)
    return 1;
  if(final_op_default(mneMonic, op1, op2, O_head) != 0)    
    return 1;

  return 0;
  
}
  
