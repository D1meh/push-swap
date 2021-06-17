#include "../push_swap.h"

void	ft_lstdelone(t_list *lst)
{
	if (lst)
		free(lst);
}
