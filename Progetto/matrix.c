#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "c_var.c"
#include "assegnazioni.c"




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




