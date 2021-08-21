#include<stdio.h>

void merge(int *a, int l, int r) {
    
    int m = l + (r-l)/2;
    int n1 = m + 1 - l;
    int n2 = r - m;
    
    int a1[n1], a2[n2];
    
    int c=0;
    for(int i=l;i<=m;i++) {
        a1[c++]=a[i];
    }
    c=0;
    for(int i=m+1;i<=r;i++) {
        a2[c++]=a[i];
    }
    
    int i=0,j=0,k=l;
    
    while(i<n1&&j<n2) {
        if(a1[i]<=a2[j]) {
            a[k++]=a1[i];
            i++;
        }
        else {
            a[k++]=a2[j];
            j++;
        }
    }
    while (i < n1) {
        a[k++]=a1[i++];
    }
    
    while (j < n2) {
        a[k++]=a2[j++];
    }
   
}

void sort(int *a,int l,int r) {
    
    if(l>=r)return;
    
    int m = l + (r-l)/2;
    
   sort(a, l, m);
    
    sort(a, m+1, r);
    
    merge(a, l, r);
    
    return;
}

int main(void) {
    
    int n, m;
    
    scanf("%d %d",&n,&m);
    
    int a[n];
    
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    
    
    sort(a, 0, n-1);
   

    
    printf("%d ", a[m-1]);
    
    return 0;
}