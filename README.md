# CP2 semester assingment: Steganography

## Description

This program can be used to encrypt a message in a .bmp image. It can also be used too extract the message out of the image.
The program is written in C and is executeable in command prompt.

### Executing program

First download the zip file and compile it with the command line: " gcc stega.c -o stegano ".

If you want to encrypt a message use the command line: " stegano -c -i input.bmp -s msg.txt -o output.bmp ".
Make sure your input image file is named "input.bmp".

To decrypt the message use the command line: " stegano -d -i output.bmp -o msg_out.txt ".
the message will be display in the command prompt and will also be stored in a .txt file called "msg_out.txt".

## Summary

### COMPILE: "gcc stega.c -o stegano"
### ENCRYPT: "stegano -c -i input.bmp -s msg.txt -o output.bmp"
### DECRYPT: "stegano -d -i output.bmp -o msg_out.txt"
