#include "node.h"
#include <assert.h>

// Given a list and an index, return the data
// in the nth node of the list. The nodes are numbered from 0.
// Assert fails if the index is invalid (outside 0..lengh-1).
int GetNth(struct node* head, int index) {
    struct node* current = head;
    int count = 0;

    for (current = head; current != NULL; current = current->next)
    {
        if (count == index) {
            return current->data;
        }
        count++;
    }
    assert(0);
}

int main()
{
    struct node* myList = BuildOneTwoThree();
    int result = GetNth(myList, 1);

    printf("Count GetNth: %d\n", result);
    assert(result == 2);

    return 0;
}
