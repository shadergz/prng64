/*
 *  Source code written by Gabriel Correia
*/

#include "prng.h"

/*  The seed used to help the calculation and to provide a 
 *  better general randomization values
*/
static uint64_t seed = 0;

/* Set the currently seed */
void sprng (uint64_t local_seed)
{
    uint mask = 0;

    if (!local_seed) {
        seed = getts ();
        /* Overwrite the MSB with zeros */
        mask = (uint)(1 << 31) - 1;
        seed &= mask;
    } else {
        seed = local_seed;
    }
}

int32_t prngi (void)
{
    uint64_t n = seed;
    /*
        λ = n >> 60
        f(x) = x² + x * λ / 2
        100
         Σ f(k)
        k=1
    */

    for (int k = 1; k <= 100; k++)
        n += (uint32_t) k * k + k * (n >> 60) / 2; 
    /* Updating the current seed value */
    seed += n * n;

    return (int32_t)n;
}

