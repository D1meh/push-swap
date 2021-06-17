#include "../push_swap.h"

long int	*fill_tab(int ac, char **av, int *l)
{
	int		 	i;
	long int	*tab;

	i = 0;
	tab = malloc(sizeof(long int) * (ac - 1));
	*l = ac - 1;
	if (!tab)
		error_return();
	while (i < ac - 1)
	{
		tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	check_int(tab, ac);
	return (tab);
}

long int	*tab_split(char *av, int *l)
{
	long int	*tab;
	int			i;
	int			len;
	char		**split;

	len = word_count(av, ' ');
	*l = len;
	tab = malloc(sizeof(long int) * len);
	if (!tab)
		error_return();
	split = ft_split(av, ' ');
	i = 0;
	while (i < len)
	{
		tab[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	check_int(tab, len);
	return (tab);
}
