/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:27:38 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/26 12:13:12 by abolor-e         ###   ########.fr       */
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
	
	if (ac == 1)
		return (-1);
	a_stack = ft_extract(ac, av);
	b_stack = NULL;
	if (!a_stack)
	{
		ft_free_stack(&a_stack);
		ft_handle_error("Error\n");
	}
	ft_double_check(a_stack);
	if (ft_sorted_check(a_stack) == 1)
		exit(FAILURE);
	ft_sorting(&a_stack, &b_stack);
	//system("leaks push_swap");
	if (ft_sorted_check(a_stack) == 1)
	{
		//freestack(&a_stack);
		//freestack(&b_stack);
		exit(SUCCESS);
	}
	return (0);
}
