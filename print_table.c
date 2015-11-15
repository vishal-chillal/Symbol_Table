#include"struct.h"

int print_table(sysTab **head, int flag)
{
	sysTab *temp;
	(*head)->lineNo = 0;
	temp = *head;
	FILE *fd;

	if(flag == 0)
		fd = fopen("symbolTable.txt", "w");
	else
		fd = fopen("symbolTable.txt", "a");

	if(fd == NULL)
		return 0;

	while(temp != NULL)
	{
		fprintf(fd,"%.8X | %d\t| %s\t| %s\t| %s\t| %s\n",temp->lineNo,temp->index,temp->name,temp->section,temp->val,temp->type);
		temp = temp->pNext;
	}

	fclose(fd);

	return 0;
}

int text_print_table(TsysTab **head)
{
	TsysTab *temp;
	temp = *head;
	FILE *fd = fopen("symbolTable.txt", "a");

	if(fd == NULL)
		return 0;

	while(temp != NULL)
	{
		fprintf(fd,"%d\t | %d\t| %s\t| %s\t| %d\t| %s\n",temp->lineNo,temp->index,temp->name,temp->section,temp->val,temp->type);
		temp = temp->pNext;
	}

	fclose(fd);

	return 0;
}

