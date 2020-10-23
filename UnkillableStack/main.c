#include "define.h"  
int main(int argc, char **argv)  
{   
    Stack_int stack;
    Constructor_int(&stack, 6);
    Push_int(&stack, 1);
    Push_int(&stack, 2);
    Push_int(&stack, 3);
    Push_int(&stack, 4);
    Push_int(&stack, 5);
    Push_int(&stack, 6);
    
    int a = Pop_int(&stack);
    print_int(a);
    a = Pop_int(&stack);
    print_int(a);
    a = Pop_int(&stack);
    print_int(a);
    a = Pop_int(&stack);
    print_int(a);
    a = Pop_int(&stack);
    print_int(a);
    a = Pop_int(&stack);
    print_int(a);
    Destructor_int(&stack);

    return 0;       
}