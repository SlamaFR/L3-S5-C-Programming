INCL    := stack.h calculator.h
SRC     := main.c stack.c calculator.c
OBJ     := $(SRC:.c=.o)
LIBS    := -lreadline -lm
EXE     := mydc

CC      := /usr/local/Cellar/gcc/10.2.0/bin/gcc-10
CFLAGS  := -ansi -pedantic -Wall -O2
LIBPATH := -L.
LDFLAGS := -o $(EXE) $(LIBPATH) $(LIBS)
RM      := rm -f

%.o: %.c
	$(CC) -c $(CFLAGS) $*.c

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ)

$(OBJ): $(INCL)

clean:
	$(RM) $(OBJ)