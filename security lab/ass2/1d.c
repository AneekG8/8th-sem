//affine cipher

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>

char key[5][5] = {  {'L', 'G', 'D', 'B', 'A'},
                    {'Q', 'M', 'H', 'E', 'C'},
                    {'U', 'R', 'N', 'I', 'F'},
                    {'X', 'V', 'S', 'O', 'K'},
                    {'Z', 'Y', 'W', 'T', 'P'}
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

char* playFairEncrypt(char* s)
{
    char* res = (char*)malloc(sizeof(char)*100);
    char* modified = (char*)malloc(sizeof(char)*100);

    int i = 0,j = 0;

    printf("\n");


    for(;s[i]!='\0';i+=2)
    {
        //ignore white spaces
        while(s[i] == ' ')
            i++;

        char a = s[i];

        //ignore white spaces
        while(s[i] == ' ')
            i++;

        char b = s[i+1];

        //validate pair
        if(b == 'j')
            b = 'i';

        if(b == a || b == '\0')
        {
            b = randChar(b);
            i--;
        }

        modified[j] = a;
        modified[j+1] = b;

        //find position of pair 
        int r1,c1,r2,c2,found = 0;

        for(int r=0;r<5;r++)
        {
            for(int c = 0;c<5;c++)
            {
                if(key[r][c] == toupper(a))
                {
                    r1 = r;
                    c1 = c;
                    found++;
                }

                if(key[r][c] == toupper(b))
                {
                    r2 = r;
                    c2 = c;
                    found++;
                }
            }

            if(found == 2)
                break;
        }

        if(r1 == r2)
        {
            res[j++] = key[r1][mod(c1+1,5)];
            res[j++] = key[r2][mod(c2+1,5)];
        }

        else if(c1 == c2)
        {
            res[j++] = key[mod(r1+1,5)][c1];
            res[j++] = key[mod(r2+1,5)][c2];
        }

        else
        {
            res[j++] = key[r1][c2];
            res[j++] = key[r2][c1];
        }

        printf("%c%c ---> %c%c\n",a,b,res[j-2],res[j-1]);

    }

    res[j] = '\0';

    printf("\n");

    printf("the modified text is: %s\n",modified);

    return res;
}

char* playFairDecrypt(char* s)
{
    char* res = (char*)malloc(sizeof(char)*100);

    int i = 0;

    printf("\n");

    for(;s[i]!='\0';i+=2)
    {
        char a = s[i];

        char b = s[i+1];

        //find position of pair 
        int r1,c1,r2,c2,found = 0;

        for(int r=0;r<5;r++)
        {
            for(int c = 0;c<5;c++)
            {
                if(key[r][c] == a)
                {
                    r1 = r;
                    c1 = c;
                    found++;
                }

                if(key[r][c] == b)
                {
                    r2 = r;
                    c2 = c;
                    found++;
                }
            }

            if(found == 2)
                break;
        }

        if(r1 == r2)
        {
            res[i] = tolower(key[r1][mod(c1-1,5)]);
            res[i+1] = tolower(key[r2][mod(c2-1,5)]);
        }

        else if(c1 == c2)
        {
            res[i] = tolower(key[mod(r1-1,5)][c1]);
            res[i+1] = tolower(key[mod(r2-1,5)][c2]);
        }

        else
        {
            res[i] = tolower(key[r1][c2]);
            res[i+1] = tolower(key[r2][c1]);
        }

        printf("%c%c ---> %c%c\n",a,b,res[i],res[i+1]);

    }

    res[i] = '\0';

    printf("\n");

    return res;
}

int main()
{
    char text[100];

    printf("enter the plain text: ");

    scanf("%[^\n]s",text);
    
    char* encryptedText = playFairEncrypt(text);

    printf("the encrypted text is: %s\n\n",encryptedText);

    char* decryptedText = playFairDecrypt(encryptedText);

    printf("the decrypted text is: %s\n\n",decryptedText);

    return 0;
}