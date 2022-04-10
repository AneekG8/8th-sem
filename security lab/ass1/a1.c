#include<stdio.h>
#include "mod.h"

int addInv(int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if( mod(x+i,n) == 0 )
            return i;
    }

    return -1;
}

int main()
{
    int n,x;

    printf("enter the value of n: ");
    scanf("%d",&n);

    printf("\nenter the value of x: ");
    scanf("%d",&x);

    printf("\nthe additive inverse of %d mod %d is: %d",x,n,addInv(n,x));

    return 0;
}