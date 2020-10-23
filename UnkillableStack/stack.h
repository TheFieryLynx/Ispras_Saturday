#ifdef TYPE    
#include "templates.h"   
#include "functions.h" 

typedef struct TEMPLATE(Stack, TYPE) {
#ifdef CANARY
    CANARY_TYPE top_canary;
#endif
    ssize_t size;
    ssize_t capacity;
    TYPE *data;
#ifdef CANARY
    CANARY_TYPE bottom_canary;
#endif
} TEMPLATE(Stack, TYPE);

void TEMPLATE(Constructor, TYPE)(TEMPLATE(Stack, TYPE) *stack, ssize_t capacity);
void TEMPLATE(Destructor, TYPE)(TEMPLATE(Stack, TYPE) *stack);
void TEMPLATE(Push, TYPE)(TEMPLATE(Stack, TYPE) *stack, TYPE value);
TYPE TEMPLATE(Pop, TYPE)(TEMPLATE(Stack, TYPE) *stack);
#endif 