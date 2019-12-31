#include <iostream> //cout, printf
#include <time.h>
#include <stdlib.h> //srand, rand
#include <Eigen/Dense>

//without any parallelism because such requirement was described after the second task
int main()
{
    srand(time(NULL));
    int rows = 8;
    int cols = 8;
    Eigen::MatrixXi a = Eigen::MatrixXi::Random(rows, cols);
    std::cout << a << std::endl;
    int max = INT32_MIN;
    for (int i = 0; i < cols; i++)
    {
        int min = INT32_MAX;
        for (int j = 0; j < rows; j++)
        {
            if (a(i, j) < min)
                min = a(i, j);
        }
        if (max<min)
            max=min;
    }
    std::cout << max;
    return 0;
}