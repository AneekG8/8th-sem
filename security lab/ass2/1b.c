//multiplicaitive cipher

#include<stdio.h>
#include<ctype.h>
#include<malloc.h>

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

char* multEncrypt(char* s,int k)
{
    if(gcd(k,26) != 1)
    {
        printf("invalid key value\n");
        return NULL;
    }

    char* res = (char*)malloc(sizeof(char)*100);

    int i = 0 , j = 0;

    for(;s[i]!='\0';i++)
    {
        if(s[i] == ' ')
            continue;
        
        char init = isupper(s[i]) ? 'A' : 'a';

        res[j++] = mod((s[i] - init) * k,26) + 'A';
    }

    res[j] = '\0';

    return res;
}

char* multDecrypt(char* s,int k)
{
    int kInv = multInv(26,k);

    if(kInv == -1)
    {
        printf("invalid key value\n");
        return NULL;
    }

    char* res = (char*)malloc(sizeof(char)*100);

    int i = 0;

    for(;s[i]!='\0';i++)
    {
        if(s[i] == ' ')
            continue;
        
        char init = isupper(s[i]) ? 'A' : 'a';

        res[i] = mod((s[i] - init) * kInv,26) + 'a';
    }

    res[i] = '\0';
    
    return res;
}

int main()
{
    char text[100];

    int k;

    printf("enter the plain text: ");

    scanf("%[^\n]s",text);

    printf("enter the key value: ");

    scanf("%d",&k);

    printf("the encrypted text is: %s\n",multEncrypt(text,k));

    printf("the decrypted text is: %s\n",multDecrypt(multEncrypt(text,k),k));

    return 0;
}