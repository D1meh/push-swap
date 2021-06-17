#include "../push_swap.h"

void	ft_rotate(t_list **lst, char c, int id)
{
	if (lst && *lst && (*lst)->next)
	{
		ft_lstadd_back(lst, ft_lstnew((*lst)->nb, id));
		new_lstclear(lst);
		if (c == 'a')
			write(1, "ra\n", 3);
		else if (c == 'b')
			write(1, "rb\n", 3);
	}
}
