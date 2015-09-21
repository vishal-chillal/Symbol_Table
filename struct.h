#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct symbol_table
{
  int index,lineNo;
  char *name,*type,*section,*val;
  struct symbol_table *pNext;

}sysTab;

typedef struct text_symb_table
{
  int index,lineNo,val;
  char *name,*type,*section;
  struct text_symb_table *pNext;

}TsysTab;

typedef struct opcd
{
  char *mn,*op1,*op2,*opcode;
  struct opcd *pNext;
}opcd;

int oP_Tab_main();
int optable(opcd **ppHead,char *opcode,char *instr, char *op1,char *op2);
int prnt_opcd(opcd **ppHead);

int addEntry (sysTab **head,char *name,char *sec,char *val,char *sysType, int lineNo);
int print_table( sysTab **head);
int text_print_table(TsysTab **head);
int text_entry (TsysTab **head,char *name,char *sec,int val,char *sysType, int lineNo);

