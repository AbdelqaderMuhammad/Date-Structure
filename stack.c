#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stack.h"

// 2 implementation either as an array or using linked list. 
// by using the array method to create a stack we might allocate it by using dynamic memory allocation or fixed size. 
// by using liked list implementation 


/*************************** ARRAY IMPLEMENTATION *********************************/

#ifdef ARRAY_IMPLEMENTATION

// function to create a stack 
STACK * STACK_Create (uint32_t StackCapacity)
{
    // create a sized stack in the heap and holds it with a pointer 
    STACK * StackPtr = (STACK *) malloc( sizeof(STACK) );
    // assign some values to the variables in the stack 
    StackPtr -> top = -1; // because stack is empty.
    StackPtr -> size = 0; // doesn't have any element.
    StackPtr -> capacity = StackCapacity; // the maximum size of the stack 
    StackPtr -> Array = (int32_t *) malloc ( sizeof (int32_t) * StackCapacity );  // assign a pointer to a dynmaically allocated array to hold the elements in stack
    return StackPtr;
}

// function to check if the stack is full.
BOOL STACK_Isfull (STACK * TheStackPtr )
{
    if ( (TheStackPtr -> top) == (TheStackPtr -> capacity - 1) )
    {
        return TRUE;
    }
    else 
    {
        return FALSE;
    } 
}


// function to check if the stack is empty.
BOOL STACK_IsEmpty (STACK * TheStackPtr)
{
    if ( TheStackPtr -> size == 0)
    {
        return TRUE;
    }
    else 
    {
        return FALSE;
    } 

}


// function to push in the stack 
EnumStackReturnStatus_t STACK_Push (STACK * TheStackPtr, int32_t item)
{
    if (STACK_Isfull(TheStackPtr))  // check if the stack is full 
     {
        return STACK_FULL;
     }
     else 
     {
        *(TheStackPtr -> Array + ( ++ TheStackPtr -> top) ) = item;  // enter the item in the stack.
        TheStackPtr -> size++;
        return STACK_OK;
     }  
    
}


// function to pop from the stack 
EnumStackReturnStatus_t STACK_Pop (STACK * TheStackPtr, int32_t * item)
{
    if (STACK_IsEmpty(TheStackPtr) )
    {
        return STACK_EMPTY;
    }
    else 
    {
        *item = TheStackPtr -> Array[TheStackPtr -> top --];
        TheStackPtr -> size--;
        return STACK_OK;
    }
}

#endif

#ifdef LINKED_IMPLEMENTATION

// function to create a node. 
static StackNode * STACK_NewNode (int32_t item)
{
    StackNode * PtrNode = (StackNode *) malloc ( sizeof( StackNode ) ); // create a node with the size of stack node.
    PtrNode -> data = item;
    PtrNode -> next = 0;
    return PtrNode;   
}

// function to create a stack 
STACK * STACK_Create (void)
{
    STACK * PtrToTheStackMembers = (STACK *) malloc ( sizeof(STACK) ); // create a stack 
    PtrToTheStackMembers -> TheStackPtr = NULL;
    return PtrToTheStackMembers; 
}

// function to push an element in the stack. 
void STACK_Push (STACK * PtrToStack , int32_t item)
{
    StackNode * PtrToNode = STACK_NewNode(item); // created a node with the item.
    PtrToNode -> next = PtrToStack -> TheStackPtr;  // make the next points to what the stack pointer points to. 
    PtrToStack -> TheStackPtr = PtrToNode; // the stack pointer points to the node itself.  
}

EnumStackReturnStatus_t STACK_Pop (STACK * PtrToStack , int32_t * item)
{
    if (PtrToStack -> TheStackPtr == NULL) // check if the stack is empty 
        return STACK_EMPTY;
        
    *item = PtrToStack -> TheStackPtr -> data; // return the value of the last element
    StackNode * temp = PtrToStack -> TheStackPtr; // holds the last node with a temp variable. 
    PtrToStack -> TheStackPtr = PtrToStack -> TheStackPtr -> next; // stack pointer will points to the following element. 
    free(temp); // free the node from the memory.
    return STACK_OK;
}


#endif