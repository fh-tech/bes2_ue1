#Makefile fuer mycommand
all: myfind

myfind: *.c
	gcc -g -Wall -o myfind main.c

clean:
	rm -f myfind

