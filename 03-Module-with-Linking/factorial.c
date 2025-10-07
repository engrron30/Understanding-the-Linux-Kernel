#include "factorial.h"

int factorial(int n)
{
    int result = 1;
    int i;
    for (i = 1; i <= n; i++)
        result *= i;
    return result;
}
