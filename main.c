#include "stdio.h"
#include "stdlib.h"
#include "errno.h"

#include "dh_model.h"
#include "matrix.h"

double* get_from_file(char* fname)
{
    FILE* file = fopen(fname, "r");
    if (file == NULL)
        return NULL;

    double* result = malloc(sizeof(double) * N);
    for (int i = 0; i < N; i++)
    {
        if (fscanf(file, "%lf", result + i) != 1)
        {
            free(result);
            return NULL;
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    double* theta_deg = NULL;
    if (argc < 2)
        theta_deg = get_from_file("input.txt");
    else
        theta_deg = get_from_file(argv[1]);

    if (theta_deg == NULL)
    {
        if (errno == 0)
            printf("File error: wrong format of file.\n");
        else
            perror("File error: ");
        return errno;
    }

    double** result = create_4d_matrix();
    double** transform_mx = create_4d_matrix();
    double** temp_result = create_4d_matrix();
    calculate_relation(result, degtorad(theta_deg[0]), a_m[0], d_m[0], alpha_rad[0]);

    for (int i = 1; i < N; i++)
    {
        calculate_relation(transform_mx, degtorad(theta_deg[i]), a_m[i], d_m[i], alpha_rad[i]);
        mulptiply_4d_matrix(temp_result, result, transform_mx);

        double** tmp = result; 
        result = temp_result;
        temp_result = tmp;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%f ", result[i][j]);
        printf("\n");
    }

    printf("x:  %f m\n", result[0][3]);
    printf("y:  %f m\n", result[1][3]);
    printf("z:  %f m\n\n", result[2][3]);

    free(theta_deg);
    delete_4d_matrix(result);
    delete_4d_matrix(transform_mx);
    delete_4d_matrix(temp_result);

    return 0;
}