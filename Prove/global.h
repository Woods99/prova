#ifndef _GLOBAL_H
#define	_GLOBAL_H


#define KEY_SOPS_RIS 64
#define SO_BASE 10
#define SO_ALTEZZA 5

#define MY_KEY_STRUCT 58
#define KEY_SOPS_RIS 64
#define KEY_GIOC_PED 57

#define ID_GIOCATORE_1	0
#define ID_GIOCATORE_2	1
#define INIT_GIOCATORE_1 2
#define INIT_GIOCATORE_2 2
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
	int c_letter;
	char lettere[];
};





struct mat * mat_read_alloc();




void mat_print(const struct mat * m);




void mat_free(struct mat * in);
#endif
