#ifndef _GLOBAL_H
#define	_GLOBAL_H



#define SO_BASE 60
#define SO_ALTEZZA 20
#define MY_KEY_STR 65
#define MY_KEY_STRUCT 57

/*
 * Data structure of a matrix:
 *   - rows is the number of rows of the matrix
 *   - cols is the number of columns of the matrix
 *   - data is a pointer to the data (rows*cols)
 */



struct mat {
	char data[SO_ALTEZZA][SO_BASE];
	int rows;
	int cols;
	int pos[SO_ALTEZZA][SO_BASE];
};

//[atoi(getenv("SO_ALTEZZA"))][atoi(getenv("SO_BASE"))]

struct mat * mat_read_alloc();




void mat_print(const struct mat * m);




void mat_free(struct mat * in);
#endif
