#include <stdio.h>

int add(int *a, int *b, int *c){
return *a + *b + *c;
}

int main()
{
int a,b,c;
a = 5;
b = 10;
c = 20;

printf("%d + %d + %d = %d\n", a, b, c, add(&a,&b,&c));

return 0;
}
