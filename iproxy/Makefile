CC=g++
CFLAGS= -g -Wall -Werror

all: showip client server

showip: showip.c
	$(CC) $(CFLAGS) -o showip.o -c showip.c
	$(CC) $(CFLAGS) -o showip showip.o

client: client.c
	$(CC) $(CFLAGS) -o client.o -c client.c
	$(CC) $(CFLAGS) -o client client.o

server: server.c
	$(CC) $(CFLAGS) -o server.o -c server.c
	$(CC) $(CFLAGS) -o server server.o

clean:
	rm -rf showip server client *.o *.dSYM

tar:
	tar -cvzf client-server.tgz client.c server.c Makefile