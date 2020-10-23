#ifdef TYPE    
#include "templates.h"  

#if 0
    __________________________________________
    | top_canary | some data | bottom_canary |
    ‾‾‾‾‾‾‾‾‾‾‾‾‾^‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
                 |    stack->data
#endif

//=================================================================================================

#ifdef CHECK
void TEMPLATE(CheckStack, TYPE)(TEMPLATE(Stack, TYPE) *stack)
{
    if (stack->size < 0) {
        fprintf(stderr, "Error message : size error\n");
        _exit(1);
    }
    if (stack->capacity < 0) {
        fprintf(stderr, "Error message : capacity error\n");
        _exit(1);
    }
#ifdef CANARY
    if (stack->top_canary != CANARY_VALUE) {
        fprintf(stderr, "Error message : top canary error\n");
        _exit(1);
    }
    if (stack->bottom_canary != CANARY_VALUE) {
        fprintf(stderr, "Error message : bottom canary error\n");
        _exit(1);
    }
    if (*((CANARY_TYPE *)stack->data - 1) != CANARY_VALUE) {
        fprintf(stderr, "Error message : data top canary erroe\n");
        _exit(1);
    }
    if (*((CANARY_TYPE *)(stack->data + stack->capacity)) != CANARY_VALUE) {
        fprintf(stderr, "Error message : data top canary erroe\n");
        _exit(1);
    }
#endif
}
#endif

//=================================================================================================

void TEMPLATE(Constructor, TYPE)(TEMPLATE(Stack, TYPE) *stack, ssize_t capacity) 
{
   
#ifdef CANARY
    void *allocated_memory = calloc(capacity * sizeof(TYPE) + 2 * sizeof(CANARY_TYPE), sizeof(*allocated_memory)); 
    if (!allocated_memory) {
        fprintf(stderr, "Error message : Allocation error\n");
        _exit(1);
    }
    CANARY_TYPE *top_canary = (CANARY_TYPE *)allocated_memory;
    *top_canary = CANARY_VALUE;
    CANARY_TYPE *bottom_canary = (CANARY_TYPE *)(allocated_memory + sizeof(CANARY_TYPE) + capacity * sizeof(TYPE));
    *bottom_canary = CANARY_VALUE;
    stack->top_canary = CANARY_VALUE;
    stack->bottom_canary = CANARY_VALUE;
    stack->data = (TYPE *)(allocated_memory + sizeof(CANARY_TYPE));
#else
    void *allocated_memory = calloc(capacity, sizeof(TYPE));
    if (!allocated_memory) {
        fprintf(stderr, "Error message : Allocation error\n");
        _exit(1);
    }
    stack->data = (TYPE *)allocated_memory;
#endif
    stack->capacity = capacity;
    stack->size = 0;

#ifdef CHECK
    TEMPLATE(CheckStack, TYPE)(stack);
#endif
}

//=================================================================================================

void TEMPLATE(Destructor, TYPE)(TEMPLATE(Stack, TYPE) *stack) 
{
#ifdef CHECK
    TEMPLATE(CheckStack, TYPE)(stack);
#endif

#ifdef CANARY
    free((CANARY_TYPE *)stack->data - 1);
#else
    free(stack->data);
#endif
    stack->data = NULL;
    stack->size = 0;
    stack->capacity = 0;
}

//=================================================================================================

void TEMPLATE(Push, TYPE)(TEMPLATE(Stack, TYPE) *stack, TYPE value) 
{
#ifdef CHECK
    TEMPLATE(CheckStack, TYPE)(stack);
#endif
    
    if (stack->size == stack->capacity) {
        stack->capacity <<= 1;
    }
#ifdef CANARY
    void *allocated_memory = realloc((char *)stack->data - sizeof(CANARY_TYPE), stack->capacity * sizeof(TYPE) + 2 * sizeof(CANARY_TYPE));
#else
    void *allocated_memory = realloc(stack->data, stack->capacity * sizeof(TYPE));
#endif
    if(!allocated_memory) {
        fprintf(stderr, "Error message : Allocation error\n");
        _exit(1);
    }

#ifdef CANARY
    CANARY_TYPE *top_canary = (CANARY_TYPE *)allocated_memory;
    *top_canary = CANARY_VALUE;
    CANARY_TYPE *bottom_canary = (CANARY_TYPE *)(allocated_memory + sizeof(CANARY_TYPE) + stack->capacity * sizeof(TYPE));
    *bottom_canary = CANARY_VALUE;
    stack->top_canary = CANARY_VALUE;
    stack->bottom_canary = CANARY_VALUE;
    stack->data = (TYPE *)(allocated_memory + sizeof(CANARY_TYPE));
#else
    stack->data = (TYPE *)allocated_memory;
#endif

    stack->data[stack->size] = value;
    stack->size += 1;
}

//=================================================================================================

TYPE TEMPLATE(Pop, TYPE)(TEMPLATE(Stack, TYPE) *stack) 
{
#ifdef CHECK
    TEMPLATE(CheckStack, TYPE)(stack);
#endif
    if (stack->size <= 0) {
        fprintf(stderr, "Error message : Stack is empty\n");
        _exit(1);
    }
    TYPE value = stack->data[stack->size - 1];
    stack->size -= 1;
    return value;
}

//=================================================================================================
#endif 