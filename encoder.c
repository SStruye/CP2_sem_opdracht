
//calc sizeof img//
int size_img(FILE *fp1)	
{
	int X, Y;
	
	fseek(fp1, 0x12, SEEK_SET);			//set seek to X pos
	fread(&X, sizeof(int), 1, fp1);		//read X pos
	fread(&Y, sizeof(int), 1, fp1);		//read Y pos
	fseek(fp1, 0L, SEEK_SET);			//set seek back to start
	
	return((X * Y * 3) / 8);
	
}

///////////////////////////////////////////////////////////////////////////

//write secret msg to .txt//
void secret_msg(FILE *fp2)
{
	char msg[1000];
	printf("\nWrite the message you want to encode: ");
	gets(msg);
	fputs(msg, fp2);
	fputs("*", fp2);
}

///////////////////////////////////////////////////////////////////////////

//calc sizeof msg//
int size_msg(FILE *fp2)
{
	int size = 0;
	fseek(fp2, 0L, SEEK_END); 	//seek end pos msg
	size = ftell(fp2);
	fseek(fp2, 0L, SEEK_SET);	//set seek back to start
	return size;
}

///////////////////////////////////////////////////////////////////////////

//copy .bmp header to output//
void copy_header(FILE *fp1,FILE *fp3)
{
	char temp;
	rewind(fp1);
	for(int i = 0;i < 54; i++)
	{
		temp = fgetc(fp1);
		fputc(temp,fp3);
	}
}

///////////////////////////////////////////////////////////////////////////

//get bits message//
int msg_bits(char byte, int bit)
{
	return((byte >> 8 - bit) & 1);
}

///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////

//transfer msg to output//
void transfer_msg(FILE *fp1,FILE *fp2,FILE *fp3)// int rest, int img_size
{
	int i;
	char img_buff = 0;
	char msg_buff = 0;
	int bit_msg;
	
	while((msg_buff = fgetc(fp2)) != EOF)		//while till end of msg
	{
		for(i = 1; i <= 8; i++)				//8 bits per char from msg
		{
			img_buff = fgetc(fp1);				//put current byte in buffer
			
			int check_lsb = (img_buff & 1);		//check if lsb from img byte is 1 or 0
			
			bit_msg = msg_bits(msg_buff, i);	//get current bit from msg
			
			if(check_lsb == bit_msg)			
			{
				fputc(img_buff, fp3);			//if equel copy img byte to output
			}
			else
			{
				if(check_lsb == 0)				
				{
					img_buff = (img_buff | 1); 	//if lsb == 0 => lsb = 1		
				}									   
				else
				{
					img_buff = (img_buff ^ 1); 	//if lsb == 1 => lsb = 0
				}
				fputc(img_buff, fp3);
			}
		}
	}
	fclose(fp2);
	
	
	while(!feof(fp1))
	{
		char tmp_cpy = fgetc(fp1);
		fputc(tmp_cpy,fp3);

	}
	printf("\n-------------------------------------------------------------------------------------\n");	
	printf("Secret message encrypted!");
	printf("\n-------------------------------------------------------------------------------------\n");
	printf("To decrypt message use: stegano -d -i output.bmp -o msg_out.txt ");
	printf("\n-------------------------------------------------------------------------------------\n");

}



///////////////////////////////////////////////////////////////////////////

//compile: gcc stega.c -o stegano
//execute: stegano -c -i input.bmp -s msg.txt -o output.bmp

///////////////////////////////////////////////////////////////////////////


int encoder(char *argv_1,char *argv_2,char *argv_3)
{
	FILE *fp1, *fp2, *fp3;
	
	//open image
	if((fp1 = fopen(argv_1, "r+b")) == NULL)
	{
		printf("could not open file  %s! Check if file is named 'input.bmp'", argv_1);
		return 1;
	}

	//calc sizeof img
	system("cls");
	int img_size = size_img(fp1);
	printf("\nMax characters storable in %s = %d \n", argv_1, img_size);
	
	//open .txt
	fp2 = fopen(argv_2, "w+");
	
	//write msg to .txt
	secret_msg(fp2);
	
	system("cls");
	//calc sizeof msg
	int msg_size = size_msg(fp2);
	printf("\nSize of secret msg = %d\n", msg_size);
	
	//compare sizes
	if(msg_size > img_size)
	{
		printf("\n!!Size of msg exceeds image size!! \n");
		return 1;
	}
	
	//int rest = img_size - 8*msg_size - 54;
	
	//create output file
	fp3 = fopen(argv_3, "wb");
	if(fp3 == NULL)
	{
		fprintf(stderr, "\n!!failed to create output file %s!!\n", argv_3);
		exit(1);
	}
	
	//copy header to output
	copy_header(fp1, fp3);
	
	//put msg in img
	transfer_msg(fp1, fp2, fp3); //rest, img_size
	fclose(fp1);
	fclose(fp3);
	
	return 0;
}
