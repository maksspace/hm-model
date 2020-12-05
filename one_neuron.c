#include <stdio.h>
#include "lib/vector.h"
#include "lib/rkf.h"

void f(double *vec_result, double *vec_n, double t);
void f_step_print(double *vec_n, double t);

FILE *dataTOutput;
FILE *dataXOutput;
double A = 3;
double I = 3.26;
double U = 0.0021;
double R = 4;
double C = 1.6;
double H = 1;
double t0 = 0;
double t1 = 10000;
double h = 0.01;

int main()
{
    dataTOutput = fopen("output/dataT.csv", "w");
    dataXOutput = fopen("output/dataX.csv", "w");

    double vec_n[3] = {0};
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
    fprintf(dataTOutput, "%f\n", t);
    fprintf(dataXOutput, "%f\n", vec_n[0]);
}