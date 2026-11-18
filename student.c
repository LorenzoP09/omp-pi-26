#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <errno.h>

// 
// The monte carlo pi program
//

double get_rand_minus_one_one(){
    return 2 * (rand_r() / (double)RAND_MAX) - 1;
}

double student_pi(long num_trials) {
  unsigned int base = (unsigned int)rand();
  unsigned int seed = 0;
  long Ncirc = 0;
  int seeded = 0; 

  //For now, we're using the default scheduler
  # pragma omp parallel for private(x) private(y) reduction(+: Ncirc)
    for (long i = 0; i < num_trials; i++) {
      if (!seeded) {
        seed = base_seed ^ ((unsigned int)(omp_get_thread_num() + 1) * 2654435761u);
        seeded = 1;
      }
      double x = get_rand_minus_one_one();
      double y = get_rand_minus_one_one();
      
      if (x*x + y*y <= 1.0) {
        ++Ncirc;
      }
    }
  return 4.0 * (double)Ncirc / (double)num_trials;
}
