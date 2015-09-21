#include <stdio.h>
#include "struct.h"

int createLiteralTable(litTab **ppHead,char filepath[])
{
	int i,j;
	FILE *fp;
	char *saveptr,input[100],*tempStr,*getNums;
	fp = fopen(filepath,"r");
	tempStr = (char *)malloc(sizeof(char)*100);

// getting till section .text
	while(fgets(input,100,fp) != NULL){ 
		tempStr = strtok(input,"\n");
		if(tempStr!=NULL)
			if(strcmp(tempStr,"section .text") == 0){
			  break;
			}
	}
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
			if(strcmp(getNums,"\0")!=0)
			  insert(ppHead,getNums); // call to linklist of lit_table
			getNums = NULL;
			
		}
	}

	return 0;
}
