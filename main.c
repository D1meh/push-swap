#include "push_swap.h"

int	main(int ac, char **av)
{
	long int	*tab;
	t_list		*a;
	t_list		*b;
	int			len;

	check_args(ac, av);
	if (ac == 2)
		tab = tab_split(av[1], &len);
	else
		tab = fill_tab(ac, av, &len);
	if (is_sort_tab(tab, len))
	{
		free(tab);
		return (0);
	}
	a = ft_createlst(tab, len);
	b = ft_createlst(tab, 0);
	new(tab, len);
	push_swap(&a, &b, tab, len);
	free(tab);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
