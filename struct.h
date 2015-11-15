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
//structure for Mnemonic table
typedef struct Mnemonic
{
		char *MnemonicName;
		int value;
		struct Mnemonic *next;
}MnemonicNode;
//structure for registor table
typedef struct reg
{
		char *regName;
		struct reg *next;
}regNode;



int oP_Tab_main(opcd **O_head);
int optable(opcd **ppHead,char *opcode,char *instr, char *op1,char *op2);
int prnt_opcd(opcd **ppHead);

int addEntry (sysTab **head,char *name,char *sec,char *val,char *sysType, int lineNo);
int print_table( sysTab **head, int flag);
int text_print_table(TsysTab **head);
int text_entry (TsysTab **head,char *name,char *sec,int val,char *sysType, int lineNo);

int createLiteralTable(litTab **head,char filepath[]);
int insert(litTab **head,char *literal,int flg );

int checkRepeat(sysTab **pHead, char *name);
int checkRepeat_text(TsysTab **pHead, char *name);


//giving final opcode
int replaceWithOpcodes(char filepath[],sysTab *D_head,sysTab *B_head,TsysTab *T_head,litTab *L_head,opcd *O_head,MnemonicNode *M_head,regNode *R_head);

int rePlacement(char *mneMonic, char *inStr,char *op2, sysTab *D_head,sysTab *B_head,TsysTab *T_head,litTab *L_head,opcd *O_head,MnemonicNode *M_head,regNode *R_head);

int check_Rg(char *op1,regNode *R_head);
int check_Mn(char *mneMonic,MnemonicNode *M_head);
//op_printing
int final_op_default(char *mneMonic,char *op1,char *op2,opcd *O_head);
int final_op_Lsec(char *mneMonic,char *op1,char *op2,litTab *L_head);
int final_op_sec(char *mneMonic,char *op1,char *op2,sysTab *head);



//making of mnumonics and register table
int createMn_Table(MnemonicNode **head);
void display_mn(MnemonicNode *head);
int insert_mn(MnemonicNode **head,char *MnemonicName,int elt);

int createRg_Table(regNode **head);
void display_rg(regNode *head);
int insert_rg(regNode **head,char *regName);

//for conversion of data part
int conversion(int address,char* input, char* dataType,sysTab *head); 
