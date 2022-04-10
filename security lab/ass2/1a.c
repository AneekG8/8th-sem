//additive cipher

#include<stdio.h>
#include<ctype.h>
#include<malloc.h>

int mod(int a,int b)
{
    return a%b < 0 ? a%b + b : a%b;
}

char* addEncrypt(char* s,int k)
{
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

int main()
{
    char text[100];

    int k;

    printf("enter the plain text: ");

    scanf("%[^\n]s",text);

    printf("enter the shift key value: ");

    scanf("%d",&k);

    printf("the encrypted text is: %s\n",addEncrypt(text,k));

    printf("the decrypted text is: %s\n",addDecrypt(addEncrypt(text,k),k));

    return 0;
}