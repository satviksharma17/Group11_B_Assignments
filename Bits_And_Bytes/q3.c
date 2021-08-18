#include<stdio.h>

int sign(int x) {
    int b = x>>31;
    
    if(b)return 0;
    
    else return 1;
}
// 0 for positive
// 1 for negative
void main(void) {
    
    int x= 10;
    
    printf("%d ",sign(x));
    
    return 0;
}