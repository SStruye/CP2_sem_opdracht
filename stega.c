#include "stega_header.h"
	
int main(int argc, char *argv[])
{
	int i;
	char *argv_1, *argv_2, *argv_3;
	
	switch(argc)
	{
		case 8	:	if(!strcmp(argv[1],"-c"))
					{
						for(i = 2; i < 8; i++)
						{
							if(!strcmp(argv[i],"-i"))
							{
								argv_1 = argv[i+1];
							}
							if(!strcmp(argv[i],"-s"))
							{
								argv_2 = argv[i+1];
							}
							if(!strcmp(argv[i],"-o"))
							{
								argv_3 = argv[i+1];
							}
						}
						encoder(argv_1, argv_2, argv_3);
						break;
					}
		
		case 6	:	if(!strcmp(argv[1],"-d"))
					{
						for(i = 2; i < 6; i++)
						{
							if(!strcmp(argv[i],"-i"))
							{
								argv_1 = argv[i+1];
							}
							if(!strcmp(argv[i],"-o"))
							{
								argv_3 = argv[i+1];
							}
						}
						decoder(argv_1, argv_3);
						break;
					}
		default	:	system("cls");
					printf("\n-------------------------------------------------------------------------------------\n");
					printf("|                                  !!WRONG COMMANDS!!                               |\n");
					printf("-------------------------------------------------------------------------------------\n");
					printf("|Too Encrypt a secret message type: stegano -c -i input.bmp -s msg.txt -o output.bmp|\n");
					printf("|Too Decrypt a secret message type: stegano -d -i output.bmp -o msg_out.txt         |\n");
					printf("-------------------------------------------------------------------------------------\n");
					printf("|Make sure your input image file is named 'input.bmp'!                              |\n");
					printf("-------------------------------------------------------------------------------------\n");
	}				
	return 0;
}	