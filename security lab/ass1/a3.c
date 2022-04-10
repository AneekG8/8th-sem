#include<stdio.h>

void get_cofactor(int mat[4][4], int cofactors[4][4], int r, int c, int mat_size)
{
    int i = 0, j = 0;
 
    for (int row = 0; row < mat_size; row++)
    {
        for (int col = 0; col < mat_size; col++)
        {
            //  Storing those element which are not in given row and column into temporary matrix
            if (row != r && col != c)
            {
                cofactors[i][j++] = mat[row][col];
 
                if (j == mat_size - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int get_determinant(int A[4][4], int size)
{
    int  determinant = 0; 
 
    if (size == 1)
        return A[0][0];
 
    int temp[4][4]; // To store cofactors
 
    int sign = 1;  // To store sign multiplier
 
     // Iterate for each element of first row
    for (int f = 0; f < size; f++)
    {
        // Getting Cofactor of A[0][f]
        get_cofactor(A, temp, 0, f, size);
        determinant += sign * A[0][f] * get_determinant(temp, size - 1);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return determinant;
}

void get_adjoint_matrix(int mat[4][4], int adj_mat[4][4], int mat_size){
    if (mat_size == 1)
    {
        adj_mat[0][0] = 1;
        return;
    }
 
    
    int sign = 1, cofactors[mat_size][mat_size];
 
    for (int i = 0; i < mat_size; i++)
    {
        for (int j = 0; j < mat_size; j++)
        {
            // Get cofactor of mat[i][j]
            get_cofactor(mat, cofactors, i, j, mat_size);
 
            // sign of adj[j][i] positive if sum of row and column indexes is even.
            sign = ((i + j) % 2 == 0)? 1: -1;
 
            // Interchanging rows and columns to get the transpose of the cofactor matrix
            adj_mat[j][i] = (sign) * (get_determinant(cofactors, mat_size - 1));
        }
    }
}
int main(){
    int size, n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the size of the matrix: ");
    scanf("%d", &size);
    
    int mat[size][size];
    printf("Enter the elements of the matrix: ");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    int adj_mat[size][size];
    printf("\nAdjoint matrix is : \n");
    get_adjoint_matrix(mat, adj_mat, size);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
    }

}