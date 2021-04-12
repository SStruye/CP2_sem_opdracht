#include <stdio.h>

int main() 
{
	FILE *fp;
	char msg[1000];
	
	printf("\nWrite the message you want to encode: ");
	gets(msg);
	
	fp = fopen("test.txt", "w");
	fputs(msg, fp);
	fclose(fp);

	return 0;
}