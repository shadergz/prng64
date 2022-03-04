CC=clang
CFLAGS=-Wall -O2 -ffast-math
ASM=yasm

EXE=prng_x86
EXE_FORMAT=elf64

ASMFLAGS=-f $(EXE_FORMAT)

PRNG_X86_C_OBJS=\
	prng.o\
	main.o\

PRNG_X86_ASM_OBJS=\
	time-stamp.$(EXE_FORMAT)

all: $(EXE)

$(EXE): $(PRNG_X86_C_OBJS) $(PRNG_X86_ASM_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.$(EXE_FORMAT): %.asm
	$(ASM) $(ASMFLAGS) -o $@ $<	

clean:
	rm -f $(EXE) $(PRNG_X86_C_OBJS) $(PRNG_X86_ASM_OBJS)

.PHONY: all clean
