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

/*
struct mat * mat_insert_flag_value(struct mat * in,int flag)
{
	unsigned int i, j;
	char * dato;
	int c_flag=-1;
	for(i=0; i<in->rows; i++) {
		for(j=0; j<in->cols; j++) {
			in->pos[i][j]=0;
			dato=in->data[j+i*in->cols];
			if(dato=="." && c_flag!=i && c_flag<flag-1){
			in->data[j+i*in->cols]="\u2690";
			in->pos[i][j]=1;
			++c_flag;
			}		
		}
	}
	return in;
}*/

/*
 char ** mat_insert_flag_value_shared(struct mat * in,int flag)
{
	unsigned int i, j;
	char * dato;
	int c_flag=-1;
	for(i=0; i<in->rows; i++) {
		for(j=0; j<in->cols; j++) {
			in->pos[i][j]=0;
			dato=in->data[j+i*in->cols];
			if(dato=="." && c_flag!=i && c_flag<flag-1){
			in->data[j+i*in->cols]="\u2690";
			in->pos[i][j]=1;
			++c_flag;
			}		
		}
	}
	return in->data;
}*/


void mat_print(const struct mat * m)
{


	
	for(int i=0; i<m->rows; i++) 
		for(int j=0; j<m->cols; j++){ 
			printf("%c",m->data[i][j]);
			
}
		
		printf("\n");
	
	
	
}
/*
void mat_print_value(const struct mat * m)
{
	unsigned int i, j;

	
	for(i=0; i<m->rows; i++) {
		for(j=0; j<m->cols; j++) {
			printf("%d",m->pos[j+i*m->cols]);
			

		}
		printf("\n");
	}
	
	
}*/

void  mat_fill_pos(struct mat * in)
{

	
	for(int i=0; i<in->rows; i++)
		for(int j=0; j<in->cols; j++){
			in->pos[i][j]=1;
		}
	
	
}


void mat_insert_data(struct mat * in)
{

	
	for(int i=0; i<in->rows; i++)
		for(int j=0; j<in->cols; j++){
			in->data[i][j]='4';
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
}

}


void mat_free(struct mat * in)
{
	/* First free the data of the matrix... */
	free(in->data);
	/* ...then the struct */
	free(in);
}
