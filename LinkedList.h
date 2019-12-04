#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

// create structure node for doubly linked list 
typedef struct node {
    // pointer to the previous node
    struct node * Previous;  
    // the data itself 
    int32_t Data;
    // pointer to the next node 
    struct node * Next;
} NODE;

void Push (NODE ** PtrToHead, int32_t NewData );
void Append (NODE ** PtrToHead, int32_t NewData);
void InsertAfter (NODE *PtrToPreNode , int32_t NewData );
void InsertBefore (NODE ** PtrToHead, uint32_t Pos ,int32_t NewData);
void PrintList (NODE ** PtrToHead);


#endif