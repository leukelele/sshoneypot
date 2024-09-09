CC = gcc
CFLAGS = -g -Wall
CHMOD := $(shell which chmod)
SETCAP := $(shell which setcap)
USER := $(shell whoami)

all: sshoneypot

sshoneypot: main.o
	$(CC) $(CFLAGS) $^ -lssh -o $@

main.o: main.c config.h
	$(CC) $(CFLAGS) -c main.c

clean:
	\/bin/rm -f *.o sshoneypot
