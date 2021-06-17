#include "../push_swap.h"

int	is_sort_tab(long int *tab, int len)
{
	int	n;
	int	max;

	n = 1;
	max = tab[0];
	while (n < len)
	{
		if (max < tab[n])
			max = tab[n];
		else
			return (0);
		n++;
	}
	return (1);
}

int	is_sort_lst(t_list *lst)
{
	int	n;

	n = lst->nb;
	lst = lst->next;
	while (lst)
	{
		if (lst->nb > n)
		{
			n = lst->nb;
			lst = lst->next;
		}
		else
			return (0);
	}
	return (1);
}

int	is_unsort_lst(t_list *lst)
{
	int	n;

	n = lst->nb;
	lst = lst->next;
	while (lst)
	{
		if (lst->nb < n)
		{
			n = lst->nb;
			lst = lst->next;
		}
		else
			return (0);
	}
	return (1);
}	
