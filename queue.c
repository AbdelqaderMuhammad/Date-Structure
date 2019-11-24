#include"stdio.h"
#include"stdlib.h"
#include"stdint.h"

#include "queue.h"


#ifdef ARRAY_IMPLEMENTATION

// function to create a queue. 
QUEUE * QUEUE_Create (int32_t QueueCapacity)
{
    QUEUE * PtrToQueueStr = (QUEUE *) malloc (sizeof(QUEUE));  // initalize queue structure in heap
    PtrToQueueStr -> size = 0;
    PtrToQueueStr -> capacity = QueueCapacity;
    PtrToQueueStr -> front = 0;
    PtrToQueueStr -> rear = QueueCapacity - 1;
    PtrToQueueStr -> QueueArray = (int32_t *) malloc (sizeof (int32_t) * QueueCapacity);

    return PtrToQueueStr;
}

// function to check if queue is full 
EnumQueueReturnStatus_t QUEUE_Isfull ( QUEUE * PtrToQueue )
{
    if (PtrToQueue -> size == PtrToQueue -> capacity )
    {
        return QUEUE_FULL;
    }
    else 
    {
        return QUEUE_NOK;
    }
}

// function to check if queue is empty 
EnumQueueReturnStatus_t QUEUE_Isempty ( QUEUE * PtrToQueue )
{
    if (PtrToQueue -> size == 0 )
    {
        return QUEUE_EMPTY;
    }
    else 
    {
        return QUEUE_NOK;
    }
}

// function to enqueue in queue.
EnumQueueReturnStatus_t QUEUE_Enqueue ( QUEUE * PtrToQueue, int32_t item )
{
    // check if the queue is full 
    if ( QUEUE_Isfull(PtrToQueue) )
        return QUEUE_NOK;
    // there is a place to enqueu.
    PtrToQueue -> rear = ( (PtrToQueue -> rear) + 1) % ( PtrToQueue -> capacity );  // update the rear position as circular queueu. 
    PtrToQueue -> QueueArray [PtrToQueue -> rear] = item;
    PtrToQueue -> size++;
    return QUEUE_OK;
}

// function to dequeue in queue
EnumQueueReturnStatus_t QUEUE_Dequeue ( QUEUE * PtrToQueue, int32_t * item )
{
    // check if the queue is Empty 
    if ( QUEUE_Isempty(PtrToQueue) )
        return QUEUE_NOK;
    // there is an element to dequeue it 
    *item = PtrToQueue -> QueueArray [PtrToQueue -> front];
    PtrToQueue -> front = ( (PtrToQueue -> front) +1) % (PtrToQueue ->capacity);
    PtrToQueue -> size++;
    return QUEUE_OK;
}


#endif

#ifdef LINKED_IMPLEMENTATION

// function to create a queue. 
QUEUE * QUEUE_Create (void)
{
    QUEUE * PtrToQueue = (QUEUE *) malloc ( sizeof(QUEUE) );  // init the queue structure
    PtrToQueue -> front = PtrToQueue -> rear = NULL;
    PtrToQueue -> size = 0;
    return PtrToQueue;    
}

// function to create a new node
static QueueNode * QUEUE_Newnode(int32_t item)
{
    QueueNode * PtrToNode = (QueueNode *) malloc (sizeof (QueueNode));
    PtrToNode -> data = item;
    PtrToNode -> next = NULL;
    return PtrToNode;
}


// function to enqueu in the queue. 
void QUEUE_Enqueue (QUEUE * PtrToQueue, int32_t item )
{
    QueueNode * PtrToNode = QUEUE_Newnode (item);   // create a node with an item given.

    if (PtrToQueue -> rear == NULL){  // check if there is no node in the queue. 
        PtrToQueue -> front = PtrToQueue -> rear = PtrToNode; // both rear and front will be pointing to the same node. 
        return;
    }
    PtrToQueue -> rear -> next = PtrToNode; // make the rear points to the last node enqueued.
    PtrToQueue -> rear = PtrToNode;  
    PtrToQueue -> size++;
}

// function to dequeue in queue
EnumQueueReturnStatus_t QUEUE_Dequeue ( QUEUE * PtrToQueue, int32_t * item )
{
    if (PtrToQueue -> front == 0)
        return QUEUE_NOK;
    *item = PtrToQueue -> front -> data;  // return the value in the variable. 
    QueueNode * temp = PtrToQueue -> front; // create a pointer to hold the first node 
    PtrToQueue -> front = PtrToQueue -> front -> next; // makes the front pointer points to the previous node.
    free(temp); // free the memeory of the node 
    if (PtrToQueue -> front == NULL){ // check if the front reached the null if so 
        PtrToQueue -> rear = NULL; // make sure the rear will be null as well.
    } 
    return QUEUE_OK;
}

#endif