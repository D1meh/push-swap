#include "../push_swap.h"

void	check_swap(t_list **lst, char c)
{
	if (*lst && (*lst)->next && (*lst)->nb > (*lst)->next->nb)
		ft_lstswap(lst, c);
}

int	check_done(t_list **a, t_list **b)
{
	if (is_unsort_lst(*b) && is_sort_lst(*a))
	{
		while (*b)
			ft_push(a, b, 'a', (*b)->index);
		return (1);
	}
	return (0);
}

int	new_id(int id, int id_tmp)
{
	if (id_tmp > id)
		id = id_tmp;
	else
		id--;
	return (id);
}

void	recover2(t_list **b, int id_tmp)
{
	while (ft_lstlast(*b)->index == id_tmp && id_tmp != 1)
		ft_r_rotate(b, 'b', ft_lstlast(*b)->index);
}

void	recover3(t_list **a, t_list **b, int id_tmp)
{
	while ((*a)->index == id_tmp + 1)
		ft_push(b, a, 'b', (*a)->index);
}
