#include "struct.h"
int check_Rg(char *op1,regNode *R_head)
{
  //  MnemonicNode *pTemp;
  //pTemp = M_head;
  printf("%s \t %s ",op1,R_head->regName);
  while(strcmp(R_head->regName,op1)!=0 )
    {       
      R_head = R_head->next;
      if(R_head == NULL)
	{
	  printf("\n bingo\n");
	  break;
	}
    }
  return 1;
}

  

