#include <stdio.h>
#include <stdlib.h>

int stack_pointer=-1;
int *ptr=NULL;

void push_stack();
void pop_stack();
void display_stack();
int main()
{
	char command;
	int exit=1;
	ptr = (int*) malloc(sizeof(int));
	if (ptr == NULL) 
	{
        printf("failed\n");
        return 1;
	}

	
	while(exit == 1)
	{
		printf("p for push, o for pop, d for display, e for exit: \n");
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
				exit =0;
				break;
			default:
				printf("wrong input\n");
		}
	}
	free(ptr);
	return(0);
}


void push_stack()
{
	int pushed_var;
	printf("insert an integer to push \n");
	scanf("%d", &pushed_var);
	

	stack_pointer = stack_pointer + 1;
	ptr = (int*) realloc(ptr, (stack_pointer+1) * sizeof(int));
	if (ptr == NULL) 
	{
        printf("failed\n");
        return 1;
	}
	ptr[stack_pointer] = pushed_var;
	printf("stack pointer value is %d\n", stack_pointer);
}
void pop_stack()
{
	int popped_var;
	popped_var = ptr[stack_pointer];
	printf("popped int with value %d\n", popped_var);

	stack_pointer=stack_pointer-1;
	ptr = (int*) realloc(ptr, (stack_pointer+1) * sizeof(int));
	if (ptr == NULL) 
	{
        printf("failed\n");
        return 1;
	}
}
void display_stack()
{
	int i;
	for(i=0; i<=stack_pointer; i++)
	{
		printf("Stack in position %d, is: %d \n", i, ptr[i]);
	}
}
