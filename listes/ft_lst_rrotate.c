#include "../push_swap.h"

t_list	*lastlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_r_rotate(t_list **lst, char c, int id)
{
	t_list	*last;
	t_list	*tmp;

	if (lst && *lst && (*lst)->next)
	{
		last = ft_lstlast(*lst);
		tmp = lastlast(*lst);
		tmp->next = NULL;
		tmp = ft_lstnew(last->nb, id);
		ft_lstadd_front(lst, tmp);
		ft_lstdelone(last);
		if (c == 'a')
			write(1, "rra\n", 4);
		else if (c == 'b')
			write(1, "rrb\n", 4);
	}
}
