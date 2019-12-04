#include"stdio.h"
#include"stdlib.h"
#include"stdint.h"

#include"LinkedList.h"

// function to add a node at the beginning of the linked list. 
void Push (NODE ** PtrToHead, int32_t NewData )
{
    // allocate a node
    NODE * new_node = (NODE *) malloc ( sizeof(NODE) ); 
    // insert the new data 
    new_node ->Data = NewData;
    // previous and the next pointer
    new_node ->Previous = NULL;
    new_node ->Next = (*PtrToHead);
    // head pointer
    // 1. if the head pointer does not point to null (there is a node)
    if ( (*PtrToHead) != NULL)
        (*PtrToHead) ->Previous = new_node;
    // 2. the head pointer points to null (empty linked list)
    (*PtrToHead) = new_node; 
} 


// function to add a node at the end of the linked list 
void Append (NODE ** PtrToHead, int32_t NewData)
{
    // create a local pointer to the head in case of loop to the end of the list 
    NODE * last = (*PtrToHead); 
    // allocate node
    NODE *new_node = (NODE *) malloc( sizeof(NODE) ); 
    // insert data 
    new_node ->Data = NewData; 
    // previous and the next pointer
    new_node ->Next = NULL;
    // if the list is empty previous will point to null otherwise will point to the last node.
    if ( (*PtrToHead) == NULL ){
        new_node ->Previous = NULL;
        (*PtrToHead) = new_node;
        return;
    }
    // get the last node
    while(last ->Next != NULL){
        // move to the next node till you stop at the last node 
        last = last -> Next; 
    }
    // next of the last node will be pointed to new node  
    last ->Next = new_node;
    // previous of the new node will be pointing to last node 
    new_node ->Previous = last;

}


// function to add a node after a certain node
void InsertAfter (NODE *PtrToPreNode , int32_t NewData )
{
    // allocate a node 
    NODE * new_node = (NODE *) malloc (sizeof(NODE));
    // allocate the data 
    new_node ->Data = NewData;
    // the next of the new node will be pointing to what the node points to 
    new_node ->Next = PtrToPreNode ->Next;
    // now the old next will be pointing to the new node
    PtrToPreNode ->Next = new_node;
    // previous of the new node will point to the latter node 
    new_node ->Previous = PtrToPreNode;
    // if the following node exits make sure the previous pointer will point to the new node 
    if(new_node ->Next != NULL){
        // the previous of the following node will be pointing to new node if the following node exists  
        new_node ->Next ->Previous = new_node;
    }
}

// function to add a node before a certain node 
void InsertBefore (NODE ** PtrToHead, uint32_t Pos ,int32_t NewData)
{
    // positions starts from node 1 to the end of the nodes in the linked list 
    // local variable for looping to reach the position 
    NODE * temp = (*PtrToHead);
    // allocate a node with the new data 
    NODE * new_node = (NODE *) malloc ( sizeof(NODE) );
    new_node ->Data = NewData;

    if (Pos == 1){
        new_node ->Previous = NULL;
        new_node ->Next = (*PtrToHead);
        (*PtrToHead) ->Previous = new_node;
        (*PtrToHead) = new_node;
        return;
    } 
    // loop on the list till you reach the node allocates at that position. 
    for(int i = 0; i<Pos-1; i++){
        temp = temp ->Next;
    }
    // temp will be pointing to the previous node.
    temp = temp ->Previous;
    // the new node will be pointing to the next node of the temp pointer 
    new_node ->Next = temp ->Next;
    // the previous of it will be pointing to the node of temp pointer.
    new_node ->Previous = temp;
    // check if there is a node to be pointing to the new node
    if (temp ->Next != NULL)
        temp ->Next ->Previous = new_node;
    // now the latter node is pointing to the new node.
    temp ->Next = new_node;
}


// function to print the list 
void PrintList (NODE ** PtrToHead)
{
    // local temp pointer for looping 
    NODE * temp = (*PtrToHead);
    // loop on each node till you reach the end
    while(temp != NULL){
        // print the data and move to the next node 
        printf("%d ", temp->Data);
        temp = temp ->Next;
    } 
}