#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Encode.c"
#include "Decode.c"


////////ENCODE//////////

//calc sizeof img//
int size_img(FILE *fp1)

//write secret msg to .txt//
void secret_msg(FILE *fp2)

//calc sizeof msg//
int size_msg(FILE *fp2)

//copy .bmp header to output//
void copy_header(FILE *fp1, *fp3)

//transfer msg to output//
void transfer_msg(FILE *fp1, *fp2, *fp3)

//get bits message//
void msg_bits(char msg_byte, int bit)