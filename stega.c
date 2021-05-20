#include stega_header.h
	
int main(int argc, char *argv[])
{
	switch(argc)
	{
		case 8	:	if(!strmcmp(argv[1],"-c"))
					{
						for(i = 2; i < 8; i++)
						{
							if(!strmcmp(argv[1],"-i"))
							{
								argv_2 = argv[i+1];
							}
							if(!strmcmp(argv[1],"-s"))
							{
								argv_3 = argv[i+1];
							}
							if(!strmcmp(argv[1],"-o"))
							{
								argv_4 = argv[i+1];
							}
						}
						encode(argv_2, argv_3, argv_4);
						break;
					}
		
		case 6	:	if(!strmcmp(argv[1],"-d"))
					{
						for(i = 2; i < 6; i++)
						{
							if(!strmcmp(argv[1],"-i"))
							{
								argv_2 = argv[i+1];
							}
							if(!strmcmp(argv[1],"-o"))
							{
								argv_4 = argv[i+1];
							}
						}
						decode(argv_2, argv_4);
						break;
					}
		default	:	printf("!!ERROR!!");	
	}
	return 0;
}	