#include "struct.h"
int check_Mn(char *mneMonic,MnemonicNode *M_head)
{
  //  MnemonicNode *pTemp;
  //pTemp = M_head;
  printf("%s \t %s ",mneMonic,M_head->MnemonicName);
  while(strcmp(M_head->MnemonicName,mneMonic)!=0 )
    {       
      M_head = M_head->next;
      if(M_head == NULL)
	{
	  printf("\n bingo\n");
	  break;
	}
    }
  return 1;
}
