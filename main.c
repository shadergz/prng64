/*
 *  Source code written by Gabriel Correia
*/

#include <stdio.h>
#include <time.h>

#include "prng.h"

#if defined (__unix__)
#include <fcntl.h>
#include <unistd.h>
#endif


/*  Generate a seed from the actual time, isn't a good idea 
 *  if u want more noise 
*/
#define BY_TIME 0

/*  If the seed as given from a pseudo random file or other function,
 *  the randomization is done with more noise
*/

#define BY_RANDOM_FILE 0

int main (int argc, char **argv)
{
#if BY_TIME
    sprng (time (NULL));
#elif BY_RANDOM_FILE

    int pseudo = 0;
#if defined (__unix__)
    int fd = open ("/dev/random", O_RDONLY);
    read (fd, &pseudo, sizeof (int));
    close (fd);
#endif

    sprng (pseudo);

#else
    /* Setting the seed value from the current TSC value */
    sprng (0);

#endif

    puts ("Pseudo random numbers: ");
    for (int i = 0; i < 26; i++)
        printf ("%d ", aprngi () % 100);
    puts ("");
    
    return 0;
}

