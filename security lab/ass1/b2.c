#include<stdio.h>
#include "mod.h"

void extEucld(int a,int b)
{
    int r1 = a, r2 = b;

    int s1 = 1, s2 = 0;

    int t1 = 0, t2 = 1;

    while(r2)
    {
        int q = r1/r2;

        if(r1%r2 < 0)
            q = r1<0 && r2<0 ? q+1 : q-1;        
             
        int r = r1 - q * r2;

        int s = s1 - q * s2;

        int t = t1 - q * t2;

        printf("q: %d r1: %d r2: %d r: %d s1: %d s2: %d s: %d t1: %d t2: %d t: %d\n",q,r1,r2,r,s1,s2,s,t1,t2,t);

        r1 = r2, r2 = r;

        s1 = s2, s2 = s;

        t1 = t2, t2 = t;
    }

    printf("r1: %d r2: %d s1: %d s2: %d t1: %d t2: %d\n",r1,r2,s1,s2,t1,t2);

    printf("\n(s)%d * %d + (t)%d * %d = %d\n",s1,a,t1,b,r1);

    if(r1 != 1)
        return;

    int s = s1 < 0 ? b+s1 : s1;

    int t = t1 < 0 ? a+t1: t1;

    if(b>0)
        printf("multiplicative inverse of %d mod %d is: %d\n",a,b,s);

    if(a>0)
        printf("multiplicative inverse of %d mod %d is: %d\n",b,a,t);


}

int main()
{
    int a , b;

    printf("enter the value of a: ");
    scanf("%d",&a);

    printf("enter the value of b: ");
    scanf("%d",&b);

    extEucld(a,b);

}