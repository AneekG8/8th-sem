#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>
#include<math.h>

int mod(int a,int b)
{
    return a%b < 0 ? a%b + b : a%b;
}

char* keyedTransEncrypt(char* s,int key[])
{
    int len = 0 , spaces = 0;

    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i] == ' ')
            spaces++;

        len++;
    }

    //form a matrix with block width 5
    int r = ceil((double)(len-spaces)/5);   

    char mat[r][5];

    int k  = 0;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<5;j++)
        {
            while(s[k] == ' ')
                k++;

            if(k < len)
                mat[i][j] = toupper(s[k++]);
            else
                mat[i][j] = 'Z';
            
            printf("%c ",mat[i][j]);
        }
        printf("\n");
    }

    //form a encrypted matrix
    char matEn[r][5];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<5;j++)
            matEn[i][j] = mat[i][key[j]-1];
    }

    //encrypted text
    char* res = (char*)malloc(sizeof(char)*100);

    k = 0;

    for(int j=0;j<5;j++)
    {
        for(int i=0;i<r;i++)
            res[k++] = matEn[i][j];
    }

    res[k] = '\0';

    return res;
}

char* keyedTransDecrypt(char* s,int key[])
{
    int len = 0 , spaces = 0;

    for(int i=0;s[i]!='\0';i++)
        len++;

    //form a matrix with block width 5
    int r = len/5;   

    char mat[r][5];

    int k = 0;

    for(int j=0;j<5;j++)
    {
        for(int i=0;i<r;i++)
            mat[i][j] = s[k++];
    }

    //form a decryption key from the given encryption key
    int keyDe[5];

    for(int i=0;i<5;i++)
        keyDe[key[i]-1] = i+1;

    //form a decrypted matrix
    char matDe[r][5];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<5;j++)
            matDe[i][j] = mat[i][keyDe[j]-1];
    }

    //encrypted text
    char* res = (char*)malloc(sizeof(char)*100);

    k = 0;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<5;j++)
            res[k++] = tolower(matDe[i][j]);
    }

    res[k] = '\0';

    return res;
}

int main()
{
    char text[100];

    int key[5];

    printf("enter the plain text: ");

    scanf("%[^\n]s",text);

    getchar();

    printf("enter the encryption key: ");

    for(int i=0;i<5;i++)
        scanf("%d",&key[i]);    

    char* encryptedText = keyedTransEncrypt(text,key);

    printf("the encrypted text is: %s\n\n",encryptedText);

    char* decryptedText = keyedTransDecrypt(encryptedText,key);

    printf("the decrypted text is: %s\n\n",decryptedText);

    return 0;
}