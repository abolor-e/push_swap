/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:54:47 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/27 12:55:11 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **a_stack)
{
	t_stack	*temp;

	if (!*a_stack || !(*a_stack)->next)
		return ;
	temp = *a_stack;
	*a_stack = (*a_stack)->next;
	temp->next = (*a_stack)->next;
	(*a_stack)->next = temp;
	write(1, "sa\n", 3);
}

void	rra(t_stack **a_stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *a_stack;
	while ((*a_stack)->next)
	{
		i++;
		*a_stack = (*a_stack)->next;
	}
	(*a_stack)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	write(1, "rra\n", 4);
}

void	ra(t_stack **a_stack)
{
	t_stack	*temp;

	temp = *a_stack;
	*a_stack = ft_lstlast(*a_stack);
	(*a_stack)->next = temp;
	*a_stack = temp->next;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b_stack)
{
	t_stack	*temp;

	temp = *b_stack;
	*b_stack = ft_lstlast(*b_stack);
	(*b_stack)->next = temp;
	*b_stack = temp->next;
	temp->next = NULL;
	write(1, "rb\n", 3);
}
