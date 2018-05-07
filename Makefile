#Makefile fuer mycommand
all: mycommand

mycommand: *.c
	gcc -g -Wall -o mycommand main.c

clean:
	rm -f mycommand

