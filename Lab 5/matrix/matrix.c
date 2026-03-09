#include <stdio.h>
#define SIZE 5

void printMatrix(int m1[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
           printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    int m3[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
    printMatrix(m3);
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    int m3[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            m3[i][j] = 0;
            for (int k = 0; k < SIZE; k++)
            {
                m3[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    printMatrix(m3);
}

void transposeMatrix(int m1[SIZE][SIZE]) {
    int m2[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            m2[i][j]=m1[j][i];
        }
    }
    printMatrix(m2);
}

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    if (sizeof(m1)/(SIZE*SIZE)!=sizeof(m2)/(SIZE*SIZE)||sizeof(m1)/(SIZE)!=sizeof(m2)/(SIZE)) 
    {
        printf("Invalid sizes for matrix addition.\n");
    }
    else 
    {
        printf("Adding the two matrices: \n");
        addMatrices(m1,m2);
    }
    if (sizeof(m1)/sizeof(m1[0])!=sizeof(m2[0])/sizeof(m2[0][0])) 
    {
        printf("\nInvalid sizes for matrix multiplication (m1m2).\n");
    }
    else
    {
        printf("\nMultiplying the two matrices (m1m2): \n");
        multiplyMatrices(m1,m2);
    }
    if (sizeof(m1[0])/sizeof(m1[0][0])!=sizeof(m2)/sizeof(m2[0])) 
    {
        printf("\nInvalid sizes for matrix multiplication (m2m1).\n");
    }
    else
    {
        printf("\nMultiplying the two matrices (m2m1): \n");
        multiplyMatrices(m2,m1);
    }
    printf("\nTransposing matrix m1: \n");
    transposeMatrix(m1);
    printf("\nTransposing matrix m2: \n");
    transposeMatrix(m2);
    return 0;
}