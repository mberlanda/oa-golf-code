#include "node.h"

/*
 Given a list and an int, return the number of times that int occurs
 in the list.
*/
int Count(struct node* head, int searchFor) {
    struct node* current = head;
    int count;

    for (current = head; current != NULL; current = current->next)
    {
        if (current->data == searchFor) count++;
    }
    return count;
}

int main()
{
    struct node* myList = BuildOneTwoThree();
    if (Count(myList, 2) == 1)
    {
        return 0;
    }
    return 1;
}