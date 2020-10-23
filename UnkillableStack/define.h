#ifndef ALL_TEMPLATES_H_   
    #define ALL_TEMPLATES_H_     
    #include "templates.h"  

    #define TYPE int 
    #ifdef TYPE  
        #include "stack.h"
        #undef TYPE  
    #endif  

    #define TYPE double  
    #ifdef TYPE  
        #include "stack.h"  
        #undef TYPE  
    #endif  
#endif