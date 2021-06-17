#include "../push_swap.h"

static void	ft_swap(long int *a, long int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	heapify(long int *tab, int n, int i)
{
	int	largest;
	int	left;
	int	right;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < n && tab[left] > tab[largest])
		largest = left;
	if (right < n && tab[right] > tab[largest])
		largest = right;
	if (largest != i)
	{
		ft_swap(&tab[i], &tab[largest]);
		heapify(tab, n, largest);
	}
}

void	new(long int *tab, int len)
{
	int	i;

	i = len / 2 - 1;
	while (i >= 0)
	{
		heapify(tab, len, i);
		i--;
	}
	i = len - 1;
	while (i >= 0)
	{
		ft_swap(&tab[0], &tab[i]);
		heapify(tab, i, 0);
		i--;
	}
}
