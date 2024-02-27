/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:57:44 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/27 12:57:45 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_little_sort(t_stack **a_stack)
{
	if (ft_min_arg3(*a_stack) == 0)
	{
		rra(a_stack);
		sa(a_stack);
	}
	else if (ft_max_arg3(*a_stack) == (*a_stack)->number)
	{
		ra(a_stack);
		if (ft_sorted_check(*a_stack) == 0)
			sa(a_stack);
	}
	else if (ft_max_arg3(*a_stack) == (ft_lstlast(*a_stack)->number))
	{
		sa(a_stack);
	}
	else
		rra(a_stack); 
}

void	ft_sort4(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;
	int		gap;

	gap = ft_gap(a_stack);
	temp = *a_stack;
	if (gap == 1)
		sa(a_stack);
	else if (gap == 2)
	{
		ra(a_stack);
		ra(a_stack);
	}
	else if (gap == 3)
		rra(a_stack);
	if (ft_sorted_check(*a_stack) == 0)
	{
		pb(a_stack, b_stack);
		ft_little_sort(a_stack);
		pa(a_stack, b_stack);
	}
}

void	ft_sort5(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;
	int		gap;

	gap = ft_gap(a_stack);
	temp = *a_stack;
	if (gap == 1)
		sa(a_stack);
	else if (gap == 2)
	{
		ra(a_stack);
		ra(a_stack);
	}
	else if (gap == 3)
	{
		rra(a_stack);
		rra(a_stack);
	}
	else if (gap == 4)
		rra(a_stack);
	if (ft_sorted_check(*a_stack) == 0)
	{
		pb(a_stack, b_stack);
		ft_sort4(a_stack, b_stack);
		pa(a_stack, b_stack);
	}
}

void	ft_sorting(t_stack **a_stack, t_stack **b_stack)
{
	if (ft_lstsize(*a_stack) == 2)
		sa(a_stack);
	else if (ft_lstsize(*a_stack) == 3)
		ft_little_sort(a_stack);
	else if (ft_lstsize(*a_stack) == 4)
		ft_sort4(a_stack, b_stack);
	else if (ft_lstsize(*a_stack) == 5)
		ft_sort5(a_stack, b_stack);
	else
		ft_radix_sort(a_stack, b_stack);
	if (ft_sorted_check(*a_stack) == 1)
	{
		ft_free_stack(a_stack);
		exit(SUCCESS);
	}
	else if (ft_sorted_check(*a_stack) == 0)
		ft_sorting(a_stack, b_stack);
}
