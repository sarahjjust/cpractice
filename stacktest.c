#include "stack.c"

int main(void)
{
  struct node *stack = init();
  for (int i = 0; i <= 5; i++) {
    push(i, &stack);
  }
  printf("Peek 2: %d\n", peek(2, stack));
  
  while(stack->next != NULL) {
    printf("%d\n", pop(&stack));
  }

  free(stack);

  return 0;
}
