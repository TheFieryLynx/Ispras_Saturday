#ifndef ALL_TEMPLATES_C_   
    #define ALL_TEMPLATES_C_     
    #include "templates.h"  
    #include "define.h"
    #include "vals.h"
    
    #define TYPE int 
    #ifdef TYPE  
        #include "stack.c"
        #undef TYPE  
    #endif  

    #define TYPE double  
    #ifdef TYPE  
        #include "stack.c"  
        #undef TYPE  
    #endif  
#endif