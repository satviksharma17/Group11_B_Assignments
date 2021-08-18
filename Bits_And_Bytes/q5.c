#include<stdio.h>

int shift (int x,int n) {

    x=x>>n;
    
    int c = (~((1<<31)>>n-1));
    
    
    return x&c;
}

int main() {
    
    int x= 22343343;
    int n=4;
    printf("%d",shift(x,n));
    return 0;
}