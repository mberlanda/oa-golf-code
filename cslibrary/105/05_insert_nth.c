#include "node.h"
#include <assert.h>

/*
int* ListData(struct node** listRef, int count)
{
    struct node* current = *listRef;

    if (count == 0){
        return NULL;
    }
    
    int* items = malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        int item = current->data;
        items[i] = item;
        current = current->next;
    }
    return items;
} 
*/

void InsertNth(struct node** headRef, int index, int data);
void InsertNth(struct node** headRef, int index, int data)
{
    if (index == 0) {
        Push(headRef, data);
    } else {
        struct node* current = *headRef;
        int count = 0;
        
        while (count < index - 1) {
            assert(current != NULL);
            current = current->next;
            count ++;
        }

        assert(current != NULL);
        Push(&(current->next), data);
    }
}

void InsertNthTest();
void InsertNthTest()
{
    struct node* head = NULL;
    InsertNth(&head, 0, 13);
    PrintValues(head); // 13

    InsertNth(&head, 1, 42);
    PrintValues(head); // 13 42

    InsertNth(&head, 1, 5);
    PrintValues(head); // 13 5 42

    // DeleteList(&head);
}

int main(){
    InsertNthTest();
}