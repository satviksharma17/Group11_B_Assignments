#include <stdio.h>


int bitAnd(int x, int y) {
    
    int ans = ~x | ~y;
    
    return ~ans;
    
}

int bitOr(int x,int y) {
    int ans = x|y;
    
    return ans;
}


// xor =x~y|~xy
int bitXor(int x,int y) {
   int a1 = bitAnd(x, ~y);
   int a2 = bitAnd(~x, y);
   
    int ans=bitOr(a1,a2);
    return ans;
}

int main() {
    
    int x, y;
    
    scanf("%d %d",& x, &y);
    
    int ans = bitXor(x, y);
    
    printf("%d\n",ans);
    return 0;
}