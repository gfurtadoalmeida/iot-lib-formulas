#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, char **av)
{
#if IOT_LIB_FORMULAS_USE_FLOAT
    printf("Type used: float \n");
#else
    printf("Type used: double \n");
#endif

    return RUN_ALL_TESTS(ac, av);
}
