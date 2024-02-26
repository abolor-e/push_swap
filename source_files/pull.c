#include "../push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new || (!lst && !new))
		return ;
	if (!(*lst))
		*lst = new;
	else
		(ft_lstlast(*lst))->next = new;
}

t_stack	*ft_extract_ac2(char **av)
{
	t_stack	*a_stack;
	char	**pull;
	int		i;
	int		a;
	
	a_stack = NULL;
	i = 0;
	pull = ft_split(av[1], ' ');
	if (!pull)
		ft_handle_error("Error\n"); //Maybe free?!
	while (pull[i])
	{
		a = ft_atoi(pull[i]);
		ft_lstadd_back(&a_stack, ft_lstnew(a));
		i++;
	}
	ft_free_(pull);
	free(pull);
	return (a_stack);
}

t_stack	*ft_extract(int ac, char **av)
{
	t_stack	*a_stack;
	int		i;
	int		a;
	
	i = 1;
	a = 0;
	a_stack = NULL;
	if (ac == 2 && !av[1][0])
		ft_handle_error("Error\n");
	ft_check_av(av);
	if (ac == 2)
		a_stack = ft_extract_ac2(av);
	else if (ac > 2)
	{
		while (i < ac)
		{
			a = ft_atoi(av[i]);
			ft_lstadd_back(&a_stack, ft_lstnew(a));
			i++;
		}
	}
	ft_sort_index(&a_stack);
	return (a_stack);
}
