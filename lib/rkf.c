#include "vector.h"

void rkf_solve(
    double t0,
    double t1,
    double *vec_n,
    int vec_size,
    void (*f)(double *vec_result,
              double *vec_n, double t),
    void (*f_step)(double *vec_n, double t),
    double h)
{
    double *k1 = create_vector(vec_size);
    double *k2 = create_vector(vec_size);
    double *k3 = create_vector(vec_size);
    double *k4 = create_vector(vec_size);
    double *vec_temp = create_vector(vec_size);

    for (double t = t0; t <= t1; t += h)
    {
        f(vec_temp, vec_n, t);
        mul_vector_by(vec_size, k1, vec_temp, h);

        div_vector_by(vec_size, vec_temp, k1, 2);
        sum_vectors(vec_size, vec_temp, vec_temp, vec_n);
        f(vec_temp, vec_temp, t + h / 2);
        mul_vector_by(vec_size, k2, vec_temp, h);

        div_vector_by(vec_size, vec_temp, k2, 2);
        sum_vectors(vec_size, vec_temp, vec_temp, vec_n);
        f(vec_temp, vec_temp, t + h / 2);
        mul_vector_by(vec_size, k2, vec_temp, h);

        sum_vectors(vec_size, vec_temp, vec_n, k3);
        f(vec_temp, vec_temp, t + h);
        mul_vector_by(vec_size, k4, vec_temp, h);

        mul_vector_by(vec_size, k2, k2, 2);
        mul_vector_by(vec_size, k3, k3, 2);
        sum_vectors(vec_size, k2, k2, k3);
        sum_vectors(vec_size, k1, k1, k2);
        sum_vectors(vec_size, k1, k1, k4);
        div_vector_by(vec_size, k1, k1, 6);
        sum_vectors(vec_size, vec_n, k1, vec_n);

        f_step(vec_n, t);
    }

    remove_vector(k1);
    remove_vector(k2);
    remove_vector(k3);
    remove_vector(k4);
    remove_vector(vec_temp);
}