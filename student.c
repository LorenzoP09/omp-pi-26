#include "student.h"
#include <stdlib.h>
#include <omp.h>

/* Parallelize this implementation. You may add includes and helper functions. */
static double get_rand_minus_one_one(void)
{
    return 2 * (rand() / (double)RAND_MAX) - 1;
}

double student_pi(long num_trials)
{

}
