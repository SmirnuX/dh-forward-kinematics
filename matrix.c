#include "matrix.h"
#include "stdlib.h"


double** create_4d_matrix()
{
    double** result = malloc(sizeof(double*) * 4);
    for (int i = 0; i < 4; i++)
        result[i] = malloc(sizeof(double) * 4);

    return result;
}

void** mulptiply_4d_matrix(double** result, double** mx1, double** mx2)
//Multiply matrices "mx1" and "mx2", and store outcome in "result"
{
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result[i][j] = 0.0;
            for(int k = 0; k < 4; k++)
                result[i][j] += mx1[i][k] * mx2[k][j];
        }
    }
}

void delete_4d_matrix(double** mx)
{
    for (int i = 0; i < 4; i++)
        free(mx[i]);
    free(mx);
}