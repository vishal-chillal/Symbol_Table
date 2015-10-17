#include"struct.h"
int conversion(char* inp,int dataType)
{
  int i=0,j=0,flag =0;
  char *buff,*temp;
  buff=(char*)malloc(sizeof(char)*(strlen(inp))+1);
  temp=(char*)malloc(sizeof(char)*(strlen(inp))+1);
  if(buff == NULL)
    return 1;
  strcpy(buff,inp);
  if(dataType ==0)
    {
      while(buff[i] !='\0' && i<strlen(buff))
	{
	  //   ----   for printing the hex for string in the "".
	  if(buff[i]== '\"')
	    flag = flag+1;
	  if(flag == 1)
	    {
	      if(buff[i]!='\"')
	  	printf("%X",buff[i]);
	    }
	  else
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
		printf("\t %.2X",atoi(temp));
	    }
	  i++;
	}
    }
  
  else
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
	  if(strlen(temp)!=0)
	    printf("\t %8X",atoi(temp));
	  i++;
	}
    }
  printf("\n");
  return 0;
}

