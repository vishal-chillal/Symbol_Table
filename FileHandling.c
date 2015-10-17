#include <stdio.h>
#include "struct.h"

int main(int argc, char **argv)
{
	FILE *fp;
	char *input,*str1, *str2, *token, *subtoken, *type, *temp;
	char *saveptr1, *saveptr2, *buffer;
	int j, sectionIdentifier, count=0, i;
	sysTab *D_head, *B_head;
	TsysTab *T_head;
	//	litTab *lit_Tab_Head = NULL;
	D_head =B_head= NULL;
	T_head= NULL;
	litTab *litHead = NULL; //head of literal Table
	input = (char *) malloc(sizeof(char) * 70);

	fp=fopen(argv[1],"r");

	if(fp==NULL)
		printf("File Does Not Exist.");
	////////////////////////////////////////////////////////
	//oP_Tab_main(); //call to akkha opCode table generation without any parameters
	printf("\n\n ");
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

				if (str1 == NULL)
					break;
				/////////////
	     
				token = strtok_r(str1, " \t", &saveptr2);

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
						addEntry(&D_head,token,subtoken,buffer,type,count);
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
						addEntry(&B_head,token,subtoken,buffer,type,count);
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

					if(j >= 0)
					{			   
						token = strtok_r(str1, ":\t",&saveptr1);
						if(token != NULL)
						{
							//if(checkRepeat(&T_head,token) == 0) 
								text_entry(&T_head,token,subtoken,0,"lable",count);
							//else
							//{	printf("ERROR: %d: %s label is already exist \n",count,token);
								//return 1;
							//}
						}
						if(strcmp(token,"main")==0)
							i = 0;
					}
					else
					{
						i++;

					}

				}
			}
		}	

		free(input);
		input = (char *) malloc(sizeof(char) * 70);
	}

	print_table(&D_head);
	print_table(&B_head);
	text_print_table(&T_head);
	fclose(fp);

	//literalTable function call
       	createLiteralTable(&litHead,argv[1]);
	printf("\n\n");	
	//call to replace with Opcodes 
	replaceWithOpcodes(argv[1]);	
	return 0;
}
