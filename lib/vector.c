// vector.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

void sum_vectors(int vec_size, double *vec_result, double *vec1, double *vec2)
{
    for (int i = 0; i < vec_size; i++)
        vec_result[i] = vec1[i] + vec2[i];
}

void mul_vector_by(int vec_size, double *vec_result, double *vec, double a)
{
    for (int i = 0; i < vec_size; i++)
        vec_result[i] = vec[i] * a;
}

void div_vector_by(int vec_size, double *vec_result, double *vec, double a)
{
    for (int i = 0; i < vec_size; i++)
        vec_result[i] = vec[i] / a;
}

double *create_vector(int size)
{
    int byte_size = sizeof(double) * size;
    double *ptr = (double *)malloc(byte_size);
    if (ptr == NULL) exit(1);
    memset(ptr, 0, byte_size);
    return ptr;
}

void remove_vector(double *vec)
{
    free(vec);
}