#ifndef STACK_H_
#define STACK_H_

#include "stdint.h"

// ( ARRAY_IMPLEMENTATION, LINKED_IMPLEMENTATION )  
#define LINKED_IMPLEMENTATION



// a boolen value for the return of some functions.
typedef enum { FALSE = 0, TRUE = 1} BOOL;

typedef enum { STACK_NOK = 0, STACK_OK ,  STACK_FULL, STACK_EMPTY } EnumStackReturnStatus_t;

#ifdef ARRAY_IMPLEMENTATION

// create a structure for the required elements in the stack 
typedef struct {
    uint32_t capacity ;  // the maximum size of the stack 
    uint32_t size; // size oft the stack in the run time
    int32_t top;    // index where the pushing/popping is happening. 
    int32_t * Array; // pointer to an array which will be allocated dynmaically in the run time.
    // int32_t Array[MAXSIZE]; // in the implementation of creating a fixed size array in the stack itself. 
} STACK ;


STACK * STACK_Create (uint32_t StackCapacity);
BOOL STACK_Isfull (STACK * TheStackPtr );
BOOL STACK_IsEmpty (STACK * TheStackPtr);
EnumStackReturnStatus_t STACK_Push (STACK * TheStackPtr, int32_t item);
EnumStackReturnStatus_t STACK_Pop (STACK * TheStackPtr, int32_t * item);
#endif

#ifdef LINKED_IMPLEMENTATION

// create a structure for the node of the stack 
struct stacknode {
    int32_t data; // the data that node contains. 
    struct stacknode * next; // a pointer which points to the next node. 
};

typedef struct stacknode StackNode; 

typedef struct {
    StackNode * TheStackPtr; // stack pointer which points to where the elements are. 
} STACK;

STACK * STACK_Create (void);
void STACK_Push (STACK * PtrToStack , int32_t item);
EnumStackReturnStatus_t STACK_Pop (STACK * PtrToStack , int32_t * item);


#endif




#endif