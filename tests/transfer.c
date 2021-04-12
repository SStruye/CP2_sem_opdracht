#include <stdio.h>

int main() 
{
	FILE *fp, *fp3;
	
	
	fp = fopen("test.bmp", "r+");
	fp3 = fopen("out.bmp", "w+");
	
	int i, c = 0;
	char tmp_cpy;
	rewind(fp);	//Goes back to the beginning of the file
	for(i = 0;i < 54; i++)
	{
		tmp_cpy = fgetc(fp);
		fputc(tmp_cpy,fp3);
		c++;
	}
	
	
	fclose(fp);
	fclose(fp3);
	
	return 0;
}