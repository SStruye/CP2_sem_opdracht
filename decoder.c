
///////////////////////////////////////////////////////////////////////////

//extract msg//
void get_msg(FILE *fp1, FILE *fp3)
{
	int buff =0;
	int temp, bit_msg;
	unsigned char out_temp[1000] = {0};
	unsigned char output[1000] = {0};
	int x = 0;
	int i =0;
	
	while(out_temp[x] != '*')
	{
		i++;
		temp = fgetc(fp1);
		bit_msg = (temp & 1);
		
		if(bit_msg)
		{
			buff = (buff << 1) | 1;
		}
		else
		{
			buff = buff << 1;
		}
		if(i == 8)
		{
			out_temp[x] = buff;
			
			if(out_temp[x] == '*')
			{
				buff = 0;
				break;
			}
			else
			{
				putc(buff, fp3);
				buff = 0;
				output[x] = out_temp[x];
				x++;
				i = 0;
			}
		}
	}
	system("cls");
	printf("\n-------------------------------------------------------------------------------------\n");
	printf("The secret message is: %s \n",output);
	printf("\nThe message can be found in the file named msg_out.txt!\n");
	printf("-------------------------------------------------------------------------------------\n");
}

///////////////////////////////////////////////////////////////////////////

//compile: gcc stega.c -o stegano
//execute: stegano -d -i output.bmp -o msg_out.txt

///////////////////////////////////////////////////////////////////////////

int decoder(char *argv_1,char *argv_3)
{
	FILE *fp1, *fp3;
	
	//open image
	if((fp1 = fopen(argv_1, "r+b")) == NULL)
	{
		printf("could not open file %s! check if file is named 'output.bmp'!!", argv_1);
		return 1;
	}
	
	//skip header
	fseek(fp1,54 ,SEEK_SET);
	
	//open .txt 
	fp3 = fopen(argv_3, "wb");
	if(fp3 == NULL)
	{
		printf("\n!!failed to create output file %s!!\n", argv_3);
		return 1;
	}
	
	//get txt from file
	get_msg(fp1,fp3);
	
	fclose (fp1);
	fclose (fp3);
	return 0;
}