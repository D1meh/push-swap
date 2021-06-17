#include "../push_swap.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst)
			new->next = *alst;
		*alst = new;
	}
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*elt;

	if (!alst)
		return ;
	if (*alst)
	{
		elt = ft_lstlast(*alst);
		elt->next = new;
	}
	else
		*alst = new;
}
