CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: myshell cat tail uniq

myshell: myshell.o
	$(CC) $(CFLAGS) -o myshell myshell.o

cat: cat.o
	$(CC) $(CFLAGS) -o cat cat.o

tail: tail.o
	$(CC) $(CFLAGS) -o tail tail.o

uniq: uniq.o
	$(CC) $(CFLAGS) -o uniq uniq.o

# Compile all C files
myshell.o: myshell.c
	$(CC) $(CFLAGS) -c myshell.c

cat.o: cat.c
	$(CC) $(CFLAGS) -c cat.c

tail.o: tail.c
	$(CC) $(CFLAGS) -c tail.c

uniq.o: uniq.c
	$(CC) $(CFLAGS) -c uniq.c

clean:
	rm -f myshell cat tail uniq *.o
