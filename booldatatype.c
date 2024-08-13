#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
int main()
{
    int a;
    float b;
    double c;
    char d;
    bool e;
    printf("%lu\n%lu\n%lu\n%lu\n%lu\n",sizeof(a),sizeof(b),sizeof(c),sizeof(d),sizeof(e));
}