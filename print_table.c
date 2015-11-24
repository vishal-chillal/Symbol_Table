#include"struct.h"

int print_table(sysTab **head, int flag)
{
	sysTab *temp;
	temp = *head;
	if(temp == NULL)
		return 0;
	FILE *fd;
	(*head)->lineNo = 0;

	if(flag == 0)
		fd = fopen("symbolTable.txt", "w");
	else
		fd = fopen("symbolTable.txt", "a");

	if(fd == NULL)
		return 0;

	while(temp != NULL)
	{
		fprintf(fd," %d\t|%.8X\t| %s\t| %s\t| %s\t| %s\n",temp->index,temp->lineNo,temp->name,temp->section,temp->val,temp->type);
		temp = temp->pNext;
	}

	fclose(fd);

	return 0;
}

int text_print_table(TsysTab **head)
{
	TsysTab *temp;
	temp = *head;
	if(temp == NULL)
		return 0;
	FILE *fd = fopen("symbolTable.txt", "a");

	if(fd == NULL)
		return 0;

	while(temp != NULL)
	{
		fprintf(fd," %d\t| %d\t\t| %s\t| %s\t| %d\t| %s\n",temp->index,temp->lineNo,temp->name,temp->section,temp->val,temp->type);
		temp = temp->pNext;
	}

	fclose(fd);

	return 0;
}

