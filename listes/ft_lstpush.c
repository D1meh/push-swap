#include "../push_swap.h"

void	ft_push(t_list **a, t_list **b, char c, int id)
{
	if (b && a && *b)
	{
		ft_lstadd_front(a, ft_lstnew((*b)->nb, id));
		new_lstclear(b);
		if (c == 'a')
			write(1, "pa\n", 3);
		else if (c == 'b')
			write(1, "pb\n", 3);
	}
}
