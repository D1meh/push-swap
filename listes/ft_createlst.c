#include "../push_swap.h"

t_list	*ft_createlst(long int *tab, int ac)
{
	t_list	*new;
	t_list	*elt;
	int		i;

	new = NULL;
	i = 0;
	while (i < ac)
	{
		elt = ft_lstnew(tab[i], 0);
		if (!elt)
		{
			ft_lstclear(&new);
			error_return();
		}
		ft_lstadd_back(&new, elt);
		i++;
	}
	return (new);
}
