#include<stdio.h>
int Check_InversionCount(int a[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            count++;
        }
    }
    return count;
}
int main() {
  int a[]={8,4,2,1};
  int inversion_count=Check_InversionCount(a,4);

    printf("%d",inversion_count);
}