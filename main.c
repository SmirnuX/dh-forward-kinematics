#include "stdio.h"
#include "time.h"

#include "dh_model.h"
#include "matrix.h"

double theta_deg[N] = {20, -50, -60, 90, 50, 0};


int main()
{
    double start_time = (double)clock() / CLOCKS_PER_SEC;

    // Start alculating
    double** result = calculate_relation(degtorad(theta_deg[0]), a_m[0], d_m[0], alpha_rad[0]);

    for (int i = 1; i < N; i++)
    {
        double** next_rel = calculate_relation(degtorad(theta_deg[i]), a_m[i], d_m[i], alpha_rad[i]);
        double** next_link = mx_multiply(result, next_rel);
        free_4d_matrix(next_rel);
        free_4d_matrix(result);
        result = next_link;

        printf("(%f, %f)\n", result[0][3] * 100, result[2][3] * 100);
    }
    //End of calculating

    double end_time = (double)clock() / CLOCKS_PER_SEC;
    double run_time = end_time - start_time;

    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //         printf("%f ", result[i][j]);
    //     printf("\n");
    // }

    printf("x:  %f\n", result[0][3] * 100);
    printf("y:  %f\n", result[1][3] * 100);
    printf("z:  %f\n\n", result[2][3] * 100);

    printf("Time elapsed:  %fs\n", run_time);

    free_4d_matrix(result);
    return 0;
}