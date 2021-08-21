#include<stdio.h>

int main(void) {
    

    int n;
    
    scanf("%d", &n);
    
    int a=0,b=1,c=0;
    
    for(int i=1;i<=3*n;i++) {
         
        a=b;
        b=c;
        c=a+b;
        
        //c is even
        if(c%2==0) {
            printf("%d ", c);
        }
    }
        
    return 0;
}