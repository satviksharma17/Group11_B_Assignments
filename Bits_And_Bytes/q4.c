#include<stdio.h>

int getb(int x,int n) {
    int c=127;
    c= c<<8*n;
    int b = c&x;
    b=b>>8*n;
    return b;
}
void main(void) {
    
    int x= 305419896;
    int n=1;
    printf("%d ",getb(x,n));
    
    return 0;
}