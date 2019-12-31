#include <iostream>
#include <omp.h>

double f(double x)
{
    return 4.0 / (1 + x * x);
}

int main()
{
    int n = 14 * 1e5;
    float a = 0.0;
    float b = 1.0;
    double h = (b - a) / n;
    for (int k = 0; k < 10; k++)
    {
        double sum = .0;
        if (k%2)
            printf("Parallel   ");
        else
            printf("Consequent ");
        double before = omp_get_wtime();
        #pragma omp parallel for reduction(+ : sum) if (k%2)
        for (int i = 0; i < n; i++)
        {
            sum += f(a + h * i);
        }
        double duration = omp_get_wtime() - before;
        sum *= h;
        printf("%f %f\n", duration, sum);
    }
    return 0;
}