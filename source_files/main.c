/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:27:38 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/25 20:41:35 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_stack **a_stack)
{
	t_stack	*tmp;

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

void	freestack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	
	a_stack = ft_extract(ac, av);
	b_stack = NULL;
	if (ac == 1)
		return (-1);
	if (!a_stack)
	{
		ft_free_stack(&a_stack);
		ft_handle_error("Error\n");
	}
	ft_double_check(a_stack); // Need a check for more than 1 same number in the stack!
	// Check if the numbers are sorted! Error when only 1 number entered!
	if (ft_sorted_check(a_stack) == 1)
		exit(FAILURE);// Check what this function is returning!
	// Can add the following examples in a new file! Called sorting!
	ft_sorting(&a_stack, &b_stack);
	if (ft_sorted_check(a_stack) == 1)
	{
		//freestack(&a_stack);
		//freestack(&b_stack);
		exit(SUCCESS);
	}
	return (0);
}
