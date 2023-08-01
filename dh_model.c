#include "dh_model.h"
#include "matrix.h"
#include "math.h"


double a_m[N] = {0.0, -0.8, -0.598, 0.0, 0.0, 0.0};
double d_m[N] = {0.21, 0.193, -0.16, 0.25, 0.25, 0.25};
double alpha_rad[N] = {M_PI/2, 0.0, 0.0, M_PI/2, -M_PI/2, 0.0};

double degtorad(double degrees)
{
    return M_PI * degrees / 180;
}

double** calculate_relation(double theta, double a, double d, double alpha)
{
    double cost = cos(theta);
    double sint = sin(theta);
    double cosa = cos(alpha);
    double sina = sin(alpha);

    double** result = create_4d_matrix();
    result[0][0] = cost;
    result[0][1] = - sint * cosa;
    result[0][2] = sint * sina;
    result[0][3] = a * cost;

    result[1][0] = sint;
    result[1][1] = cost * cosa;
    result[1][2] = - cost * sina;
    result[1][3] = a * sint;

    result[2][0] = 0.0;
    result[2][1] = sina;
    result[2][2] = cosa;
    result[2][3] = d;

    result[3][0] = 0.0;
    result[3][1] = 0.0;
    result[3][2] = 0.0;
    result[3][3] = 1.0;

    return result;
}