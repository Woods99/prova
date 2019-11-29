#include <stdio.h>
#include "global.h"
#include "matrix.c"


int main()
{

struct mat * m1, *m2, *m3;

m1=mat_read_alloc();
mat_print(m1);
mat_free(m1);
}
