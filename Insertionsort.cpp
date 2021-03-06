// Insertionsort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
void merge(int *mn,int n);

int main()
{
	int a[] = { 3, 7, 12, 1, 4, 10, 6, 21,14 };
	int i, j, n;
#if 0
	for (i = 1; i < 10; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[i] < a[j])
			{
				n = a[i];
				a[i] = a[j];
				a[j] = n;
			}
		}
	}
	
#endif // 0
	merge(a, 9);
	for (i = 0; i<9; i++)
		printf("%d ", a[i]);
	while (1);
    return 0;
}

void merge(int *mn, int n)
{
	int i,key1,key2;
	int sort[20];
	key1 = 0;
	key2 = n / 2;
	if(n!=1)
	{ 
	if ((n-key2) != 1)
	{
		merge(mn , key2);
		merge(mn + key2, n-key2);
	}
	for (i = 0; i < n; i++)
	{
		if (mn[key1] < mn[key2])
		{
			sort[i] = mn[key1];
			key1++;
			if (key1 == (n / 2 ))
			{
				i++;
				for (; i < n; i++)
				{
					sort[i] = mn[key2++];
				}
				break;
			}
		}
		else
		{
			sort[i] = mn[key2];
			key2++;
			if (key2 == n )
			{
				i++;
				for (; i < n; i++)
				{
					sort[i] = mn[key1++];
				}
				break;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		mn[i] = sort[i];
		printf("%d ", mn[i]);
		
	}printf("\n");
	}
}

