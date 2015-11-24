#include <stdio.h>
#include "struct.h"

int main(int argc, char **argv)
{
	FILE *fp, *fptr;
	char *input,*str1, *str2, *token, *subtoken, *type, *temp;
	char *saveptr1, *saveptr2, *buffer, *inputLine;
	int j, sectionIdentifier, count=0, i;
	sysTab *D_head, *B_head;
	TsysTab *T_head;
	D_head =B_head= NULL;
	T_head= NULL;
	litTab *litHead = NULL; //head of literal Table
	opcd *O_head;
	O_head=NULL;
	MnemonicNode *M_head;
	M_head=NULL;
	regNode *R_head;
	R_head=NULL;
	input = (char *) malloc(sizeof(char) * 70);

	fp=fopen(argv[1],"r");
	if(fp==NULL)
		printf("File Does Not Exist.");

	fptr=fopen("output.lst","w+");
	if(fptr==NULL)
		printf("Could not create lst file\n");

	////////////////////////////////////////////////////////
	//call to akkha opCode table generation without any parameters
	////////////////////////////////////////////////////////
	oP_Tab_main(&O_head); 

	createRg_Table(&R_head);
	createMn_Table(&M_head);
       	createLiteralTable(&litHead,argv[1]);

	//fprintf(fptr, "\n\n");
	while(!feof(fp))
	{
		while(fgets(input, 70, fp) != NULL)
		{
			if(input[0]!=';')
			{
				count++;
				str1=(char*)malloc(sizeof(char)*(strlen(input)+1));

				buffer=(char*)malloc(sizeof(char)*(strlen(input)+1));

				strcpy(str1,input);
				str1 = strtok(str1,";");

				if (str1 == NULL || (int)(strlen(str1)) <2)
				  break;
				str1[strlen(str1)-1]='\0';
				/////////////
				inputLine = (char*)malloc(sizeof(char)*(strlen(str1)));
				strcpy(inputLine,str1);
				fprintf(fptr, "\n%d %s \t \t \t \t",count,inputLine);
				token = strtok_r(str1, " \t", &saveptr2);
				if(token == NULL)
				  break;
				if (strcmp(token,"section")==0)
				{
					str2 = NULL;

					for (; ;str2 = NULL)
					{
						subtoken = strtok_r(str2, "\n", &saveptr2);
						if (subtoken == NULL)
							break;
						//////////

						if (strcmp(subtoken,".data")==0)
						{
							sectionIdentifier = 0;
							break;
						}

						else if (strcmp(subtoken,".bss")==0)
						{
							sectionIdentifier = 1;
							break;
						}

						else if (strcmp(subtoken,".text")==0)
						{
							sectionIdentifier = 2;
							break;
						}
					}
				}


				if(sectionIdentifier == 0 && strcmp(token,"section")!=0 && strcmp(token,"\n")!=0 && strcmp(token,"\t\n")!=0)
				{
					str2 = NULL;
					type=(char*)malloc(sizeof(char)*2);

					temp=strtok_r(str2," ",&saveptr2);
					strncpy(type,temp,2);
					type[2]='\0';
					if(strlen(temp)>2)
					{
						saveptr1=strtok_r(temp,"\n",&saveptr2);
						strncpy(buffer,&saveptr1[2],(strlen(saveptr1)-2));
					}
					else
					{
						str1= NULL;
						buffer=strtok_r(str1,"\n",&saveptr2);
					}
					if(checkRepeat(&D_head,token) == 0) 
						addEntry(&D_head,token,subtoken,buffer,type,count,fptr);
					else
					{	printf("ERROR: %d: %s label is already exist\n",count,token);
						return 1;
					}
				}

				else if(sectionIdentifier == 1 && strcmp(token,"section")!=0  && strcmp(token,"\n")!=0 && strcmp(token,"\t\n")!=0)
				{
					str1 = NULL;
					saveptr1 = strtok_r(str1, " ", &saveptr2);

					type = (char *)malloc(sizeof(char) * 5);

					strncpy(type, saveptr1, 4);

					buffer = strtok_r(str1,"\n", &saveptr2);

					if(checkRepeat(&B_head,token) == 0) 
						addEntry(&B_head,token,subtoken,buffer,type,count, fptr);
					else	
					{	printf("ERROR: %d: %s label is already exist\n",count,token);
						return 1;
					}	
				}
				
				else if(sectionIdentifier == 2 && strcmp(token,"section")!=0 && strcmp(token,"\n")!=0 && strcmp(token,"\t\n")!=0)
				{
					j=strlen(str1);

					while(j>=0)
					{
						if(str1[j]==':')
							break;
						else
							j--;
					}

					replaceWithOpcodes(inputLine,D_head,B_head,T_head,litHead,O_head,M_head,R_head, fptr);

					if(j >= 0)
					{
						token = strtok_r(str1, ":\t",&saveptr1);
						if(token != NULL)
						{
							if(checkRepeat_text(&T_head,token) == 0) 
								text_entry(&T_head,token,subtoken,0,"lable",count);
							else
							{	printf("ERROR: %d: %s label is already exist \n",count,token);
								return 1;
							}
						}
						if(strcmp(token,"main")==0)
							i = 0;
					}
					else
						i++;
				}
				
			}
		}	

		free(input);
		input = (char *) malloc(sizeof(char) * 70);
	}

	print_table(&D_head, 0);
	print_table(&B_head, 1);
	text_print_table(&T_head);
	fclose(fp);
	fclose(fptr);

	//literalTable function call
	fprintf(fptr, "\n");
	return 0;
}
