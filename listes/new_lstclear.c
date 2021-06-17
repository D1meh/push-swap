#include "../push_swap.h"

void	new_lstclear(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp);
}
