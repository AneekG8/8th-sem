//additive cipher

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

char* addEncrypt(char* s,int k)
{
    if(!s)
        return NULL;

    char* res = (char*)malloc(sizeof(char)*100);

    int i = 0, j = 0;

    for(;s[i]!='\0';i++)
    {
        if(s[i] == ' ')
            continue;

        char init = isupper(s[i]) ? 'A' : 'a';

        res[j++] = mod((s[i] - init + k),26) + 'A';
    }

    res[j] = '\0';

    return res;
}

char* addDecrypt(char* s,int k)
{
    if(!s)
        return NULL;
    
    char* res = (char*)malloc(sizeof(char)*100);

    int i = 0;

    for(;s[i]!='\0';i++)
    {
        if(s[i] == ' ')
            continue;
        
        char init = isupper(s[i]) ? 'A' : 'a';

        res[i] = mod((s[i] - init - k),26) + 'a';
    }

    res[i] = '\0';
    
    return res;
}

char* multEncrypt(char* s,int k)
{
    if(!s)
        return NULL;
    
    if(gcd(k,26) != 1)
    {
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
    if(!s)
        return NULL;
    
    int kInv = multInv(26,k);

    if(kInv == -1)
    {
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

char* affineEncrypt(char* s,int k1,int k2)
{
    return addEncrypt(multEncrypt(s,k1),k2);
}

char* affineDecrypt(char* s,int k1,int k2)
{
    return multDecrypt(addDecrypt(s,k2),k1);
}

void affineCipherKeySearch(char* s)
{

    int validMultKeys[12] , c = 0;

    for(int i=1;i<26;i++)
    {
        if(multInv(26,i) != -1)
            validMultKeys[c++] = i;
    }

    printf("the possible plain texts are: \n");

    for(int i=0;i<26;i++)
    {
        char* addDecrypted = addDecrypt(s,i);

        for(int j=0;j<12;j++)
        {
            char* multDecrypted = multDecrypt(addDecrypted,validMultKeys[j]);

            printf("for shift key %d and mult key %d : plain text is : %s\n",i,validMultKeys[j],multDecrypted);
        }
    }
}

int main()
{
    char text[100];

    int k;

    printf("enter the encrypted text: ");

    scanf("%[^\n]s",text);

    affineCipherKeySearch(text);

    return 0;
}