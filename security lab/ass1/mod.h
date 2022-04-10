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