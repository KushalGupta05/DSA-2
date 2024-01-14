#include<stdio.h>
int rsum(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else 
    {
        return n + rsum(n-1);
    }
}
int main()
{
    int n;
    printf("Enter the number :");
    scanf("%d",&n);
    printf("Addition of 1 to %d is %d",n,rsum(n));
    return 0;
}