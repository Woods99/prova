#include <stdio.h>
#include <stdlib.h>
#include <time.h> 



int mycFlag(int n_flag_min,int n_flag_max){
	int c_bandierine=0;
	while(c_bandierine==0){
		c_bandierine=rand()%n_flag_min;
		c_bandierine+=n_flag_min;
		if(c_bandierine>n_flag_max)
		c_bandierine=0;
	}
	printf("bandierine %d\n",c_bandierine);
	return c_bandierine;
}

struct mat * myfillFlag(struct mat * m1,int flag){
	int c_flag=0;
	char * dato;
	int c_i=-1;
	for(int i=0; i<m1->rows; i++) {
		
		for(int j=0; j<m1->cols; j++) {
			dato=m1->data[j+i*m1->cols];
			if(c_flag<flag && c_i!=i && dato!="-"){
			m1->data[j+i*m1->cols]="\u2690";
			++c_flag;
			c_i=i;
			}
		}
		
	}
	mat_print(m1);
	return m1;
}
