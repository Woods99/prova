#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "my_sem_lib.c"
#include "assegnazioni.c"

struct mat * mat_read_alloc()
{
	unsigned int i, j;
	struct mat * in;

	in = malloc(sizeof(*in));
	in->rows=SO_ALTEZZA;
	in->cols=SO_BASE;
	
	
	
	for(i=0; i<in->rows; i++) {
		for(j=0; j<in->cols; j++){
			in->pos[i][j]=1;
			in->data[i][j]='.';
		}	
	}
	return in;
}




void mat_print(const struct mat * m)
{


	printf("\n");
	for(int i=0; i<m->rows; i++){
		for(int j=0; j<m->cols; j++){ 
			printf("%c",m->data[i][j]);
		}
	printf("\n");
	}
	
	
}

void  mat_fill_pos(struct mat * in)
{

	
	for(int i=0; i<in->rows; i++)
		for(int j=0; j<in->cols; j++){
			in->pos[i][j]=1;
		}
	
	
}


void mat_insert_data(struct mat * in)
{
	
	printf("%d",in->rows);
	printf("%d",in->cols);
	
	for(int i=0; i<in->rows; i++){
		for(int j=0; j<in->cols; j++){
			in->data[i][j]='.';
		}
	}
	
}

void mat_insert_char(struct mat * in,char ch)
{
	
	printf("%d",in->rows);
	printf("%d",in->cols);
	int c=0;
	for(int i=0; i<in->rows && !c; i++){
		for(int j=0; j<in->cols && !c; j++){
			if(in->data[i][j]=='.'){
			in->data[i][j]=ch;
			c=1;
			}
		}
	}
	
}


void mat_insert_flag(struct mat * in)
{
	
	printf("%d",in->rows);
	printf("%d",in->cols);
	
	for(int i=0; i<in->rows; i++){
		for(int j=0; j<in->cols; j++){
			in->data[i][j]='~';
		}
	}
	
}

void mat_print_pos(struct mat * in)
{
	unsigned int i, j;
	printf("%d\n",in->rows);
	printf("%d\n",in->cols);	

	for(i=0; i<in->rows; i++) {
		for(j=0; j<in->cols; j++) {
			printf("%d",in->pos[i][j]);
			
		}
	printf("\n");
	}

}


void mat_free(struct mat * in)
{
	/* First free the data of the matrix... */
	free(in->data);
	/* ...then the struct */
	free(in);
}
