CC = gcc
CFLAGS = -g -Wall -Werror -std=gnu11
LDFLAGS = -fsanitize=undefined -fsanitize=address 
LIBS += -lm

TARGETS = run
CFILES = main.c functions.c tests.c
HFILES = headerfile.h
OFILES = $(CFILES: .c=.o)

all: run

run : $(OFILES)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

include deps.make

deps.make : $(CFILES) $(HFILES)
	$(CC) -MM $(CFILES) > deps.make

clean: 
	-rm -f $(TARGETS) *.o deps.make Output/*.txt
