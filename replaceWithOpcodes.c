#include <stdio.h>
#include "struct.h"

int replaceWithOpcodes(char filepath[])
{
	FILE *fp;
	char *saveptr,input[100],*tempStr,*getNums,*inputLine;
	fp = fopen(filepath,"r");
	tempStr = (char *)malloc(sizeof(char)*100);
	inputLine = (char *)malloc(sizeof(char)*100);

	// getting till section .text
	while(fgets(input,100,fp) != NULL){ 
		tempStr = strtok(input," \t");
		if(tempStr!=NULL)
			if(strcmp(tempStr,"main:") == 0){
				//we have to handle main: line here (single line)
				break;
			}
	}

	//starting from next line of section .text
	getNums = NULL;
	while(fgets(input,100,fp) != NULL){
		inputLine = strtok_r(input," \t",&saveptr);
		if(inputLine == NULL)
			break;
		for(;;getNums=NULL)
		{		
			inputLine = strtok_r(getNums," \t",&saveptr);
			if(inputLine == NULL)
				break;
			//printf("%s  = %c",inputLine,inputLine[strlen(inputLine)-1]);
		}
	}
	return 0;
}
