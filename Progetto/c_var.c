#include <math.h>
#include "c_flag.c"

int myPow(int x,int n)
{
    int i; /* Variable used in loop counter */
    int number = 1;

    for (i = 0; i < n; ++i)
        number *= x;

    return(number);
}

int mycVar(char * get_env,int c_num_p){
int sum=0;
int c=0;
for(int i =0;i < sizeof(get_env) && get_env[i]!=((char)0);i++){
		++c_num_p;
		}
		for(int i=c_num_p-1;i >= 0;i--){		
		sum+=((get_env[i]-48)*myPow(10,c));	
		++c;
		}
	return sum;
}

