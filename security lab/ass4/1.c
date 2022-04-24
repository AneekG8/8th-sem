#include<stdio.h>
#include<stdlib.h>

int shift_table[16] = { 1, 1, 2, 2,
                        2, 2, 2, 2,
                        1, 2, 2, 2,
                        2, 2, 2, 1 };
                       
int exp_d[48] =       { 32, 1, 2, 3, 4, 5, 4, 5,
                      6, 7, 8, 9, 8, 9, 10, 11,
                      12, 13, 12, 13, 14, 15, 16, 17,
                      16, 17, 18, 19, 20, 21, 20, 21,
                      22, 23, 24, 25, 24, 25, 26, 27,
                      28, 29, 28, 29, 30, 31, 32, 1 };


int sbox[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                          0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                          4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                          15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
                        { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                          3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                          0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                          13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },
 
                        { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                          13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                          13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                          1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
                        { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                          13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                          10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                          3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
                        { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                          14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                          4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                          11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
                        { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                          10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                          9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                          4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
                        { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                          13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                          1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                          6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
                        { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                          1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                          7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                          2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };


int straight_pbox[32] = {16, 7, 20, 21, 29, 12, 28, 17,
                         1, 15, 23, 26, 5, 18, 31, 10,
                         2, 8, 24, 14, 32, 27, 3, 9,
                         19, 13, 30, 6, 22, 11, 4, 25};

int key_parity[56] = { 57, 49, 41, 33, 25, 17, 9,
                     1, 58, 50, 42, 34, 26, 18,
                     10, 2, 59, 51, 43, 35, 27,
                     19, 11, 3, 60, 52, 44, 36,
                     63, 55, 47, 39, 31, 23, 15,
                     7, 62, 54, 46, 38, 30, 22,
                     14, 6, 61, 53, 45, 37, 29,
                     21, 13, 5, 28, 20, 12, 4 };

int key_compression[48] = { 14, 17, 11, 24, 1, 5,
                         3, 28, 15, 6, 21, 10,
                         23, 19, 12, 4, 26, 8,
                         16, 7, 27, 20, 13, 2,
                         41, 52, 31, 37, 47, 55,
                         30, 40, 51, 45, 33, 48,
                         44, 49, 39, 56, 34, 53,
                         46, 42, 50, 36, 29, 32 };
                         
int keys[16][48];
 


void bin_to_hex(int c[], int n){
    int k = 0;
    char c_hex[16];
    for(int i = 0; i < n; i+= 4){
        if(c[i] == 0 && c[i + 1] == 0 && c[i + 2] == 0 && c[i + 3] == 0){
            c_hex[k++] = '0';
        }
        else if(c[i] == 0 && c[i + 1] == 0 && c[i + 2] == 0 && c[i + 3] == 1){
            c_hex[k++] = '1';
        }
        else if(c[i] == 0 && c[i + 1] == 0 && c[i + 2] == 1 && c[i + 3] == 0){
            c_hex[k++] = '2';
        }
        else if(c[i] == 0 && c[i + 1] == 0 && c[i + 2] == 1 && c[i + 3] == 1){
            c_hex[k++] = '3';
        }
        else if(c[i] == 0 && c[i + 1] == 1 && c[i + 2] == 0 && c[i + 3] == 0){
            c_hex[k++] = '4';
        }
        else if(c[i] == 0 && c[i + 1] == 1 && c[i + 2] == 0 && c[i + 3] == 1){
            c_hex[k++] = '5';
        }
        else if(c[i] == 0 && c[i + 1] == 1 && c[i + 2] == 1 && c[i + 3] == 0){
            c_hex[k++] = '6';
        }
        else if(c[i] == 0 && c[i + 1] == 1 && c[i + 2] == 1 && c[i + 3] == 1){
            c_hex[k++] = '7';
        }
        else if(c[i] == 1 && c[i + 1] == 0 && c[i + 2] == 0 && c[i + 3] == 0){
            c_hex[k++] = '8';
        }
        else if(c[i] == 1 && c[i + 1] == 0 && c[i + 2] == 0 && c[i + 3] == 1){
            c_hex[k++] = '9';
        }
        else if(c[i] == 1 && c[i + 1] == 0 && c[i + 2] == 1 && c[i + 3] == 0){
            c_hex[k++] = 'A';
        }
        else if(c[i] == 1 && c[i + 1] == 0 && c[i + 2] == 1 && c[i + 3] == 1){
            c_hex[k++] = 'B';
        }
        else if(c[i] == 1 && c[i + 1] == 1 && c[i + 2] == 0 && c[i + 3] == 0){
            c_hex[k++] = 'C';
        }
        else if(c[i] == 1 && c[i + 1] == 1 && c[i + 2] == 0 && c[i + 3] == 1){
            c_hex[k++] = 'D';
        }
        else if(c[i] == 1 && c[i + 1] == 1 && c[i + 2] == 1 && c[i + 3] == 0){
            c_hex[k++] = 'E';
        }
        else if(c[i] == 1 && c[i + 1] == 1 && c[i + 2] == 1 && c[i + 3] == 1){
            c_hex[k++] = 'F';
        }
    }
    c_hex[k] = '\0';
    printf("%s\n", c_hex);
}

void straight_pbox_func(int compressed_sbox[], int function_output[]){
    for(int i = 0; i < 32; i++){
        function_output[i] = 0;
    }

    //printf("straight pbox output: ");
    for(int i = 0; i < 32; i++){
        function_output[i] = compressed_sbox[straight_pbox[i] - 1];
    //    printf("%d ", function_output[i]);
    }
    //printf("\n");
}

void func_sbx(int right[], int compressed_sbox[]){

    int k = 0, j = 4;
    for(int i = 0; i < 32; i++){
        compressed_sbox[i] = 0;
    }

    for(int i = 0; i < 8; i++){
        int row = 2 * right[6 * i + 0] + right[6 * i + 5];
        int col = 8 * right[6 * i + 1] + 4 * right[6 * i + 2] + 2 * right[6 * i + 3] + right[6 * i + 4];

        int val_sbox = sbox[i][row][col];
        //printf("%d %d %d\n", row, col, val_sbox);
        while (val_sbox > 0) {
            compressed_sbox[j - k - 1] = val_sbox % 2;
            val_sbox = val_sbox / 2;
            k++;
        }
        j += 4;
        k = 0;
    }
    // printf("Sbox output: ");
    // for(int i = 0; i < 8; i++){
    //     printf("%d ", compressed_sbox[i]);
    // }
    // printf("\n");
}

void expansion(int right[], int expanded_right[]){
    for(int i=0;i<48;i++)
    {
        expanded_right[i] = right[exp_d[i]-1];
    }
}

void xor(int a[], int b[], int n){
    for(int i = 0; i < n; i++){
        a[i] = a[i] ^ b[i];
    }
}

void function(int right[], int key[], int function_output[]){
   
    int expanded_right[48], compressed_sbox[32];

    expansion(right, expanded_right);

    xor(expanded_right, key, 48);

    // printf("XOR inside function: ");
    // for(int i = 0; i < 12; i++){
    //     printf("%d ", expanded_right[i]);
    // }
    // printf("\n");

    func_sbx(expanded_right, compressed_sbox);

    straight_pbox_func(compressed_sbox, function_output);
}

void mixer(int left[], int right[], int key[]){
    int function_output[32];

    function(right, key, function_output);
   
    //printf("XOR inside mixer: ");
    xor(left, function_output, 32);

    // for(int i = 0; i< 8; i++){
    //     printf("%d ", left[i]);
    // }
    // printf("\n");
   
}

void swapper(int left[], int right[]){
    for(int i = 0; i< 32; i++){
        int temp = left[i];
        left[i] = right[i];
        right[i] = temp;
    }
}
void shift_left(int key[], int shifts){
    int new_key[28], k = 0;

    for(int i = 0; i < shifts; i++){
        for(int j = 1; j < 28; j++){
            new_key[j - 1] = key[j];
        }
        new_key[27] = key[0];
        for(int j = 0; j < 28; j++){
            key[j] = new_key[j];
        }
    }
}

void generate_key(int key[], int shifts, int key_compressed[]){
    int key_left[28], key_right[28];
    for(int i = 0; i < 28; i++){
        key_left[i] = key[i];
    }

    for(int i = 28; i < 56; i++){
        key_right[i - 28] = key[i];
    }
    shift_left(key_left, shifts);
    shift_left(key_right, shifts);

    //bin_to_hex(key_left, 28);
    //bin_to_hex(key_right, 28);

    for(int i = 0; i < 28; i++){
        key[i] = key_left[i];
    }

    for(int i = 28; i < 56; i++){
        key[i] = key_right[i - 28];
    }

    //key compression
    //printf("Key after compression: ");
    for(int i = 0; i < 48; i++){
        key_compressed[i] = key[key_compression[i] - 1];
    //    printf("%d ", key_compressed[i]);
    }
    //bin_to_hex(key_compressed, 48);
    //printf("\n");
}

void parity_bit_drop(int key[], int new_key[]){
    for(int i = 0; i < 56; i++){
        new_key[i] = key[key_parity[i] - 1];
    }
}

void hex_to_bin(char plain_hex[], int plaintext[]){
    int k = 0;
    for(int i = 0; i < 16; i++){
        if(plain_hex[i] == '0'){
            plaintext[k] = 0;
            plaintext[k + 1] = 0;
            plaintext[k + 2] = 0;
            plaintext[k + 3] = 0;
        }
        else if(plain_hex[i] == '1'){
            plaintext[k] = 0;
            plaintext[k + 1] = 0;
            plaintext[k + 2] = 0;
            plaintext[k + 3] = 1;
        }
        else if(plain_hex[i] == '2'){
            plaintext[k] = 0;
            plaintext[k + 1] = 0;
            plaintext[k + 2] = 1;
            plaintext[k + 3] = 0;
        }
        else if(plain_hex[i] == '3'){
            plaintext[k] = 0;
            plaintext[k + 1] = 0;
            plaintext[k + 2] = 1;
            plaintext[k + 3] = 1;
        }
        else if(plain_hex[i] == '4'){
            plaintext[k] = 0;
            plaintext[k + 1] = 1;
            plaintext[k + 2] = 0;
            plaintext[k + 3] = 0;
        }
        else if(plain_hex[i] == '5'){
            plaintext[k] = 0;
            plaintext[k + 1] = 1;
            plaintext[k + 2] = 0;
            plaintext[k + 3] = 1;
        }
        else if(plain_hex[i] == '6'){
            plaintext[k] = 0;
            plaintext[k + 1] = 1;
            plaintext[k + 2] = 1;
            plaintext[k + 3] = 0;
        }
        else if(plain_hex[i] == '7'){
            plaintext[k] = 0;
            plaintext[k + 1] = 1;
            plaintext[k + 2] = 1;
            plaintext[k + 3] = 1;
        }
        else if(plain_hex[i] == '8'){
            plaintext[k] = 1;
            plaintext[k + 1] = 0;
            plaintext[k + 2] = 0;
            plaintext[k + 3] = 0;
        }
        else if(plain_hex[i] == '9'){
            plaintext[k] = 1;
            plaintext[k + 1] = 0;
            plaintext[k + 2] = 0;
            plaintext[k + 3] = 1;
        }
        else if(plain_hex[i] == 'A'){
            plaintext[k] = 1;
            plaintext[k + 1] = 0;
            plaintext[k + 2] = 1;
            plaintext[k + 3] = 0;
        }
        else if(plain_hex[i] == 'B'){
            plaintext[k] = 1;
            plaintext[k + 1] = 0;
            plaintext[k + 2] = 1;
            plaintext[k + 3] = 1;
        }
        else if(plain_hex[i] == 'C'){
            plaintext[k] = 1;
            plaintext[k + 1] = 1;
            plaintext[k + 2] = 0;
            plaintext[k + 3] = 0;
        }
        else if(plain_hex[i] == 'D'){
            plaintext[k] = 1;
            plaintext[k + 1] = 1;
            plaintext[k + 2] = 0;
            plaintext[k + 3] = 1;
        }
        else if(plain_hex[i] == 'E'){
            plaintext[k] = 1;
            plaintext[k + 1] = 1;
            plaintext[k + 2] = 1;
            plaintext[k + 3] = 0;
        }
        else if(plain_hex[i] == 'F'){
            plaintext[k] = 1;
            plaintext[k + 1] = 1;
            plaintext[k + 2] = 1;
            plaintext[k + 3] = 1;
        }
        k = k + 4;
    }
}

void DES_decryption(int plaintext[]){
    int left[32], right[32], ciphertext[64];

    for(int i = 0; i < 32; i++){
        left[i] = plaintext[i];
    }

    for(int i = 32; i < 64; i++){
        right[i - 32] = plaintext[i];
    }

   
    for(int i = 1; i <= 16; i++){
       
        mixer(left, right, keys[16-i]);
       
        if(i != 16){
            swapper(left, right);
            // bin_to_hex(left, 32);
            // bin_to_hex(right, 32);
        }
    }

    printf("The plaintext in binary is: ");
    int k = 0;
    for(int i = 0; i < 32; i++){
        ciphertext[k] = left[i];
        printf("%d ", ciphertext[k]);
        k++;
    }
    for(int i = 0; i < 32; i++){
        ciphertext[k] = right[i];
        printf("%d ", ciphertext[k]);
        k++;
    }
    printf("\n");

    printf("The plaintext in hexadecimal is: ");
    //char cipher_hex[16];
    bin_to_hex(ciphertext, 64);
    //printf("%s\n", cipher_hex);
}

void DES_encryption(int plaintext[]){
    int left[32], right[32], ciphertext[64];

    for(int i = 0; i < 32; i++){
        left[i] = plaintext[i];
    }

    for(int i = 32; i < 64; i++){
        right[i - 32] = plaintext[i];
    }

   
    for(int i = 1; i <= 16; i++){
       
        mixer(left, right, keys[i-1]);
       
        if(i != 16){
            swapper(left, right);
            // printf("left: ");
            // bin_to_hex(left, 32);
            // printf("right: ");
            // bin_to_hex(right, 32);
        }
    }

    printf("The ciphertext in binary is: ");
    int k = 0;
    for(int i = 0; i < 32; i++){
        ciphertext[k] = left[i];
        printf("%d ", ciphertext[k]);
        k++;
    }
    for(int i = 0; i < 32; i++){
        ciphertext[k] = right[i];
        printf("%d ", ciphertext[k]);
        k++;
    }
    printf("\n");

    printf("The ciphertext in hexadecimal is: ");
    //char cipher_hex[16];
    bin_to_hex(ciphertext, 64);
    //printf("%s\n", cipher_hex);
    DES_decryption(ciphertext);
}


int main(){
    int plaintext[64], key[64];

    char plain_hex[16], key_hex[16];

    printf("Enter the plaintext: ");
    scanf("%[^\n]%*c", plain_hex);

    hex_to_bin(plain_hex, plaintext);
    for(int i = 0; i < 64; i++){
        printf("%d", plaintext[i]);
    }
    printf("\n");
    printf("Enter the Key: ");
    scanf("%[^\n]%*c", key_hex);

    hex_to_bin(key_hex, key);

    int new_key[56];
    parity_bit_drop(key, new_key);
   
    for(int i = 1; i <= 16; i++){
        generate_key(key, shift_table[i - 1], keys[i-1]);
    }

    DES_encryption(plaintext);
}