#include <stdio.h>
#include <stdlib.h>
#include "lib/vector.h"
#include "lib/rkf.h"

void f(double *vec_result, double *vec_n, double t);
void f_step_print(double *vec_n, double t);

double A = 3;
double U = 0.0021;
double R = 4;
double C = 1.6;
double H = 1;
double t0 = 0;
double t1 = 10000;
double h = 0.001;
double I = 3.26;
FILE *output;

int main(int argc, char *argv[])
{
    char *i_str = argv[1];
    char *t1_str = argv[2];
    char *h_str = argv[3];
    char *output_path = argv[4];
    double vec_n[3] = {0, 0, 0};
    int steps = (int)(t1 - t0) / h;

    I = atof(i_str);
    t1 = atof(t1_str);
    h = atof(h_str);
    output = fopen(output_path, "w");
    printf("Calc I = %f, t1 = %f, h = %f, steps = %d\n", I, t1, h, steps);
    rkf_solve(t0, t1, vec_n, 3, f, f_step_print, h);
}

void f(double *vec_result, double *vec_n, double t)
{
    double x = vec_n[0];
    double y = vec_n[1];
    double z = vec_n[2];
    vec_result[0] = y + A * (x * x) - (x * x * x) - z + I;
    vec_result[1] = H - 5 * x * x - y;
    vec_result[2] = U * (R * (x + C) - z);
}

void f_step_print(double *vec_n, double t)
{
    fprintf(output, "%f,%f\n", t, vec_n[0]);
}