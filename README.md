# prng64

- A Pseudo-random number generator that can use the TSC (Time Stamp Counter) from the host processor

## Usage examples

- With BY_TIME 1 (Using the current raw time as seed)

```c
sprng (time (NULL));
```

- With BY_RANDOM_FILE 1 (Using the pseudo random file from an Unix env)

```c
#if defined (__unix__)
int pseudo = 0;
int fd = open ("/dev/random", O_RDONLY);
read (fd, &pseudo, sizeof (int));
close (fd);
#endif
```

- With TSC (BY_TIME 0 && BY_RANDOM_FILE 0)

```c
sprng (0);
```

## How to build

```bash
make
```

## How to clean

```bash
make clean
```
