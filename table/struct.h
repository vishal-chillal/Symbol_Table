#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct opcd
{
  char *mn,*op1,*op2,*opcode;
  struct opcd *pNext;
}opcd;

int optable(opcd **ppHead,char *opcode,char *instr, char *op1,char *op2);
int prnt_opcd(opcd **ppHead);
