#include<stdio.h>
// void decreasing(int num)
// {
//     if(num >= 1 )
//     {
//         printf("%d\n",num);
//         decreasing(num-1);
//     }
// }
void increasing(int n)
{
    if(n == 0) return ;
    if(n >= 1 )
    {
        printf("%d\n",n);
        increasing(n-1);
        printf("%d\n",n); 
    }
}
int main()
{
    int num;
    printf("Enter the number :");
    scanf("%d",&num);
    printf("\nThe numbers in increasing order are:\n");
    increasing(num);
    return 0;
}