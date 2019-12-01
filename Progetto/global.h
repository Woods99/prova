#ifndef _GLOBAL_H
#define	_GLOBAL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define MY_KEY_STRUCT 58
#define KEY_GIOC_PED 57
#define KEY_SOPS_RIS 64

/*
 * Data structure of a matrix:
 *   - rows is the number of rows of the matrix
 *   - cols is the number of columns of the matrix
 *   - data is a pointer to the data (rows*cols)
 */

struct mat {
	char data[20][60];
	int rows;
	int cols;
	int pos[20][60];
	int c_letter;
	char lettere[];
};



struct mat * mat_read_alloc();




void mat_print(const struct mat * m);




void mat_free(struct mat * in);



//int myPow(int x,int n);
#endif
