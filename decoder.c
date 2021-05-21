
///////////////////////////////////////////////////////////////////////////

void get_msg(FILE *fp1, FILE *fp3)
{
	int buff =0;
	int temp, bit_msg;
	char out_temp[1000];
	char output[1000];
	int x = 0;
	int i =0;
	
	while(output[x] != '*')
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
				break;
			}
			output[x] = out_temp[x];
			putc(buff, fp3);
			x++;
			i = 0;
			buff = 0;
		}
	}
	printf("\nThe secret message is: %s\n",output);
}

///////////////////////////////////////////////////////////////////////////

//compile: gcc stega.c -o stegano
//execute: stegano -d -i output.bmp -o msg_out.txt

///////////////////////////////////////////////////////////////////////////

int decoder(char *argv_1,char *argv_3)
{
	FILE *fp1, *fp3;
	
	//open image
	if((fp1 = fopen(argv_1, "rb")) == NULL)
	{
		printf("could not open file %s", argv_1);
		return 1;
	}
	
	//skip header
	fseek(fp1,54 ,SEEK_SET);
	
	//open .txt 
	fp3 = fopen(argv_3, "wb");
	if(fp3 == NULL)
	{
		fprintf(stderr, "\n!!failed to create output file %s!!\n", argv_3);
		exit(1);
	}
	
	//get txt from file
	get_msg(fp1,fp3);
	
	fclose (fp1);
	fclose (fp3);
	return 0;
}