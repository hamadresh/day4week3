#include <stdio.h>
#include <stdlib.h>

int stack_pointer = -1;
int *ptr = NULL;  // Changed: Initialized global ptr to NULL; removed malloc from global scope.

void push_stack();
void pop_stack();
void display_stack();

int main()
{
    char command;
    int exit = 1;

    // Changed: Allocate initial memory for ptr here instead of as a global declaration.
    // Original code had `int *ptr = (int*) malloc(sizeof(int));` in `main`, which redefined `ptr` locally,
    // overshadowing the global `ptr` and causing other functions to work with uninitialized memory.
    ptr = (int*) malloc(sizeof(int));
    if (ptr == NULL) {  // Changed: Check if malloc was successful.
        printf("Memory allocation failed\n");
        return 1;  // Changed: Exits if memory allocation fails, avoiding further issues.
    }

    while (exit == 1)
    {
        printf("Enter a command (p - push, o - pop, d - display, e - exit): \n");
        scanf(" %c", &command);
        switch (command)
        {
            case 'p':
                push_stack();
                break;
            case 'o':
                pop_stack();
                break;
            case 'd':
                display_stack();
                break;
            case 'e':
                exit = 0;  // Changed: Set exit to 0 to break the loop. Original code set exit to 1, making it infinite.
                break;
            default:
                printf("Invalid command. Try again.\n");
        }
    }

    free(ptr);  // Changed: Added memory deallocation for `ptr` to prevent memory leaks.
    return 0;
}

void push_stack()
{
    int pushed_var;
    printf("Insert an integer to push: \n");
    scanf("%d", &pushed_var);

    stack_pointer++;  // Changed: Increment stack_pointer directly. Original code had stack_pointer + 1 in realloc call.

    // Changed: Reallocate memory to expand the stack.
    // Original code incorrectly used `*ptr = (int*) realloc(*ptr, ...)`, dereferencing `ptr` and causing a memory error.
    // Now, we use `realloc` directly on `ptr` and assign to a temporary pointer to check for NULL.
    int *temp_ptr = (int*) realloc(ptr, (stack_pointer + 1) * sizeof(int));
    if (temp_ptr == NULL) {  // Changed: Added check for NULL to ensure reallocation was successful.
        printf("Memory reallocation failed\n");
        stack_pointer--;  // Changed: Undo stack_pointer increment if reallocation fails.
        return;
    }
    ptr = temp_ptr;  // Changed: Update global pointer with new memory address after realloc.

    ptr[stack_pointer] = pushed_var;  // Changed: Correctly assigns the pushed value to the new stack position.
    printf("Pushed %d onto the stack\n", pushed_var);
}

void pop_stack()
{
    if (stack_pointer < 0) {  // Changed: Added a condition to check if the stack is empty before popping.
        printf("Stack is empty. Nothing to pop.\n");
        return;
    }

    int popped_var = ptr[stack_pointer];
    printf("Popped int is %d\n", popped_var);

    stack_pointer--;  // Changed: Decrement stack_pointer to reflect the removed element.

    // Changed: Reallocate memory to shrink the stack.
    // Original code incorrectly used `*ptr = (int*) realloc(*ptr, ...)`. Fixed by removing the dereference and updating ptr.
    int *temp_ptr = (int*) realloc(ptr, (stack_pointer + 1) * sizeof(int));
    if (temp_ptr != NULL || stack_pointer == -1) {  // Changed: Allow NULL if stack is empty to avoid a dangling pointer.
        ptr = temp_ptr;  // Changed: Update ptr only if realloc succeeds.
    }
}

void display_stack()
{
    if (stack_pointer < 0) {  // Changed: Added a condition to check if the stack is empty before displaying.
        printf("Stack is empty.\n");
        return;
    }

    for (int i = 0; i <= stack_pointer; i++) {
        printf("Stack position %d: %d\n", i, ptr[i]);
    }
}

