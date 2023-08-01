#ifndef DH_MODEL_H
#define DH_MODEL_H

#define N 6

//DH parameters of manioulator
extern double a_m[N];
extern double d_m[N];
extern double alpha_rad[N];

double degtorad(double degrees);

double** calculate_relation(double theta, double a, double d, double alpha);

#endif