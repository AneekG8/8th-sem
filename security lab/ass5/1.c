#include<stdio.h>
#include<math.h>

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
    int p = 5, q = 11 , n = p*q , fi = (p-1)*(q-1);

    int e=2;

    while(e < fi)
    {
        if(gcd(e,fi) == 1)
            break;
            
        e++;
    }

    printf("The value of e is %d",e);

    int d = multInv(e,fi);

    printf("The value of d is %d",d);

    int pt = 10;

    int ct = pow(pt,e);

    int dt = pow(ct,d);

    ct = mod(ct,n);
    dt = mod(dt,n);

    printf("Message data = %d",pt);
    printf("\np = %d",p);
    printf("\nq = %d",q);
    printf("\nn = p*q = %d",n);
    printf("\nfi = %d",fi);
    printf("\ne = %d",e);
    printf("\nd = %d",d);
    printf("\nEncrypted data = %d",ct);
    printf("\nOriginal Message Sent = %d",dt);

    return 0;
}