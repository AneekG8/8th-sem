//affine cipher

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>
#include<math.h>

int key[4][4] = {   {9,7,11,13},
                    {4,7,5,6},
                    {2,21,14,9},
                    {3,23,21,8},
                  };

int keyInv[4][4] = {    {2,15,22,3},
                        {15,0,19,3},
                        {9,9,3,11},
                        {17,0,4,7}
                  };

int mod(int a,int b)
{
    return a%b < 0 ? a%b + b : a%b;
}

char randChar(char c)
{
    while(1)
    {
        char ch = rand()%26 + 'a';

        if(ch != c)
            return ch;
    }
}

char* hillEncrypt(char* s)
{
    int len = 0 , spaces = 0;

    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i] == ' ')
            spaces++;

        len++;
    }

    int r = ceil((double)(len-spaces)/4);   

    int mat[r][4];

    int k = 0;

    //create a matrix from the inut string
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<4;j++)
        {
            while(s[k] == ' ')
                k++;

            if(k < len)
            {
                char init = isupper(s[k]) ? 'A' : 'a';
                mat[i][j] = (int)(s[k++]-init);   //offset
            }
            else
                mat[i][j] = 25;
        }
    }

    //print the matrix created from input string
    // for(int i=0;i<r;i++)
    // {
    //     for(int j=0;j<4;j++)
    //         printf("%d ",mat[i][j]);

    //     printf("\n");
    // }

    //print the modified string
    printf("the modified text is: ");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<4;j++)
            printf("%c",mat[i][j]+'a');
    }
    printf("\n\n");

    char* res = (char*)malloc(sizeof(char)*100);
    int ind = 0;

    //matrix multiplication
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<4;j++)
        {
            int val  = 0;

            for(int p=0;p<4;p++)
            {
                val += mat[i][p] * key[p][j];
            }
            res[ind] = val % 26 + 'A';
            ind++;
        }
    }
    res[ind] = '\0';
    return res;
}

char* hillDecrypt(char* s)
{
    int len = 0;

    for(int i=0;s[i]!='\0';i++)
        len++;

    int r = len/4;

    int mat[r][4];

    int k = 0;

    //create a matrix from the inut string
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<4;j++)
            mat[i][j] = (int)(s[k++]-'A');   //offset
    }

        char* res = (char*)malloc(sizeof(char)*100);
    int ind = 0;

    //matrix multiplication
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<4;j++)
        {
            int val  = 0;

            for(int p=0;p<4;p++)
                val += mat[i][p] * keyInv[p][j];

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
    
    char* encryptedText = hillEncrypt(text);

    printf("the encrypted text is: %s\n\n",encryptedText);

    char* decryptedText = hillDecrypt(encryptedText);

    printf("the decrypted text is: %s\n\n",decryptedText);

    return 0;
}