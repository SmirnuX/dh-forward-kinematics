#include "matrix.h"
#include "stdlib.h"


double** create_4d_matrix()
{
    double** result = malloc(sizeof(double*) * 4);
    for (int i = 0; i < 4; i++)
        result[i] = malloc(sizeof(double) * 4);

    return result;
}

void delete_4d_matrix(double** mx)
{
    for (int i = 0; i < 4; i++)
        free(mx[i]);
    free(mx);
}

double** mx_4d_multiply(double** mx1, double** mx2)
{
    double** result = create_4d_matrix();

    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result[i][j] = 0.0;
            for(int k = 0; k < 4; k++)
                result[i][j] += mx1[i][k] * mx2[k][j];
        }
    }

    return result;
}