#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://www.hackerrank.com/challenges/balanced-brackets/problem

char *readline();

// Complete the isBalanced function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//

struct node {
  int value;
  struct node* next;
};
typedef struct node* stack;

void push(stack* s, int value) {
  stack n = (stack) malloc(sizeof(struct node));
  n->value = value;
  n->next = (*s);

  (*s) = n;
}

int pop(stack *sRef)
{
  stack s = *sRef;
  // When expression starts with )] or }
  if (s == NULL) {
    return -1;
  };
  int v = s->value;
  *sRef = s->next;
  free(s);
  return v;
}
int ssize (stack s) {
  if (s == NULL) return 0;
  return ssize(s->next) + 1;
}

char *isBalanced(char *s)
{
  int l, c;
  stack st = NULL;
  while (*s != '\0')
  {
    c = *s++;
    if (c == '(' || c == '[' || c == '{'){
      push(&st, c);

    } else {
      l = pop(&st);
      if ((c == ')' && l != '(') ||
          (c == ']' && l != '[') ||
          (c == '}' && l != '{')) {
        return "NO";
      }
    }
  }
  if (st == NULL){
    return "YES";
  }
  return "NO";
}

int main()
{
  FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

  char *t_endptr;
  char *t_str = readline();
  int t = strtol(t_str, &t_endptr, 10);

  if (t_endptr == t_str || *t_endptr != '\0')
  {
    exit(EXIT_FAILURE);
  }

  for (int t_itr = 0; t_itr < t; t_itr++)
  {
    char *s = readline();

    char *result = isBalanced(s);

    fprintf(fptr, "%s\n", result);
  }

  fclose(fptr);

  return 0;
}

char *readline()
{
  size_t alloc_length = 1024;
  size_t data_length = 0;
  char *data = malloc(alloc_length);

  while (true)
  {
    char *cursor = data + data_length;
    char *line = fgets(cursor, alloc_length - data_length, stdin);

    if (!line)
    {
      break;
    }

    data_length += strlen(cursor);

    if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
    {
      break;
    }

    size_t new_length = alloc_length << 1;
    data = realloc(data, new_length);

    if (!data)
    {
      break;
    }

    alloc_length = new_length;
  }

  if (data[data_length - 1] == '\n')
  {
    data[data_length - 1] = '\0';
  }

  data = realloc(data, data_length);

  return data;
}
