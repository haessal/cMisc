/*.......1.........2.........3.........4.........5.........6.........*/
/* Name        : chkEndian.c                                         */
/* Created on  : 2010/02/08                                          */
/* Author      : haessal                                             */
/* Version     :                                                     */
/* Copyright   : Copyright(C) 2010 haessal. All rights reserved.     */
/* Description : Check the endian is big or little for 64bit system. */
/*.......1.........2.........3.........4.........5.........6.........*/
#include <stdio.h>
typedef unsigned char  UC;
typedef unsigned short US;
typedef unsigned int   UL;
typedef unsigned long  UW;

int main(int argc, char *argv[])
{
	UW boxw = 0xFEDCBA9876543210;
	US boxs;

	boxs = *((US*)(&boxw));

	printf("uw:%d, ul:%d, us:%d, uc:%d\n",
			(int)sizeof(UW), (int)sizeof(UL), (int)sizeof(US), (int)sizeof(UC));
	printf("boxs:0x%x\n", boxs);

	return 0;
}
