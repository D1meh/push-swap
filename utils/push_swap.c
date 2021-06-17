#include "../push_swap.h"

static void	init(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (*a)
	{
		(*a)->index = 1;
		*a = (*a)->next;
	}
	*a = tmp;
}

int	find_higher(t_list *lst, int m)
{
	while (lst)
	{
		if (m <= lst->nb)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	find_lower(t_list *lst, int m)
{
	while (lst)
	{
		if (m > lst->nb)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	check_3(t_list **a)
{
	if (ft_lstsize(*a) != 3)
		return (0);
	if (is_sort_lst(*a))
		return (1);
	if ((*a)->nb > (*a)->next->nb && (*a)->nb < ft_lstlast(*a)->nb)
		ft_lstswap(a, 'a');
	else if ((*a)->nb > (*a)->next->nb && ft_lstlast(*a)->nb < (*a)->next->nb)
	{
		ft_lstswap(a, 'a');
		ft_r_rotate(a, 'a', (*a)->index);
	}
	else if ((*a)->nb > ft_lstlast(*a)->nb
		&& ft_lstlast(*a)->nb > (*a)->next->nb)
		ft_rotate(a, 'a', (*a)->index);
	else if ((*a)->nb < ft_lstlast(*a)->nb
		&& ft_lstlast(*a)->nb < (*a)->next->nb)
	{
		ft_lstswap(a, 'a');
		ft_rotate(a, 'a', (*a)->index);
	}
	else if ((*a)->nb < (*a)->next->nb && (*a)->nb > ft_lstlast(*a)->nb)
		ft_r_rotate(a, 'a', (*a)->index);
	return (1);
}

void	push_swap(t_list **a, t_list **b, long int *tab, int len)
{
	int	id;
	int	id_tmp;

	init(a);
	while (ft_lstsize(*a) > 2 && !is_sort_lst(*a))
		divide_a(a, b, tab, len);
	check_swap(a, 'a');
	clear(a);
	if (is_sort_lst(*a) && !ft_lstsize(*b))
		return ;
	id = (*b)->index;
	while (id)
	{
		if (check_done(a, b))
			return ;
		if (ft_sizeindex(*b, id) == 1)
			size1(a, b);
		id_tmp = id;
		if (ft_sizeindex(*b, id) > 1)
			id_tmp = size3more_utils(a, b, tab, len);
		id = new_id(id, id_tmp);
	}
}
