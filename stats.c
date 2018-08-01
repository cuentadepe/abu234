/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);

  find_mean(test, SIZE);

  find_maximum(test, SIZE);

  find_minimum(test, SIZE);

  sort_array(test, SIZE);

  find_median(test, SIZE);
}

/* Add other Implementation File Code Here */

void print_array(const unsigned char *ipArray,
		         const unsigned int iArraySize)
{
	int i = 0;
	while (i < iArraySize)
	{
		printf("%d ", *(ipArray + i));
		i++;
	}
	printf("\n");
}

void find_median(unsigned char *iopArray,
		         const unsigned int iArraySize)
{
	//sort array
	int i = 0;
	while (i < iArraySize)
	{
		int j = 0;
		while (j < iArraySize)
		{
			if(*(iopArray + i) < *(iopArray + j))
			{
				unsigned char tmp = *(iopArray + i);
				*(iopArray + i) = *(iopArray + j);
				*(iopArray + j) = tmp;
			}
			j++;
		}
		i++;
	}
	print_array(iopArray, SIZE);


	//middle pair
	if((iArraySize % 2) == 0)
	{
		int indx = (iArraySize / 2);
		float sup = (*(iopArray + indx) + *(iopArray + indx - 1));
		float median = sup/2;
		printf("median: %f\n", median);
	}
	else
	{
		int indx = (iArraySize / 2);
		printf("median: %d\n", *(iopArray + indx));

	}
}


void find_mean(const unsigned char *ipArray,
		         const unsigned int iArraySize)
{
	int i = 0;
	int sum = 0;
	float mean = 0;
	while (i < iArraySize)
	{
		sum += *(ipArray + i);
		i++;
	}

	mean = sum/iArraySize;

	printf("mean: %f\n", mean);
}

void find_maximum(const unsigned char *ipArray,
		          const unsigned int iArraySize)
{
	int i = 0;
	int max = *(ipArray + i);
	while (i < iArraySize)
	{
		if (*(ipArray + i) > max)
			max = *(ipArray + i);
		i++;
	}

	printf("maximun: %d\n", max);
}

void find_minimum(const unsigned char *ipArray,
		          const unsigned int iArraySize)
{
	int i = 0;
	int min = *(ipArray + i);
	while (i < iArraySize)
	{
		if (*(ipArray + i) < min)
			min = *(ipArray + i);
		i++;
	}

	printf("minimun: %d\n", min);
}

void sort_array(unsigned char *iopArray,
		        const unsigned int iArraySize)
{
	int i = 0;
	while (i < iArraySize)
	{
		int j = 0;
		while (j < iArraySize)
		{
			if(*(iopArray + i) > *(iopArray + j))
			{
				unsigned char tmp = *(iopArray + i);
				*(iopArray + i) = *(iopArray + j);
				*(iopArray + j) = tmp;
			}
			j++;
		}
		i++;
	}

	print_array(iopArray, SIZE);
}
