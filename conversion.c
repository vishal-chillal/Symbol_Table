#include"struct.h"
int conversion(int address,char* inp,char* dataType,sysTab *pHead, FILE *fp)
{
	int i=0,j=0,flag =0, cnt=0;
	char *buff,*temp;
	buff=(char*)malloc(sizeof(char)*(strlen(inp))+1);
	temp=(char*)malloc(sizeof(char)*(strlen(inp))+1);
	if(buff == NULL)
		return 1;
	strcpy(buff,inp);

	fprintf(fp, "%.8X ", address);
	if(strcmp(pHead -> section,".bss")==0)
		fprintf(fp, "<res ");

	if(strcmp(dataType,"db")==0)
	{
		while(buff[i] !='\0' && i<strlen(buff))
		{
			//   ----   for printing the hex for string in the "".
			if(buff[i]== '\"')
				flag = flag+1;
			if(flag == 1)
			{
				if(buff[i]!='\"')
				{
					cnt ++;
					fprintf(fp, "%X",buff[i]);
				}
			}
			else if(buff[i]!='\"')
			{
				j=0;
				//      ----    printing the part after the " "
				while(buff[i]!=',' && i < strlen(buff))
				{
					temp[j]=buff[i];
					j++;
					i++;
				}
				temp[strlen(temp)]='\0';
				if(strlen(temp)!=0)
				{
					cnt ++;
					fprintf(fp, "%.2X",atoi(temp));
				}
			}
			i++;
		}
	}

	else if(strcmp(dataType,"dd")==0)
	{
		while(buff[i] !='\0' && i<strlen(buff))
		{
			j=0;
			//      ----    printing the part after the " "
			while(buff[i]!=',' && i < strlen(buff))
			{
				temp[j]=buff[i];
				j++;
				i++;
			}
			temp[strlen(temp)]='\0';
			fprintf(fp, "%.8X",atoi(temp));
			i++;
			cnt ++;
		}
		cnt = cnt*4;
	}

	//      ----    printing the part for bss section  ..... //
	else
	{

		while(buff[i]!=',' && i < strlen(buff))
		{
			temp[j]=buff[i];
			j++;
			i++;
		}
		temp[strlen(temp)]='\0';
		if(strlen(temp)!=0)
		{
			if(strcmp(dataType,"resd")==0)      	  //      ----    printing the part for resd
			{
				fprintf(fp, "%.8X",(atoi(temp)*4));
				cnt = (atoi(temp)*4);
			}
			else if(strcmp(dataType,"resw")==0)  	  //      ----    printing the part for resw
			{
				fprintf(fp, "%.8X",(atoi(temp)*2));
				cnt = (atoi(temp)*2);
			}
			else if(strcmp(dataType,"resb")==0)          //      ----    printing the part for resb
			{
				fprintf(fp, "%.8X",(atoi(temp)));
				cnt = (atoi(temp));
			}

		}
	}

	if(strcmp(pHead -> section,".bss")==0)
		fprintf(fp, ">");

	free(buff);
	free(temp);
	return cnt;
}

