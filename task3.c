#include <stdio.h>
#include <stdlib.h>'

int save_samples_and_return_num_samples(int *ptr);
float find_avg(int *ptr, int num_samples);

int main()
{
	int num_samples;
	int *ptr = (int*) malloc(sizeof(int));
	float average;
	int i;


	if (ptr == NULL)
        {
                // check if memory reallocation was successful
                printf("Memory reallocation failed.\n");
                return 1;
        }



	num_samples=save_samples_and_return_num_samples(ptr);
	printf("number of samples with function is %d\n", num_samples);
	average = find_avg(ptr, num_samples);
	printf("average is %f \n", average);
	printf("new samples are: \n");
	
	// to print our new array after subtracting the mean
	float *ptr1 = (float*) malloc(num_samples*sizeof(float));

        if (ptr1 == NULL)
        {
                // check if memory reallocation was successful
                printf("Memory reallocation failed.\n");
                return 1;
        }


	
	for(i=0;i<num_samples;i++)
	{
		ptr1[i]=(float)ptr[i]-average;
		printf("%f ", ptr1[i]);
	}
	printf("\n");
	free(ptr1);
	free(ptr);
}

int save_samples_and_return_num_samples(int *ptr)
{
	char user_reply;
	int sample;
	int i=2;

	do
	{
		printf("Enter a sample integer value: \n");
		scanf("%d", &sample);

		ptr[i-2]= sample;
		
		printf("Do you want to add more samples?\n");
		scanf(" %c", &user_reply);

		ptr = (int*) realloc(ptr, i * sizeof(int));
		i=i+1;
	} while(user_reply=='y');
	return i-2;
}

float find_avg(int *ptr, int num_samples)
{
	int i;
	int sum=0;
	float average;

	for(i=0;i<num_samples;i++)
	{
		sum=ptr[i]+sum;
	}
	
	average = (float)sum/ num_samples;
	return average;
}
