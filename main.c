/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:27:38 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/15 15:37:27 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Checking argument count and pulling the data!

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->number = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
		(ft_lstlast(*lst))->next = new;
}

int	ft_atoi(const char *str)
{
	int				i;
	int				s;
	long long int	res;

	s = 1;
	i = 0;
	res = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= 58 || str[i] <= 47)
			ft_handle_error("Error\n");
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * s);
}

t_list	*ft_extract_ac2(char **av)
{
	t_list	*a_stack;
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
	ft_free(pull);
	free(pull);
	return (a_stack);
}

t_list	*ft_extract(int ac, char **av)
{
	t_list	*a_stack;
	
	a_stack = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		ft_handle_error("Error!\n");
	if (ac == 2)
		a_stack = ft_extract_ac2(av);
	else if (ac > 2)
		
		
		
}

int	main(int ac, char **av)
{
	t_list	*a_stack;

	a_stack = ft_extract(ac, av);
	if (!a_stack || )
	
}
