project1b: main.c cell.c cell.h
	gcc -c main.c cell.c cell.h
	gcc -o project1b main.o cell.o cell.h

