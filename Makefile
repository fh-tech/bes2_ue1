#Makefile fuer mycommand
all: myfind

myfind: *.c
	gcc -g -Wall -o myfind *.c

clean:
	rm -f myfind *.o

