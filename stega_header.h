#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encoder.c"
#include "decoder.c"


////////ENCODER//////////

//calc sizeof img//
int size_img(FILE *fp1);

//write secret msg to .txt//
void secret_msg(FILE *fp2);

//calc sizeof msg//
int size_msg(FILE *fp2);

//copy .bmp header to output//
void copy_header(FILE *fp1,FILE *fp3);

//transfer msg to output//
void transfer_msg(FILE *fp1,FILE *fp2,FILE *fp3); //int rest, int img_size

//get bits message//
int msg_bits(char byte, int bit);

////////DECODER//////////

//get msg from img//
void get_msg(FILE *fp1, FILE *fp3);
