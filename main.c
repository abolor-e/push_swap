/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:27:38 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/21 14:00:38 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack_list **a_stack)
{
	t_stack_list	*tmp;

	if (!(*a_stack))
		return ;
	while (*a_stack)
	{
		tmp = (*a_stack)->next;
		free(*a_stack);
		*a_stack = tmp;
	}
	*a_stack = NULL;
}

int	main(int ac, char **av)
{
	t_stack_list	*a_stack;

	a_stack = ft_extract(ac, av);
	if (!a_stack)
	{
		ft_free_stack(&a_stack);
		ft_handle_error("Error\n");
	}
	ft_double_check(a_stack); // Need a check for more than 1 same number in the stack!
	// Check if the numbers are sorted! Error when only 1 number entered!
	if (ft_sorted_check(a_stack) == 0)
		exit(FAILURE);// Check what this function is returning!
	// Can add the following examples in a new file! Called sorting!
	if (ft_lstsize(a_stack) == 2)
		sa(&a_stack);
	else if (ft_lstsize(a_stack) == 3)
	{
		ft_little_sort(&a_stack);
	}
	/*
	else (ft_lst_size(a_stack) > 3)
	{
		ft_turk_sorting();
	}
	*/
}
