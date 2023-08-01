#ifndef MATRIX_H
#define MATRIX_H

double** create_4d_matrix();
void free_4d_matrix(double** mx);

double** mx_multiply(double** mx1, double** mx2);

#endif