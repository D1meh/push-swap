#include "../push_swap.h"

void	size1(t_list **a, t_list **b)
{
	ft_push(a, b, 'a', (*b)->index);
	(*a)->index = 0;
}

void	size2(t_list **a, t_list **b)
{
	if ((*b)->nb < (*b)->next->nb)
		ft_lstswap(b, 'b');
	ft_push(a, b, 'a', (*b)->index);
	(*a)->index = 0;
	ft_push(a, b, 'a', (*b)->index);
	(*a)->index = 0;
}

void	size3(t_list **a, t_list **b, int id_tmp)
{
	while (ft_sizeindex(*b, id_tmp))
	{
		if ((*b)->next && (*b)->index == (*b)->next->index
			&& (*b)->nb < (*b)->next->nb)
			ft_lstswap(b, 'b');
		ft_push(a, b, 'a', (*b)->index);
		if ((*a)->nb > (*a)->next->nb)
			ft_lstswap(a, 'a');
		(*a)->next->index = 0;
		(*a)->index = 0;
	}
}

void	size3more(t_list **a, t_list **b, int m, int id_tmp)
{
	while (ft_sizeindex(*b, id_tmp))
	{
		if (ft_sizeindex(*b, 1) == ft_lstsize(*b) && !find_higher(*b, m))
			break ;
		if ((*b)->nb < m)
			ft_rotate(b, 'b', (*b)->index);
		else
		{
			(*b)->index++;
			ft_push(a, b, 'a', (*b)->index);
		}
	}
}

int	size3more_utils(t_list **a, t_list **b, long int *tab, int len)
{
	int	id_tmp;
	int	m;

	id_tmp = (*b)->index;
	while (ft_sizeindex(*b, id_tmp) > 3)
	{
		m = med(tab, len - ft_lstsize(*a) - ft_sizeindex(*b, id_tmp),
				ft_sizeindex(*b, id_tmp));
		size3more(a, b, m, id_tmp);
		recover2(b, id_tmp);
		if (is_sort_lst(*a))
		{
			clear(a);
			continue ;
		}
		recover3(a, b, id_tmp);
		id_tmp++;
	}
	if (ft_sizeindex(*b, id_tmp) == 2)
		size2(a, b);
	else if (ft_sizeindex(*b, id_tmp) == 3)
		size3(a, b, id_tmp);
	return (id_tmp);
}
