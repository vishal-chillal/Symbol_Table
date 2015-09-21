#include "struct.h"

int main()
{
	FILE *fp;
	char *input,*str1, *str2, *token, *subtoken, *type, *temp,*saveptr2, *buffer;
	int j, sectionIdentifier, count=0;
	opcd *pHead;

	pHead= NULL;

	input = (char *) malloc(sizeof(char) * 70);

	fp=fopen("myInput.text","r");

	if(fp==NULL)
		printf("File Does Not Exist.");
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
				/////////////
				input = strtok(str1, ";");
				token = strtok_r(input, " \t",&saveptr2);
				str2 = NULL;
				for (; ;str2 = NULL)
				  {
				    subtoken = strtok_r(str2, " \t", &saveptr2);
				    if (subtoken == NULL)
				      break;
				    if (sectionIdentifier >= 1);
				    {
				      str1 = strtok_r(str2, " \t", &saveptr2);
				      if (str1 == NULL)
					break;
				      buffer = strtok_r(str2, " \t", &saveptr2);
				      if (buffer == NULL)
					break;
				      j=strlen(buffer);

				      if(buffer[j-1]==':')
					buffer = strtok_r(str2, " \t", &saveptr2);
				      if (buffer == NULL)
					break;
				      type = strtok_r(str2, " ,\t", &saveptr2);
				      if (type == NULL)
					break;
				      temp = strtok_r(str2, " ,\t", &saveptr2);
				      if (temp == NULL)
					break;
				      
				      optable(&pHead,str1,buffer,type,temp);
				    }
				    str1=buffer=type=temp=NULL; 
				  }
				//	printf("\n");
			}
			
		}	
		
		free(input);
		input = (char *) malloc(sizeof(char) * 70);
	}

	prnt_opcd(&pHead);
	fclose(fp);
	return 0;
}
