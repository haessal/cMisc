/*.......1.........2.........3.........4.........5.........6.........*/
/* Name        : getASIN.c                                           */
/* Created on  : 2009/05/05                                          */
/* Author      : haessal                                             */
/* Version     :                                                     */
/* Copyright   : Copyright(C) 2009 haessal. All rights reserved.     */
/* Description : Search ASIN with "/dp/" eye catch.                  */
/*.......1.........2.........3.........4.........5.........6.........*/

#include <stdio.h>
#include <stdlib.h>
#define   S_START      0
#define   S_FstSL      1
#define   S_Cd         2
#define   S_Cp         3
#define   S_SecSL      4

int main(int argc, char *argv[])
{
    FILE *fp;
    int chcnt = 0;
    int status = S_START;
    unsigned char ch[1] = {'\0'};

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        printf("file open error!\n");
        exit(EXIT_FAILURE);
    }

    while ( fread(ch, 1, 1, fp) > 0 ) {
        switch (status) {
        case S_START:
            if (ch[0] == '/') {
                status = S_FstSL;
            } else {
                status = S_START;
            }
            break;
        case S_FstSL:
            if (ch[0] == 'd') {
                status = S_Cd;
            } else if (ch[0] == '/'){
                status = S_FstSL;
            } else {
                status = S_START;
            }
            break;
        case S_Cd:
            if (ch[0] == 'p') {
                status = S_Cp;
            } else if (ch[0] == '/'){
                status = S_FstSL;
            } else {
                status = S_START;
            }
            break;
        case S_Cp:
            if (ch[0] == '/') {
                status = S_SecSL;
            } else {
                status = S_START;
            }
            break;
        case S_SecSL:
            if (ch[0] == '%') {
                printf("\n");
                status = S_START;
            } else {
                printf("%c", ch[0]);
                status = S_SecSL;
            }
            break;
        default:
            fclose(fp);
            exit(EXIT_FAILURE);
            break;
        }
        /* output for debug */
        if (chcnt % 16 ==0) { fprintf(stderr, "a:%08x ", chcnt); }
        fprintf(stderr, "%02x ", ch[0]);
        chcnt++;
        if (chcnt % 8   ==0) { fprintf(stderr, " ");    }
        if (chcnt % 16 ==0) { fprintf(stderr, "\n"); }
    }
    printf("OK\n");
    fclose(fp);
}
