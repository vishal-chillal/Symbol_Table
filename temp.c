#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char *str;
	int num = 837839397, temp, count = 0;

	while(num > 1)
	{
		temp = num % 10;
		str[count] = '0' + temp;
		count++;
		num/=10;
	}

	str[count] = '\0';

	//	str = strrev(str);

	printf("%s",str);
	
	return 0;
}
