#include "../push_swap.h"

void	ft_doubleswap(t_list **a, t_list **b)
{
	ft_lstswap(a, 'c');
	ft_lstswap(b, 'c');
	write(1, "ss\n", 3);
}

void	ft_lstswap(t_list **lst, char a)
{
	int	tmp;
	int	id_tmp;

	if (lst && *lst && (*lst)->next)
	{
		tmp = (*lst)->next->nb;
		id_tmp = (*lst)->next->index;
		(*lst)->next->nb = (*lst)->nb;
		(*lst)->next->index = (*lst)->index;
		(*lst)->nb = tmp;
		(*lst)->index = id_tmp;
		if (a == 'a')
			write(1, "sa\n", 3);
		else if (a == 'b')
			write(1, "sb\n", 3);
	}
}
