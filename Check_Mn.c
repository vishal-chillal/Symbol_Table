#include "struct.h"
int check_Mn(char *mneMonic,MnemonicNode *M_head)
{
   while(M_head != NULL)
    {       
      if(strcmp(M_head->MnemonicName,mneMonic)!=0 )
	return 0;
      M_head = M_head->next;
    }
  return 1;
}
