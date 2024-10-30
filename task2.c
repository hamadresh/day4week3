#include <stdio.h>
#include <stdlib.h>

int length_sentence(char ch_arr[]);

int main() 
{
        char ch_arr[100];
	int i;
	int length;

	printf("insert your sentence \n");
        scanf("%[^\n]%*c", ch_arr);
        
	length = length_sentence(ch_arr);
	
	char *ptr = (char*) malloc(length * sizeof(char));

	if (ptr == NULL) 
	{ 
		// check if memory reallocation was successful
		printf("Memory reallocation failed.\n");
		return 1;
	}
	
	// save in reverse
	for(i=length; i>=1; i--)
	{
		ptr[i-1]= ch_arr[length-i];
	}
	
	printf("reversed sentence is: \n");
	// print the pointer values
	for(i=0; i<length; i++)
	{
		printf("%c",ptr[i]);
	}
	printf("\n");
	
	free(ptr);
}

int length_sentence(char ch_arr[]){
        int i;
        for(i=0;i<=99;i++)
        {
                if ((char)ch_arr[i] == '\0' )
                {
			return i;
                        break;
                }
        }
}
