#include<stdio.h>
#include "mod.h"

int multInv(int n,int x)
{
    if(gcd(n,x) != 1)
        return -1;

    for(int i=0;i<n;i++)
    {
        if( mod(x*i,n) == 1 )
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

    printf("\nthe multiplicative inverse of %d mod %d is: %d",x,n,multInv(n,x));

    return 0;
}