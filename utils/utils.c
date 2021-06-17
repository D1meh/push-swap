#include "../push_swap.h"

int	med(long int *tab, int debut, int len)
{
	return (tab[debut + len / 2]);
}

void	clear(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (*a)
	{
		(*a)->index = 0;
		*a = (*a)->next;
	}
	*a = tmp;
}

int	ft_sizeindex(t_list *lst, int index)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->index != index)
			break ;
		i++;
		lst = lst->next;
	}
	return (i);
}

void	recover(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (ft_lstlast(*a)->index > (*a)->index)
	{
		(*a)->index = ft_lstlast(*a)->index;
		*a = (*a)->next;
	}
	*a = tmp;
}

void	divide_a(t_list **a, t_list **b, long int *tab, int len)
{
	int	m;
	int	g;
	int	i;

	if (check_3(a))
		return ;
	m = med(tab, len - ft_lstsize(*a), ft_lstsize(*a));
	g = ft_lstsize(*a);
	i = 0;
	while (i < g && find_lower(*a, m))
	{
		if ((*a)->nb < m)
			ft_push(b, a, 'b', (*a)->index);
		else
		{
			(*a)->index++;
			ft_rotate(a, 'a', (*a)->index);
		}
		i++;
	}
	recover(a);
}
