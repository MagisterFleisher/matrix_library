matrix2 : main.c main.o myMatrix.c myMatrix.h myMatrix.o
	cc -o matrix1 main.o myMatrix.o -Wall -O0 -Wpedantic -lm -fsanitize=address -g

main.o : main.c
	cc -c main.c

myMatrix.o : myMatrix.h matrix_int.h matrix_int.c matrix_double.h matrix_double.c matrix_float.h matrix_float.c
	cc -c 

main_int.o : matrix_int.h matrix_int.c
	cc -c matrix_int.c

main_double.o : matrix_double.h matrix_double.c
	cc -c matrix_double.c

main_float.o : matrix_float.h matrix_float.c
	cc -c matrix_float.c


clean :
	rm main.o myMatrix.o