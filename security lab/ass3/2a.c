#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>

int mod(int a,int b)
{
    return a%b < 0 ? a%b + b : a%b;
}

char* vigenereEncrypt(char* s,char* key)
{
    int keyLen = 0;

    for(int i=0;key[i]!='\0';i++)
        keyLen++;

    char* res = (char*)malloc(sizeof(char)*100);

    int i = 0 , j  = 0 , k = 0;

    for(;s[i]!='\0';i++)
    {
        if(s[i] == ' ')
            continue;

        res[j++] = (toupper(s[i]) + toupper(key[k]) - 2 * 'A') % 26 + 'A';
        
        k = (k+1) % keyLen;
    }


    res[j] = '\0';

    return res;
}

char* vigenereDecrypt(char* s,char* key)
{
    int keyLen = 0;

    for(int i=0;key[i]!='\0';i++)
        keyLen++;

    char* res = (char*)malloc(sizeof(char)*100);

    int i = 0 , k = 0;

    for(;s[i]!='\0';i++)
    {
        res[i] = mod((toupper(s[i]) - toupper(key[k])),26) + 'a';
        
        k = (k+1) % keyLen;
    }


    res[i] = '\0';

    return res;
}

int main()
{
    char text[100] , key[100];

    printf("enter the plain text: ");

    scanf("%[^\n]s",text);

    getchar();

    printf("enter the key string: ");
    scanf("%[^\n]s",key);
    
    char* encryptedText = vigenereEncrypt(text,key);

    printf("the encrypted text is: %s\n\n",encryptedText);

    char* decryptedText = vigenereDecrypt(encryptedText,key);

    printf("the decrypted text is: %s\n\n",decryptedText);

    return 0;
}