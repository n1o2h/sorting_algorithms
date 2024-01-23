#include "sort.h"

/**
 * quick_sort - sorts in ascending order using the Quick sort algorithm
 * @array: the array
 * @size: the size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	size_t flag = size - 1, s = 0, i, j;
	int cmp, pivot;

	if (!array || size <= 0)
		return;
	for (i = 0; i <= size - 1; i++)
	{
		pivot = array[flag];
		if (array[i] > pivot)
		{
			s = flag;
			cmp = pivot;
			for (j = i; j < size; j++)
			{
				if (array[j] < cmp)
				{
					s = j;
					cmp = array[j];
				}
			}
			array[s] = array[i];
			array[i] = cmp;
			print_array(array, size);
		}
		if (i == flag)
		{
			flag--;
			i = 0;
			if (!flag)
				break;
		}
	}
}
