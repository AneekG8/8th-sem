#include<stdio.h>
int mod(int a,int b)
{
    return a%b < 0 ? a%b + b : a%b;
}

int gcd(int a,int b)
{
    if(b == 0)
        return a;

    return gcd(b,mod(a,b)); 
}

void dioPhantine(int a,int b,int c)
{
    if(c % gcd(a,b))
    {
        printf("no solution\n");
        return;
    }

    int r1 = a, r2 = b;

    int s1 = 1, s2 = 0;

    int t1 = 0, t2 = 1;

    while(r2)
    {
        int q = r1/r2;

        // if(r1%r2 < 0)
        //     q = r1<0 && r2<0 ? q+1 : q-1;               
             
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

    int x0 = s1*c/r1;
    int y0 = t1*c/r1;

    printf("\nthe particular solution of the equation is x0: %d y0: %d\n",x0,y0);

    printf("\nthe general solutions of the equation are: \n");

    printf("x = %d + k * %d and y = %d - k * %d\n",x0,b/r1,y0,a/r1);
    printf("x = %d - k * %d and y = %d + k * %d\n",x0,b/r1,y0,a/r1);
}

int main()
{
    int a,b,c;

    printf("enter the values( for ax+by+c ): ");
    scanf("%d%d%d",&a,&b,&c);
    dioPhantine(a,b,c);
}