CC = gcc
CFLAGS = -g -Wall -Werror -std=gnu11
LDFLAGS = -fsanitize=undefined -fsanitize=address
LIBS += -lm
DEBUG_FLAGS = -DCANARY

TARGETS = simple good
CFILES = *.c
HFILES = *.h
OFILES = $(CFILES: .c=.o)

simple : $(OFILES)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

good : $(OFILES)
	$(CC) $(LDFLAGS) $^ -DCANARY -DCHECK -o $@ $(LIBS)

include deps.make

deps.make : $(CFILES) $(HFILES)
	$(CC) -MM $(CFILES) > deps.make

clean: 
	-rm -f $(TARGETS) *.o deps.make
