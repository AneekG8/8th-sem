#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>
#include<math.h>

int mod(int a,int b)
{
    return a%b < 0 ? a%b + b : a%b;
}

char* permutationEncrypt(char* s,int key[],int keySize)
{
    int len = 0 , spaces = 0;

    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i] == ' ')
            spaces++;

        len++;
    }

    //form a matrix with block width keySize
    int r = ceil((double)(len-spaces)/keySize);   

    int mat[r][keySize];

    int k  = 0;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<keySize;j++)
        {
            while(s[k] == ' ')
                k++;

            if(k < len)
                mat[i][j] = toupper(s[k++]) - 'A';
            else
                mat[i][j] = 25;
            
            //printf("%c ",mat[i][j]);
        }
        //printf("\n");
    }

    //form a key matrix

    int matKey[keySize][keySize];

    for(int j=0;j<keySize;j++)
    {
        for(int i=0;i<keySize;i++)
        {
            if(i == key[j]-1)
                matKey[i][j] = 1;
            else
                matKey[i][j] = 0;
        }
    }

    for(int i=0;i<keySize;i++)
    {
        for(int j=0;j<keySize;j++)
        {
            printf("%d ",matKey[i][j]);
        }

        printf("\n");
    }

    char* res = (char*)malloc(sizeof(char)*100);
    int ind = 0;

    //matrix multiplication
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<keySize;j++)
        {
            int val  = 0;

            for(int p=0;p<keySize;p++)
            {
                val += mat[i][p] * matKey[p][j];
            }

            res[ind] = val % 26 + 'A';
            ind++;
        }
    }
    res[ind] = '\0';
    return res;
}

char* permutationDecrypt(char* s,int key[],int keySize)
{
    int len = 0;

    for(int i=0;s[i]!='\0';i++)
        len++;

    //form a matrix with block width keySize
    int r = len/keySize;   

    int mat[r][keySize];

    int k  = 0;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<keySize;j++)
            mat[i][j] = toupper(s[k++]) - 'A';

    }

    //form a decryption key from the given encryption key
    int keyDe[keySize];

    for(int i=0;i<keySize;i++)
        keyDe[key[i]-1] = i+1;

    //form a key matrix

    int matKey[keySize][keySize];

    for(int j=0;j<keySize;j++)
    {
        for(int i=0;i<keySize;i++)
        {
            if(i == keyDe[j]-1)
                matKey[i][j] = 1;
            else
                matKey[i][j] = 0;
        }
    }

    char* res = (char*)malloc(sizeof(char)*100);
    int ind = 0;

    //matrix multiplication
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<keySize;j++)
        {
            int val  = 0;

            for(int p=0;p<keySize;p++)
            {
                val += mat[i][p] * matKey[p][j];
            }

            res[ind] = val % 26 + 'a';
            ind++;
        }
    }

    res[ind] = '\0';
    return res;
}

int main()
{
    char text[100];

    printf("enter the plain text: ");

    scanf("%[^\n]s",text);

    getchar();

    int keySize;

    printf("enter the key size: ");

    scanf("%d",&keySize);

    int key[keySize];

    printf("enter the encryption key: ");

    for(int i=0;i<keySize;i++)
        scanf("%d",&key[i]);    

    char* encryptedText = permutationEncrypt(text,key,keySize);

    printf("the encrypted text is: %s\n\n",encryptedText);

    char* decryptedText = permutationDecrypt(encryptedText,key,keySize);

    printf("the decrypted text is: %s\n\n",decryptedText);

    return 0;
}