#ifndef TEMPLATES_H_
    #define TEMPLATES_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <errno.h>
    #define CAT(X, Y) X##_##Y
    #define TEMPLATE(X, Y) CAT(X, Y)
    typedef unsigned long long CANARY_TYPE; 
#endif  