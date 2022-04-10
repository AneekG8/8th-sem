#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>
#include<math.h>
#include<string.h>

int mod(int a,int b)
{
    return a%b < 0 ? a%b + b : a%b;
}

char* permutationEncrypt(char* s,int key[])
{   
    char* res = (char*)malloc(sizeof(char)*100);

    int ind = 0;

    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i] == ' ')
            continue;

        key[ind] = rand() % 9;

        res[ind] = ((toupper(s[i])-'A') ^ key[ind])  + 'A';

        ind++;
    }

    res[ind] = '\0';
    
    return res;
}

char* permutationDecrypt(char* s,int key[])
{
    char* res = (char*)malloc(sizeof(char)*100);

    int i = 0;

    for(;s[i]!='\0';i++)
        res[i] = ((toupper(s[i])-'A') ^ key[i]) + 'a';


    res[i] = '\0';

    return res;
}

int main()
{
    char text[100];

    printf("enter the plain text: ");

    scanf("%[^\n]s",text);

    getchar();

    // int len = 0 ,  spaces = 0;

    // for(int i=0;text[i]!='\0';i++)
    // {
    //     if(text[i] == ' ')
    //         spaces++;

    //     len++;
    // }

    // int trimmedLen = len-spaces;

    // int key[trimmedLen];

    int key[100];

    char* encryptedText = permutationEncrypt(text,key);

    printf("the encrypted text is: %s\n\n",encryptedText);

    char* decryptedText = permutationDecrypt(encryptedText,key);

    printf("the decrypted text is: %s\n\n",decryptedText);

    return 0;
}