CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-g
OBJS=mytee binomial ppcm

ifneq (clean, $(firstword $(MAKECMDGOALS)))
	ifneq (all, $(firstword $(MAKECMDGOALS)))
		ifneq (mrproper, $(firstword $(MAKECMDGOALS)))
				EXEC := $(wordlist 1, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
		endif
	endif
endif

all: $(OBJS)

$(EXEC): $(EXEC).o
	$(CC) -o $@ $^ $(LDFLAGS)
	@make clean

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o

mrproper:
	@make clean
	rm -f $(OBJS)
	rm -rf *.dSYM
