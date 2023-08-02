#ifndef DH_MODEL_H
#define DH_MODEL_H

#define N 6 //Number of nodes of manipulator

//DH parameters of manipulator
extern double a_m[N];
extern double d_m[N];
extern double alpha_rad[N];

double degtorad(double degrees);

void calculate_relation(double** result, double theta, double a, double d, double alpha);

#endif