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

void shiftCipherKeySearch(char* s)
{
    printf("the possible plain texts are: \n");

    for(int i=0;i<26;i++)
    {
        char* decryptedText = addDecrypt(s,i);
        printf("for key %d : plain text is : %s\n",i,decryptedText);
    }
}

int main()
{
    char text[100];

    int k;

    printf("enter the encrypted text: ");

    scanf("%[^\n]s",text);

    shiftCipherKeySearch(text);

    return 0;
}