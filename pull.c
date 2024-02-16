#include "push_swap.h"

// Checking argument count and pulling the data!

t_stack_list	*ft_lstnew(int content)
{
	t_stack_list	*new;

	new = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (!new)
		return (NULL);
	new->number = content;
	new->next = NULL;
	return (new);
}

t_stack_list	*ft_lstlast(t_stack_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack_list **lst, t_stack_list *new)
{
	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
		(ft_lstlast(*lst))->next = new;
}

t_stack_list	*ft_extract_ac2(char **av)
{
	t_stack_list	*a_stack;
	char	**pull;
	int		i;
	int		a;
	
	a_stack = NULL;
	i = 0;
	pull = ft_split(av[1], ' ');
	if (!pull)
		ft_handle_error("Error\n"); // Maybe should just check in the main.c if a_stack is null!
	while (pull[i])
	{
		a = ft_atoi(pull[i]);// Checks also if the string is a number!
		ft_lstadd_back(&a_stack, ft_lstnew(a));
		i++;
	}
	ft_free_(pull);
	free(pull);
	return (a_stack);
}

t_stack_list	*ft_extract(int ac, char **av)
{
	t_stack_list	*a_stack;
	int		i;
	int		a;
	
	i = 1;
	a = 0;
	a_stack = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		ft_handle_error("Error\n");
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
	return (a_stack);
}