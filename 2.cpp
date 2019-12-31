#include <time.h>
#include <stdlib.h> //srand, rand
#include <iostream>
#include <omp.h>
#include <Eigen/Dense>

void gemm_omp(double *A, double *B, double *C, int n)
{
#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double dot = 0.0;
            for (int k = 0; k < n; k++)
                dot += A[i * n + k] * B[k * n + j];
            C[i * n + j] = dot;
        }
    }
}

void gemm(double *A, double *B, double *C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double dot = 0.0;
            for (int k = 0; k < n; k++)
            {
                dot += A[i * n + k] * B[k * n + j];
            }
            C[i * n + j] = dot;
        }
    }
}

void showMat(double *A, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%f ", A[i * n + j]);
        printf("\n");
    }
    printf("\n");
}

bool isEqual(double *A, double *B, int n)
{
    for (int i = 0; i < n*n; i++)
        if (A[i]!=B[i])
            return false;
    return true;
}

int main()
{
    //srand(time(NULL));
    int n = 1000;
    double *A = (double *)malloc(sizeof(double) * n * n);
    double *B = (double *)malloc(sizeof(double) * n * n);
    double *C = (double *)malloc(sizeof(double) * n * n);
    double *P = (double *)malloc(sizeof(double) * n * n);
    for (int i = 0; i < n * n; i++)
    {
        A[i] = rand()/RAND_MAX;
        B[i] = rand()/RAND_MAX;
    }
    double dtime = omp_get_wtime();
    gemm(A, B, C, n);
    dtime = omp_get_wtime() - dtime;
    printf("Multiplication of two %i*%i matrices\n",n,n);
    printf("Consequent: %f\n", dtime);
    dtime = omp_get_wtime();
    gemm_omp(A, B, P, n);
    dtime = omp_get_wtime() - dtime;
    bool e = isEqual(C,P,n);
    printf("Parallel:   %f\nSame result? %s\n", dtime, e ? "Yes" : "No");
    // if (!e)
    // {
    //     showMat(P,n);
    //     showMat(C,n);
    // }
    return 0;
}