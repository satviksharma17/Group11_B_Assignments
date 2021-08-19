#include<stdio.h>

int fun(int x) {
  
    int y = (x|(~x+1));
    y = y >> 31;
    
    return y + 1;
}

int main(void) {
   int x=1;
    
   printf("%d",fun(x));
    
    return 0;
}