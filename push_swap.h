#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list {
	int				nb;
	int				index;	
	struct s_list	*next;
}	t_list;

typedef struct s_moves {
	char	*mv;
	int		len;
}	t_moves;

void		check_args(int ac, char **av);
void		error_return(void);
void		check_int(long int *tab, int ac);

long int	*fill_tab(int ac, char **av, int *l);
long int	*tab_split(char *av, int *l);
long		ft_atoi(const char *str);
char		**ft_split(char *str, char c);
int			word_count(char *s, char c);

void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst);
int			ft_lstsize(t_list *a);
void		ft_lstdelone(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int n, int id);
void		new_lstclear(t_list **lst);
t_list		*ft_createlst(long int *tab, int ac);
t_list		*lastlast(t_list *lst);

void		ft_push(t_list **a, t_list **b, char c, int id);
void		ft_lstswap(t_list **lst, char a);
//void		ft_doubleswap(t_list **a, t_list **b);
void		ft_r_rotate(t_list **lst, char c, int id);
void		ft_rotate(t_list **lst, char c, int id);
//void		double_rotate(t_list **a, t_list **b);
//void		double_R_rotate(t_list **a, t_list **b);

void		ft_quicksort(long int *tab, int low, int high);
void		new(long int *tab, int len);
int			is_sort_tab(long int *tab, int len);
int			is_sort_lst(t_list *lst);
int			is_unsort_lst(t_list *lst);
int			ft_isdigit(char c);

void		push_swap(t_list **a, t_list **b, long *tab, int len);
int			med(long int *tab, int debut, int len);
void		clear(t_list **a);
int			check_3(t_list **a);
int			ft_sizeindex(t_list *lst, int index);
int			find_higher(t_list *lst, int m);
int			find_lower(t_list *lst, int m);
void		divide_a(t_list **a, t_list **b, long int *tab, int len);
int			check_done(t_list **a, t_list **b);
void		size1(t_list **a, t_list **b);
void		size2(t_list **a, t_list **b);
void		size3(t_list **a, t_list **b, int id_tmp);
void		size3more(t_list **a, t_list **b, int m, int id_tmp);
int			size3more_utils(t_list **a, t_list **b, long int *tab, int len);
void		recover2(t_list **b, int id_tmp);
void		recover3(t_list **a, t_list **b, int id_tmp);
int			new_id(int id, int id_tmp);
void		check_swap(t_list **lst, char c);

#endif
