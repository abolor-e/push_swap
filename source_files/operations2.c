/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:55:22 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/27 12:55:58 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_push(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;
	t_stack	*from;
	t_stack	*to;

	if (ft_lstsize(*b_stack) == 0)
		return (-1);
	from = *b_stack;
	to = *a_stack;
	temp = *b_stack;
	from = from->next;
	*b_stack = from;
	if (!to)
	{
		to = temp;
		to->next = NULL;
		*a_stack = to;
	}
	else
	{
		temp->next = to;
		*a_stack = temp;
	}
	return (0);
}

void	pb(t_stack **a_stack, t_stack **b_stack)
{
	if (ft_push(b_stack, a_stack) == -1)
		ft_handle_error("Error\n");
	write(1, "pb\n", 3);
}

void	pa(t_stack **a_stack, t_stack **b_stack)
{
	if (ft_push(a_stack, b_stack) == -1)
		ft_handle_error("Error\n");
	write(1, "pa\n", 3);
}
