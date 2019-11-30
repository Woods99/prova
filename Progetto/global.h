#ifndef _GLOBAL_H
#define	_GLOBAL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define MY_KEY_STR 62

	#define memoria_condivisa(MY_KEY_STR){\
	key = ftok("shmfile",MY_KEY_STR);\
	shmid = shmget(key,1024,0666|IPC_CREAT);\
	struct mat * m1 = (struct mat *) shmat(shmid,(void*)0,0);\
	m1=mat_read_alloc();\
	}


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
};



struct mat * mat_read_alloc();




void mat_print(const struct mat * m);




void mat_free(struct mat * in);



//int myPow(int x,int n);
#endif
