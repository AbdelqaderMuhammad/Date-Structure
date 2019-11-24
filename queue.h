#ifndef QUEUE_H_
#define QUEUE_H_

#include "stdint.h"


// ARRAY_IMPLEMENTATION, LINKED_IMPLEMENTATION
#define LINKED_IMPLEMENTATION



typedef enum { FALSE = 0, TRUE = 1} BOOL;

typedef enum { QUEUE_NOK = 0, QUEUE_OK ,  QUEUE_FULL, QUEUE_EMPTY } EnumQueueReturnStatus_t;



#ifdef ARRAY_IMPLEMENTATION

typedef struct {

    uint32_t front; // the first element will get out in dequeue.
    uint32_t rear; // the position where the element enqueus.
    uint32_t size; // the number of elements in the queue. 
    int32_t capacity;  // the capacity of the queue. 
    int32_t * QueueArray; // the queue where the elements will be stored. 

} QUEUE;

QUEUE * QUEUE_Create (int32_t QueueCapacity);
EnumQueueReturnStatus_t QUEUE_Isfull ( QUEUE * PtrToQueue );
EnumQueueReturnStatus_t QUEUE_Isempty ( QUEUE * PtrToQueue );
EnumQueueReturnStatus_t QUEUE_Enqueue ( QUEUE * PtrToQueue, int32_t item );
EnumQueueReturnStatus_t QUEUE_Dequeue ( QUEUE * PtrToQueue, int32_t * item );

#endif

#ifdef LINKED_IMPLEMENTATION

typedef struct queuenode {
    int32_t data;  // where the data will be in the node
    struct queuenode * next ; // pointer which points to the next element. 
} QueueNode;


typedef struct {
    QueueNode * front; // where the dequeue happening
    QueueNode * rear; // where the enqueue happening
    int32_t size; // the current size of the queue
} QUEUE;


QUEUE * QUEUE_Create (void);
void QUEUE_Enqueue (QUEUE * PtrToQueue, int32_t item );
EnumQueueReturnStatus_t QUEUE_Dequeue ( QUEUE * PtrToQueue, int32_t * item );

#endif






#endif