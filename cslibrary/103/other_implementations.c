#include "node.h"

/* Dummy Header
  empty single dummy instead of NULL
  + no node** in Push implementation
  - memory allocation also for NULL values
*/

/* Circular
  tail.next = &head;
*/

/* Tail Pointer
  + operations such as Add
*/

/* HeadStruct */
struct HeadStruct
{
  struct node* head;
  struct node* tail;
  int size;
};

/* Double-Linked */
struct DoubleLinked
{
  int data;
  struct node* previous;
  struct node* next;
};

/* Chunk List
  Several elements per node
  + better performances
*/

/* Dynamic Arrays
  realloc()
  + access to contigous areas of the memory
*/
