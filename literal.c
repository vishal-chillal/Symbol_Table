#include "struct.h"

int createLiteralTable(litTab **ppHead,char filepath[],MNT **head)
{
	int i,j,flg = 0;
	FILE *fp;
	char *saveptr,input[100],*tempStr,*getNums;
	fp = fopen(filepath,"r");

	tempStr = (char *)malloc(sizeof(char)*100);

	// getting macro
	while(fgets(input,100,fp) != NULL)
	{ 
		tempStr = strtok_r(input," ",&saveptr);
		if(tempStr!=NULL)
		{
			if(strcmp(tempStr,"%macro") == 0)
			{
				getNums = NULL;
				MnTable(head,saveptr);
			}
			else if(strcmp(tempStr,"section")==0)
			{
				while(strcmp(input,"section .text")==0)
					fgets(input,100,fp);
				break;	
			}
		}
	}

	printMNT(*head);

	//starting from next line of section .text

	while(fgets(input,100,fp) != NULL){
		tempStr = strtok(input,"\n");
		tempStr = strtok_r(tempStr,",",&saveptr);
		if(tempStr!=NULL){
			j=0;
			getNums = (char *)malloc(sizeof(char)*100);
			for(i=0;i<strlen(saveptr);i++){
				if((saveptr[i] > 47) && (saveptr[i] < 58)){
					getNums[j] = saveptr[i];
					j++;
				}
				if((saveptr[i] == ';')||(saveptr[i] == ' ')||(saveptr[i] == '\n')||(saveptr[i] == '\t')){
					break;
				}
			}
			saveptr =NULL;
			if( getNums[0] !='\0')
			{
				insert(ppHead,getNums,flg); // call to linklist of lit_table
				flg = 1;
			}
			getNums = NULL;


		}
	}

	return 0;
}
