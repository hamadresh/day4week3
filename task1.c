#include <stdio.h>
#include <stdlib.h>

void multiplication(int a, int b, int *ptr, int vector_size);
void main()
{
	int vector_size;
	int a;
	int b;
	int vectora_elem;
	int vectorb_elem;
	int i;

	printf("give me the size of the first vector\n");
	scanf("%d", &vector_size);

	printf("read value of a \n");
	scanf("%d", &a);

	printf("read value of b \n");
	scanf("%d", &b);

	int *ptr = (int*) malloc(vector_size*3 * sizeof(int));
	if (ptr == NULL)
        {
                // check if memory reallocation was successful
                printf("Memory reallocation failed.\n");
                return 1;
        }


	for(i=0; i< vector_size; i++)
	{
		printf("insert the value for vector a\n");
		scanf("%d", &vectora_elem);
		ptr[i] = vectora_elem;
	}

	for(i=0; i< vector_size; i++)
	{
		printf("insert the value for vector b\n");
		scanf("%d", &vectorb_elem);
		ptr[i+vector_size] = vectorb_elem;
	}
	multiplication(a,b, ptr, vector_size);
	free(ptr);
}

void multiplication(int a, int b, int *ptr, int vector_size)
{
	/* multiply by a and b */
	printf("value of z is \n");
	int i;
	for(i=0; i<vector_size;i++)
	{
		ptr[i] = ptr[i]*a;
		ptr[i+vector_size]=ptr[i+vector_size]*b;
		ptr[i+vector_size*2]=ptr[i+vector_size]+ptr[i];
		printf("%d ", ptr[i+vector_size*2]);
	}
	printf("\n");

}
