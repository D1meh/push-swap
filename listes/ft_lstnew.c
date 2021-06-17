#include "../push_swap.h"

t_list	*ft_lstnew(int n, int id)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l->nb = n;
	l->next = NULL;
	l->index = id;
	return (l);
}
