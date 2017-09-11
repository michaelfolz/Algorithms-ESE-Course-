#include <stdio.h>
#include <stdlib.h>


void BubbleSort(int a[], int array_size);
void insertionSort(int a[], int array_size);
void SelectionSort(int a[], int array_size);
void heapsort(int a[], int array_size);
void downHeap(int a[], int root, int bottom);

int unsorted_array[5] = { 4, 2, 1, 3, 5 };

int main()
{
	int count = 0;

	printf("\n Contents of the unsorted array\n ");
	for (count = 0; count < 5; count++)
		printf("%d", unsorted_array[count]);

	BubbleSort(unsorted_array, 5);


	printf("\n Contents of the unsorted array\n ");
	for (count = 0; count < 5; count++)
		printf("%d", unsorted_array[count]);
	return 0;
}



void BubbleSort(int a[], int array_size)
{
	int i, j, temp;
	for (i = 0; i < (array_size - 1); ++i)
	{
		for (j = 0; j < array_size - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

void insertionSort(int a[], int array_size)
{
	int i, j, index;
	for (i = 1; i < array_size; ++i)
	{
		index = a[i];
		for (j = i; j > 0 && a[j - 1] > index; j--)
			a[j] = a[j - 1];

		a[j] = index;
	}
}


void SelectionSort(int a[], int array_size)
{
	int i;
	for (i = 0; i < array_size - 1; ++i)
	{
		int j, min, temp;
		min = i;
		for (j = i + 1; j < array_size; ++j)
		{
			if (a[j] < a[min])
				min = j;
		}

		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

void heapsort(int a[], int array_size)
{
	int i;
	for (i = (array_size / 2 - 1); i >= 0; --i)
	{
		downHeap(a, i, array_size - 1);
	}

	for (i = array_size - 1; i >= 0; --i)
	{
		int temp;
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		downHeap(a, 0, i - 1);
	}
}

void downHeap(int a[], int root, int bottom)
{
	int maxchild, temp, child;
	while (root * 2 < bottom)
	{
		child = root * 2 + 1;
		if (child == bottom)
		{
			maxchild = child;
		}
		else
		{
			if (a[child] > a[child + 1])
				maxchild = child;
			else
				maxchild = child + 1;
		}

		if (a[root] < a[maxchild])
		{
			temp = a[root];
			a[root] = a[maxchild];
			a[maxchild] = temp;
		}
		else return;

		root = maxchild;
	}

}






