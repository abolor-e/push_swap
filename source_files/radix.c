/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:57:00 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/27 12:57:31 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_maxindex_bits(t_stack **a_stack)
{
	t_stack	*temp;
	int		max;
	int		bits;

	temp = *a_stack;
	max = temp->index;
	bits = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_radix_sort(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;
	int		i;
	int		a;
	int		list_size;
	int		iterbits;

	i = 0;
	temp = *a_stack;
	list_size = ft_lstsize(temp);
	iterbits = ft_maxindex_bits(a_stack);
	while (i < iterbits)
	{
		a = 0;
		while (a++ < list_size)
		{
			temp = *a_stack;
			if (((temp->index >> i) & 1) == 0)
				pb(a_stack, b_stack);
			else
				ra(a_stack);
		}
		while (ft_lstsize(*b_stack) != 0)
			pa(a_stack, b_stack);
		i++;
	}
}
