/*
 *  Source code written by Gabriel Correia
*/

#ifndef PRNG_H
#define PRNG_H

#include <stdlib.h>

#include "time-stamp.h"

void sprng (uint64_t local_seed);

int32_t prngi (void);

/* Returns only positive values (The absolute number value) */
int32_t inline aprngi (void)
{
    return abs ( prngi ());
}

#endif

