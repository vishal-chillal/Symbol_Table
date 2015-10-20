#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct for only bss and data section  
typedef struct symbol_table
{
  int index,lineNo;
  char *name,*type,*section,*val;
  struct symbol_table *pNext;

}sysTab;

// sepearate structure symbol table for text section symbol table
typedef struct text_symb_table
{
  int index,lineNo,val;
  char *name,*type,*section;
  struct text_symb_table *pNext;

}TsysTab;

//structure for opCode table 
typedef struct opcd
{
  char *mn,*op1,*op2,*opcode;
  struct opcd *pNext;
}opcd;

//structure for literal table having three values
typedef struct literal_table{
	char *op2;
	int hexVal;
	struct literal_table *next;
}litTab;


int oP_Tab_main();
int optable(opcd **ppHead,char *opcode,char *instr, char *op1,char *op2);
int prnt_opcd(opcd **ppHead);

int addEntry (sysTab **head,char *name,char *sec,char *val,char *sysType, int lineNo);
int print_table( sysTab **head);
int text_print_table(TsysTab **head);
int text_entry (TsysTab **head,char *name,char *sec,int val,char *sysType, int lineNo);

int createLiteralTable(litTab **head,char filepath[]);
int insert(litTab **head,char *literal );

int checkRepeat(sysTab **pHead, char *name);
int checkRepeat_text(TsysTab **pHead, char *name);

int replaceWithOpcodes(char filepath[]);

//for conversion of data part
int conversion(char* input, char* dataType); 
