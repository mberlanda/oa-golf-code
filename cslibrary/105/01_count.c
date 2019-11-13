#include "node.h"
#include <assert.h>

/*
 Given a list and an int, return the number of times that int occurs
 in the list.
*/
int Count(struct node* head, int searchFor) {
    struct node* current = head;
    int count = 0;

    for (current = head; current != NULL; current = current->next)
    {
        if (current->data == searchFor){
            count++;
        }
    }
    return count;
}

int main()
{
    struct node* myList = BuildOneTwoThree();
    int result = Count(myList, 2);

    printf("Count myList: %d\n", result);
    assert(result == 1);

    return 0;
}
