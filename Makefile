CC = cc
CFLAGS = -Wall -O0 -Wpedantic -lm -fsanitize=address -g
SRC = main.c matrix_int.c matrix_double.c matrix_float.c
OBJ = $(SRC:.c=.o)
DEPS = myMatrix.h

all: matrix

matrix : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean 
clean :
	rm main.o myMatrix.o main_int.o main_float.o main_double.o 

#
# matrix1 : main.c main.o myMatrix.c myMatrix.h myMatrix.o
#	cc -o matrix1 main.o myMatrix.o -Wall -O0 -Wpedantic -lm -fsanitize=address -g
#
# main.o : main.c
#	cc -c main.c
# myMatrix.o : myMatrix.c myMatrix.h
#	cc -c myMatrix.c
#
# clean :
#	rm main.o myMatrix.o