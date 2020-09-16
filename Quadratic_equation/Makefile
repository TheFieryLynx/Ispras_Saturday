CC = gcc
CFLAGS = -g -Wall -Werror -std=gnu11
LDFLAGS = -fsanitize=undefined -g
LIBS += -lm


TARGETS = m
CFILES = main.c func.c tests.c
HFILES = head.h
OFILES = $(CFILES: .c=.o)

all: m

m : $(OFILES)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

include deps.make

deps.make : $(CFILES) $(HFILES)
	$(CC) -MM $(CFILES) > deps.make

clean: 
	-rm -f $(TARGETS) *.o deps.make
