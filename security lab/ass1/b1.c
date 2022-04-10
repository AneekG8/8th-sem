#include<stdio.h>
#include "mod.h"

int gcd(int a,int b)
{
    //display
    printf("r1: %d r2: %d ",a,b);

    if(b)
        printf("q: %d r: %d",a/b,mod(a,b));

    printf("\n");

    //base
    if(b == 0)
        return a;

    //next iteration
    return gcd(b,mod(a,b));
}

int main()
{
    int a,b;

    printf("enter the values: ");
    scanf("%d %d",&a,&b);
    printf("gcd: %d",gcd(a,b));
}