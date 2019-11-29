#include <stdio.h>
#include <string.h>

int main(){


//char (*m)[2][10];
char str[2][10]={"\u2690","fame"};
char * p=&str[0][0];
printf("%s\n",p);
}
