#include <stdio.h>

int main() 
{
	FILE *fp_txt;
	char msg[1000];
	
	printf("\nWrite the message you want to encode: ");
	gets(msg);
	
	fp_txt = fopen("test.txt", "w");
	fputs(msg, fp_txt);
	fputs("*", fp_txt);
	fclose(fp_txt);

	return 0;
}