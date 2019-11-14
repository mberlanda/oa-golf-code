#include "node.h"
#include <assert.h>

/*
    Write a SortedInsert() function which given a list that is sorted in increasing order,
    and a single node, inserts the node into the correct sorted position in the list. While
    Push() allocates a new node to add to the list, SortedInsert() takes an existing node,
    and just rearranges pointers to insert it into the list. There are many possible
    solutions to this problem.
*/


void SortedInsert(struct node** headRef, struct node* newNode)
{
    assert(newNode != NULL);

    struct node* current = *headRef;
    struct node* next;

    if(current == NULL) { // edge case: headRef empty
        *headRef = newNode;
        return;
    }

    while(newNode->data > current->data)
    {
        next = current->next;
        if (next == NULL){ // edge case: new data greater than max
            break;
        }
        current = next;
    }

    next = current->next; // // edge case: new data smaller than min
    newNode->next = next;
    current->next = newNode;
}

void SortedInsertLocalRef(struct node** headRef, struct node* newNode)
{
    struct node** currentRef = *headRef;

    while(*currentRef != NULL && (*currentRef)->data < newNode->data){
        currentRef = &((*currentRef)->next);
    }
    newNode->next = currentRef;
    *currentRef = newNode;
}