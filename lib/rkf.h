void rkf_solve(
    double t0,
    double t1,
    double *vec_n,
    int vec_size,
    void (*f)(double *vec_result,
              double *vec_n, double t),
    void (*f_step)(double *vec_n, double t),
    double h);
