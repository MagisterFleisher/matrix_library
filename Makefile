CC = cc
CFLAGS = -Wall -O0 -Wpedantic -lm -fsanitize=address -g
SRC = main.c matrix_int.c matrix_double.c matrix_float.c
OBJ = $(SRC:.c=.o)
DEPS = myMatrix.h matrix_int.h matrix_double.h matrix_float.h

all: matrix

matrix : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean :
	rm main.o myMatrix.o main_int.o main_float.o main_double.o 