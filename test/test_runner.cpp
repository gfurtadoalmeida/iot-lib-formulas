#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, char **av)
{
#if CONFIG_IOT_LIB_FORMULAS_USE_FLOAT == 1
    printf("Type used: float \n");
#else
    printf("Type used: double \n");
#endif

    return RUN_ALL_TESTS(ac, av);
}
