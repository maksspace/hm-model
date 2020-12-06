#include <stdio.h>
#include <stdlib.h>
#include "lib/vector.h"
#include "lib/rkf.h"

double f(double x, double i);
double calc_root(double x0, double x1, double h, double i);

int main(int argc, char *argv[])
{

    FILE *output = fopen("stable_point_output/output.csv", "w");
    double x0 = -2.0;
    double x1 = 5.0;
    double i0 = 0;
    double i1 = 30;
    double h = 0.000001;
    for (double i = i0; i <= i1; i += 0.1)
    {
        double x_root = calc_root(x0, x1, h, i);
        fprintf(output, "%f,%f\n", i, x_root);
    }
}

inline double f(double x, double i)
{
    return -(x * x * x) - 2 * (x * x) - 4 * (x + 1.6) + 1 + i;
}

double calc_root(double x0, double x1, double h, double i)
{
    for (double x = x0; x <= x1; x += h)
    {
        double f_x = f(x, i);
        if (f_x <= h)
        {
            return x;
        }
    }
}