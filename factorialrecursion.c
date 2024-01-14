#include<stdio.h>
int factorial(int num)
{
    if(num<=1){
        return 1;
    }
    else 
    {
        return num * factorial(num-1);
    }
}
int main()
{
    int num;
    printf("Enter the number whose factorial you want :");
    scanf("%d", &num);
    if(num<0)
    {
        printf("Factorial not possible.");
    }
    else 
    {
        printf("%d ! = %d",num,factorial(num));
    }
    return 0;
}