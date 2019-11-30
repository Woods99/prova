#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "c_var.c"




struct mat * mat_read_alloc()
{

	struct mat * in;
	char * get_env;
	unsigned int i, j;
	int c_altezza=0;
	int c_base=0;
	int sum=0;	
	
	if((getenv("SO_ALTEZZA"))==NULL)
	fprintf(stderr,"Errore variabile d'ambiente SO_ALTEZZA non presente\n");
	else {
		get_env=getenv("SO_ALTEZZA");
		c_altezza=mycVar(get_env,c_altezza);
	}


	if((getenv("SO_BASE"))==NULL)
	fprintf(stderr,"Errore variabile d'ambiente SO_BASE non presente\n");
	else {
		get_env=getenv("SO_BASE");
		c_base=mycVar(get_env,c_base);
	}


	in = malloc(sizeof(*in));
	in->rows=c_altezza;
	in->cols=c_base;
	
	

	
	for(i=0; i<in->rows; i++) {
		for(j=0; j<in->cols; j++){ 
			in->data[i][j]='.';
			
	}
	}

	return in;
}


struct mat * mat_insert_flag_value(struct mat * in,int flag)
{
	unsigned int i, j;
//	char * dato;
	int c_flag=-1;
	int score=0;	

	if((getenv("SO_ROUND_SCORE"))==NULL)
	fprintf(stderr, "Errore variabile d'ambiente SO_ROUND_SCORE non presente\n");
	else{
	score=atoi(getenv("SO_ROUND_SCORE"));
	}	
	printf("%d\n",score);	

	for(i=0; i<in->rows; i++) {
		for(j=0; j<in->cols; j++) {
//			dato=in->data[j+i*in->cols];
			if(in->data[i][j]=='.' && c_flag!=i && c_flag<flag-1){
			in->data[i][j]='~';
			in->pos[i][j]=(score/flag);
			++c_flag;
			}		
		}
	}
	return in;
}

void mat_print(const struct mat * m)
{	
	unsigned int i, j;
	char * get_env;
	
	for(i=0; i<m->rows; i++) {
		for(j=0; j<m->cols; j++) {
			printf("%c",m->data[i][j]);
			

		}
		printf("\n");
	}
	
	
}

void mat_print_value(const struct mat * m)
{
	unsigned int i, j;

	
	for(i=0; i<m->rows; i++) {
		for(j=0; j<m->cols; j++) {
			printf("%d",m->pos[i][j]);
			

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




