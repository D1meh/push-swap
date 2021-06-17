#include "../push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*elt;

	while (*lst)
	{
		elt = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = elt;
	}
}
