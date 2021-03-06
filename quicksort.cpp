// quicksort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"

int randompartiton(int p, int q, int* A);
int partiton(int p, int q, int* A);
void Quicksort(int p, int q,int* A);
void RandomQuicksort(int p, int q, int* A);
int main()
{
	int a[] = { 7,2,4,11,3,6,15,16,1 };
	int i;
	RandomQuicksort(0, 8, a);
	for (i = 0; i < 9; i++)
		printf("%d ", a[i]);
	while (1);
    return 0;
}

int partiton(int p,int q,int* A)
{
	int i, j, var;
	i = p;
	for (j = p + 1; j <= q; j++)
	{
		if (A[p] > A[j])
		{
			i++;
			var = A[i];
			A[i] = A[j];
			A[j] = var;
		}
	}
	var = A[p];
	A[p] = A[i];
	A[i] = var;
	return i;
}

void Quicksort(int p,int q,int* A)
{
	int i;
	if (p < q)
	{
		i = partiton(p, q, A);
		Quicksort(p, i - 1, A);
		Quicksort(i + 1, q, A);
	}
}

int randompartiton(int p, int q, int* A)
{
	int i, j, var;
	i = (rand() % (q - p)) + p;
	var = A[p];
	A[p] = A[i];
	A[i] = var;
	i = p;
	for (j = p + 1; j <= q; j++)
	{
		if (A[p] > A[j])
		{
			i++;
			var = A[i];
			A[i] = A[j];
			A[j] = var;
		}
	}
	var = A[p];
	A[p] = A[i];
	A[i] = var;
	return i;
}

void RandomQuicksort(int p, int q, int* A)
{
	int i;
	if (p < q)
	{
		i = randompartiton(p, q, A);
		RandomQuicksort(p, i - 1, A);
		RandomQuicksort(i + 1, q, A);
	}
}