#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>

int mod(int a,int b)
{
    return a%b < 0 ? a%b + b : a%b;
}

char* auto_keyEncrypt(char* s,char key)
{
    key = toupper(key);

    char* res = (char*)malloc(sizeof(char)*100);

    int i = 0 , j  = 0;

    printf("keystream is: ");

    for(;s[i]!='\0';i++)
    {
        if(s[i] == ' ')
            continue;

        printf("%c",key);

        char init = isupper(s[i]) ? 'A' : 'a';

        res[j++] = (s[i] - init + key - 'A') % 26 + 'A';

        key = toupper(s[i]);
    }

    printf("\n");

    res[j] = '\0';

    return res;
}

char* auto_keyDecrypt(char* s,char key)
{
    key = toupper(key);

    char* res = (char*)malloc(sizeof(char)*100);

    int i = 0;

    for(;s[i]!='\0';i++)
    {
        res[i] = mod((s[i] - key),26) + 'a';

        key = toupper(res[i]);
    }

    res[i] = '\0';

    return res;
}

int main()
{
    char text[100] ,  key;

    printf("enter the plain text: ");

    scanf("%[^\n]s",text);

    getchar();

    printf("enter the key: ");
    scanf("%c",&key);
    
    char* encryptedText = auto_keyEncrypt(text,key);

    printf("the encrypted text is: %s\n\n",encryptedText);

    char* decryptedText = auto_keyDecrypt(encryptedText,key);

    printf("the decrypted text is: %s\n\n",decryptedText);

    return 0;
}