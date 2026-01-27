matrix1 : main.c main.o myMatrix.c myMatrix.h myMatrix.o
	cc -o matrix1 main.o myMatrix.o -Wall -O0 -Wpedantic -lm -fsanitize=address -g

main.o : main.c
	cc -c main.c
myMatrix.o : myMatrix.c myMatrix.h
	cc -c myMatrix.c

clean :
	rm main.o myMatrix.o