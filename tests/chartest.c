#include <stdio.h>

int main() 
{
	char i[] = "101100";
	
	i = (i | 1);
	printf("= %s", i);
	return 0;
}