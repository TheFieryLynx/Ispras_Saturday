define.o: define.c templates.h define.h stack.h functions.h vals.h \
 stack.c
functions.o: functions.c templates.h functions.h
main.o: main.c define.h templates.h stack.h functions.h
stack.o: stack.c
